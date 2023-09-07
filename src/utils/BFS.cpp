#include "../../include/utils/BFS.hpp"

BFS::BFS(int params, char* instance) : dataBfs(params, instance) {
    std::cout << "Reading " << dataBfs.getInstanceName() << std::endl;
    dataBfs.readData();
    dataBfs.printAdjacencyMatrix();
    dataBfs.printAdjacencyList();

    this->coloredEdges.resize(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER, std::vector<char>(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER));
    this->graphVertex.resize(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER);
    setGlobalTimer(0);

    for (int i = 1; i <= dataBfs.getNumVertices(); ++i) {
        this->graphVertex[i].setVertex(i);
        this->graphVertex[i].setSearchIndex(0);
        this->graphVertex[i].setAncestral(-1);
        this->graphVertex[i].setLevel(0);
    }
}

void BFS::setGlobalTimer(int globalTimer) {
    this->globalTimer = globalTimer;
}

int BFS::getGlobalTimer() {
    return globalTimer;
}

void BFS::incrementGlobalTimer() {
    this->globalTimer += 1;
}

void BFS::interactiveBfs(Vertex vertex) {
    auxQueue.push(vertex);
    incrementGlobalTimer();
    this->graphVertex[vertex.getVertex()].setSearchIndex(getGlobalTimer());

    while (!auxQueue.empty()) {
        Vertex current = auxQueue.front();
        Vertex& neighborVertex = this->graphVertex[current.getVertex()];
        auxQueue.pop();
        int currentIndex = vertex.getSearchIndex();
        std::vector<int> neighborhood(dataBfs.getNeighborhoodMatrix(current.getVertex()));

        for (int neighbor : neighborhood) {
            if (neighborVertex.getSearchIndex() == 0) {
                this->coloredEdges[current.getVertex()][neighbor] = BLUE;
                neighborVertex.setAncestral(current.getVertex());   
                neighborVertex.setLevel(current.getLevel()+1);
                incrementGlobalTimer();
                neighborVertex.setSearchIndex(getGlobalTimer());
                auxQueue.push(neighborVertex);
            }
            else if (neighborVertex.getLevel() == current.getLevel()) {
                if (neighborVertex.getAncestral() == current.getAncestral()) {
                    this->coloredEdges[current.getVertex()][neighbor] = RED;
                } else {
                    this->coloredEdges[current.getVertex()][neighbor] = YELLOW;
                }
            }
            else if (neighborVertex.getLevel() == current.getLevel()) {
                this->coloredEdges[current.getVertex()][neighbor] = GREEN;
            }
         }
    }
}

void BFS::showBreadth() {
    int numVertices = dataBfs.getNumVertices();

    std::cout << "L(v): ";
    for (int i = 1; i <= numVertices; ++i) {
        std::cout << this->graphVertex[i].getLevel() << ", ";
    }
}