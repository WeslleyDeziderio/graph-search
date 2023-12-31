#include "../../include/utils/DFS.hpp"

DFS::DFS(int params, char* instance) : dataDfs(params, instance) {
    std::cout << "Reading " << dataDfs.getInstanceName() << std::endl;
    dataDfs.readData();

    const int numVertices = dataDfs.getNumVertices();
    const int adjustedSize = numVertices+ADJUST_ZERO_INDEX;

    this->coloredEdges.resize(adjustedSize, std::vector<std::string>(adjustedSize, null));
    this->graphVertex.resize(adjustedSize);

    setGlobalTimer(0);
    initializeParams();
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

    auto current = currentVertex.getVertex();
    this->graphVertex[current].setEntryDepth(getGlobalTimer());
    
    std::vector<int> neighborhood = dataDfs.getNeighborhoodMatrix(current);
    for (auto vertex : neighborhood) {
        Vertex& neighborVertex = this->graphVertex[vertex];

        if (neighborVertex.getEntryDepth() == 0) {
            this->coloredEdges[current][vertex] = blue;
            this->coloredEdges[vertex][current] = blue;
            neighborVertex.setAncestral(current);
            recursiveDFS(neighborVertex);
        }
        else if (neighborVertex.getExitDepth() == 0 && vertex != currentVertex.getAncestral()) {
            this->coloredEdges[current][vertex] = red;
            this->coloredEdges[vertex][current] = red;
        }
    }

    incrementGlobalTimer();
    this->graphVertex[current].setExitDepth(getGlobalTimer());
}

void DFS::initializeParams() {
  for (int i = 1; i <= dataDfs.getNumVertices(); ++i) {
        this->graphVertex[i].setVertex(i);
        this->graphVertex[i].setEntryDepth(0);
        this->graphVertex[i].setExitDepth(0);
        this->graphVertex[i].setAncestral(-1);
    }
}

void DFS::showDepths() {
    auto numVertices = dataDfs.getNumVertices();

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

void DFS::generateOutputFile() {
    std::string path = "instances/myOutput/graph_dfs.gdf";
    std::ofstream file(path);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the output file." << std::endl;
        return;
    }

    file << "nodedef>name VARCHAR,label VARCHAR" << std::endl;

    for (int i = 1; i <= dataDfs.getNumVertices(); ++i) {
        file << i << "," << i << std::endl;
    }

    file << "edgedef>node1 VARCHAR,node2 VARCHAR,directed BOOLEAN,color VARCHAR" << std::endl;

    for (int i = 0; i < this->coloredEdges.size(); ++i) {
        for (int j = i; j < this->coloredEdges[i].size(); ++j) {
            if (this->coloredEdges[i][j].length() > 0) {
                file << i << "," << j << ",false," << this->coloredEdges[i][j] << std::endl;
            }
        }
    }

    file.close();

     if (file.fail()) {
        std::cerr << "Error: Failed to write data to the output file." << std::endl;
    } else {
        std::cout << "\nFile generated successfully: " << path << std::endl;
    }
}
