#include "../../include/utils/BFS.hpp"

BFS::BFS(int params, char* instance) : dataBfs(params, instance) {
    std::cout << "Reading " << dataBfs.getInstanceName() << std::endl;
    dataBfs.readData();

    const int numVertices = dataBfs.getNumVertices();
    const int adjustedSize = numVertices+ADJUST_ZERO_INDEX;

    this->coloredEdges.resize(adjustedSize, std::vector<std::string>(adjustedSize, null));
    this->graphVertex.resize(adjustedSize);
    
    setGlobalTimer(0);
    initializeParams();
}

void BFS::setGlobalTimer(int globalTimer) {
    this->globalTimer = globalTimer;
}

int BFS::getGlobalTimer() {
    return globalTimer;
}

void BFS::incrementGlobalTimer() {
    this->globalTimer++;
}

void BFS::interactiveBfs(Vertex vertex) {
    auxQueue.push_back(vertex);
    incrementGlobalTimer();
    this->graphVertex[vertex.getVertex()].setSearchIndex(getGlobalTimer());
    this->graphVertex[vertex.getVertex()].setLevel(0);

    while (!auxQueue.empty()) {
        Vertex& current = auxQueue.front();
        auxQueue.pop_front();
        std::vector<int> neighborhood = dataBfs.getNeighborhoodMatrix(current.getVertex());

        for (auto neighbor : neighborhood) {
            if (this->graphVertex[neighbor].getSearchIndex() == 0) {
                this->coloredEdges[current.getVertex()][neighbor] = blue;
                this->coloredEdges[neighbor][current.getVertex()] = blue;
                incrementGlobalTimer();
                this->graphVertex[neighbor].setAncestral(current.getVertex());   
                this->graphVertex[neighbor].setSearchIndex(getGlobalTimer());
                this->graphVertex[neighbor].setLevel(current.getLevel()+1);
                auxQueue.push_back(this->graphVertex[neighbor]);
            }
            else if (this->graphVertex[neighbor].getLevel() == current.getLevel()) {
                if (this->graphVertex[neighbor].getAncestral() == current.getAncestral()) {
                    this->coloredEdges[current.getVertex()][neighbor] = red;
                    this->coloredEdges[neighbor][current.getVertex()] = red;
                } else {
                    this->coloredEdges[current.getVertex()][neighbor] = yellow;
                    this->coloredEdges[neighbor][current.getVertex()] = yellow;
                }
            }
            else if (this->graphVertex[neighbor].getLevel() == current.getLevel()+1) {
                this->coloredEdges[current.getVertex()][neighbor] = green;
                this->coloredEdges[neighbor][current.getVertex()] = green;

            }
         }
    }
}

void BFS::initializeParams() {
    for (int i = 1; i <= dataBfs.getNumVertices(); ++i) {
        this->graphVertex[i].setVertex(i);
        this->graphVertex[i].setSearchIndex(0);
        this->graphVertex[i].setAncestral(-1);
        this->graphVertex[i].setLevel(-1);
    }
}

void BFS::calculateMetrics() {
        int numVertices = dataBfs.getNumVertices();
        int ecc = 0;
        int radius = MAX;
        int diameter = MIN;
        double accumulator = 0;
        double count = numVertices*(numVertices-1);
        std::vector<int> eccVec;

        for (int i = 1; i <= numVertices; ++i) {
            setGlobalTimer(0);
            initializeParams();
            interactiveBfs(this->graphVertex[i]);
            int eccMaxAux = 0;

            for (int j = 1; j <= numVertices; ++j) {
                accumulator += this->graphVertex[j].getLevel();

                if (eccMaxAux < this->graphVertex[j].getLevel()) {
                    eccMaxAux = this->graphVertex[j].getLevel();
                } 
            }

            eccVec.push_back(eccMaxAux);

            if (eccMaxAux > ecc) {
                ecc = eccMaxAux;
            }

            std::cout << "Eccentricity of vertex " << i << ": " << eccMaxAux << std::endl;

        }

        for (auto k : eccVec) {
            if (eccVec[k] < radius) {
                radius = eccVec[k];
            }

            if (eccVec[k] > diameter) {
                diameter = eccVec[k];
            }
        }

        std::cout << "\nEccentricity of the graph: " << ecc << std::endl;
        std::cout << "Radius of the graph: " << radius << std::endl;
        std::cout << "Diameter of the graph: " << diameter << std::endl;
        std::cout << "\n\nAverage distance: " << accumulator/count << std::endl;
}

void BFS::showLevelSearchIndex() {
    int numVertices = dataBfs.getNumVertices();

    std::cout << "L(v): ";
    for (int i = 1; i <= numVertices; ++i) {
        std::cout << this->graphVertex[i].getSearchIndex() << ", ";
    }

    std::cout << "\nLevel: ";
    for (int i = 1; i <= numVertices; ++i) {
        std::cout << this->graphVertex[i].getLevel() << ", ";
    }

    std::cout << "\n\n";
}

void BFS::generateOutputFile() {
    std::string path = "instances/myOutput/graph_bfs.gdf";
    std::ofstream file(path, std::ofstream::trunc);

    if (!file.is_open()) {
        std::cerr << "Error: Unable to open the output file." << std::endl;
        return;
    }

    file << "nodedef>name VARCHAR,label VARCHAR" << std::endl;

    for (int i = 1; i <= dataBfs.getNumVertices(); ++i) {
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