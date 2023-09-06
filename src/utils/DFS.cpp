#include "../../include/utils/DFS.hpp"

DFS::DFS(int params, char* instance) : dataDfs(params, instance) {
    std::cout << "Reading " << dataDfs.getInstanceName() << std::endl;
    dataDfs.readData();
    dataDfs.printAdjacencyMatrix();
    dataDfs.printAdjacencyList();
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