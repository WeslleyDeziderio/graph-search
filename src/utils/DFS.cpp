#include "../../include/utils/DFS.hpp"

DFS::DFS(int params, char* instance) : dataDfs(params, instance) {
    std::cout << "Reading " << dataDfs.getInstanceName() << "..." << std::endl;
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
    const std::list<std::list<int>>& neighbors = dataDfs.getAdjacencyList();
    incrementGlobalTimer();

    this->graphVertex[currentVertex.getVertex()].setEntryDepth(getGlobalTimer());
    
}