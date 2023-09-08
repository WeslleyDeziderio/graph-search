#include "../../include/utils/DFS.hpp"

DFS::DFS(int params, char* instance) : dataDfs(params, instance) {
    std::cout << "Reading " << dataDfs.getInstanceName() << std::endl;
    dataDfs.readData();
    dataDfs.printAdjacencyMatrix();
    dataDfs.printAdjacencyList();

    this->coloredEdges.resize(this->dataDfs.getNumVertices()+ZERO_INDEX_REMOVER, std::vector<std::string>(this->dataDfs.getNumVertices()+ZERO_INDEX_REMOVER));
    this->graphVertex.resize(this->dataDfs.getNumVertices()+ZERO_INDEX_REMOVER);
    setGlobalTimer(0);

    for (int i = 1; i <= dataDfs.getNumVertices(); ++i) {
        this->graphVertex[i].setVertex(i);
        this->graphVertex[i].setEntryDepth(0);
        this->graphVertex[i].setAncestral(0);
    }
}

void DFS::setGlobalTimer(int globalTimer) {
    this->globalTimer = globalTimer;
}

int DFS::getGlobalTimer() {
    return globalTimer;
}

void DFS::incrementGlobalTimer() {
    this->globalTimer += 1; 
}

void DFS::recursiveDFS(Vertex currentVertex) {
    incrementGlobalTimer();

    int current = currentVertex.getVertex();
    this->graphVertex[current].setEntryDepth(getGlobalTimer());
    
    std::vector<int> neighborhood(dataDfs.getNeighborhoodMatrix(current));
    for (int neighbor : neighborhood) {
        Vertex& neighborVertex = this->graphVertex[neighbor];

        if (neighborVertex.getEntryDepth() == 0) {
            this->coloredEdges[current][neighbor] = BLUE;
            neighborVertex.setAncestral(current);
            recursiveDFS(neighborVertex);
        }
        else if (neighborVertex.getExitDepth() == 0 && neighbor != currentVertex.getAncestral()) {
            this->coloredEdges[current][neighbor] = RED;
        }
    }

    incrementGlobalTimer();
    this->graphVertex[current].setExitDepth(getGlobalTimer());
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