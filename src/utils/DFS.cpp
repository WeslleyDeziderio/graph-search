#include "../../include/utils/DFS.hpp"

DFS::DFS(int params, char* instance) : dataDfs(params, instance) {
    std::cout << "Reading " << dataDfs.getInstanceName() << std::endl;
    dataDfs.readData();
    dataDfs.printAdjacencyMatrix();
    dataDfs.printAdjacencyList();

    const int numVertices = dataDfs.getNumVertices();
    const int adjustedSize = numVertices + ADJUST_ZERO_INDEX;

    this->coloredEdges.resize(numVertices+adjustedSize, std::vector<std::string>(numVertices+adjustedSize));
    this->graphVertex.resize(numVertices+adjustedSize);

    initializeParams();
    setGlobalTimer(0);
}

void DFS::setGlobalTimer(int globalTimer) {
    this->globalTimer = globalTimer;
}

int DFS::getGlobalTimer() {
    return globalTimer;
}

void DFS::incrementGlobalTimer() {
    this->globalTimer++; 
}

void DFS::recursiveDFS(Vertex currentVertex) {
    incrementGlobalTimer();

    int current = currentVertex.getVertex();
    this->graphVertex[current].setEntryDepth(getGlobalTimer());
    
    std::vector<int> neighborhood = dataDfs.getNeighborhoodMatrix(current);
    for (int neighbor : neighborhood) {
        Vertex& neighborVertex = this->graphVertex[neighbor];

        if (neighborVertex.getEntryDepth() == 0) {
            this->coloredEdges[current][neighbor] = blue;
            this->coloredEdges[neighbor][current] = blue;
            neighborVertex.setAncestral(current);
            recursiveDFS(neighborVertex);
        }
        else if (neighborVertex.getExitDepth() == 0 && neighbor != currentVertex.getAncestral()) {
            this->coloredEdges[current][neighbor] = red;
            this->coloredEdges[neighbor][current] = red;
        }
    }

    incrementGlobalTimer();
    this->graphVertex[current].setExitDepth(getGlobalTimer());
}

void DFS::initializeParams() {
  for (int i = 1; i <= dataDfs.getNumVertices(); ++i) {
        this->graphVertex[i].setVertex(i);
        this->graphVertex[i].setEntryDepth(0);
        this->graphVertex[i].setAncestral(0);
    }
}

void DFS::showDepths() {
    int numVertices = dataDfs.getNumVertices();

    std::cout << "\nP(E): ";
    for (int i = 1; i <= numVertices; ++i) {
        std::cout << this->graphVertex[i].getEntryDepth() << ", ";
    }

    std::cout << "\n";
    std::cout << "P(S): ";
    for (int i = 1; i <= numVertices; ++i) {
        std::cout << this->graphVertex[i].getExitDepth() << ", ";
    }
}