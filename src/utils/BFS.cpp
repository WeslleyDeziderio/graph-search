#include "../../include/utils/BFS.hpp"

BFS::BFS(int params, char* instance) : dataBfs(params, instance) {
    std::cout << "Reading " << dataBfs.getInstanceName() << std::endl;
    dataBfs.readData();
    dataBfs.printAdjacencyMatrix();
    dataBfs.printAdjacencyList();

    this->coloredEdges.resize(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER, std::vector<char>(this->dataBfs.getNumVertices()));
    this->graphVertex.resize(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER);

    for (int i = 1; i < dataBfs.getNumVertices(); ++i) {
        this->graphVertex[i].setVertex(1);
        this->graphVertex[i].setSearchIndex(0);
        this->graphVertex[i].setAncestral(NULL);
    }

}