#include "../../include/utils/BFS.hpp"

BFS::BFS(int params, char* instance) : dataBfs(params, instance) {
    std::cout << "Reading " << dataBfs.getInstanceName() << std::endl;
    dataBfs.readData();
    dataBfs.printAdjacencyMatrix();
    dataBfs.printAdjacencyList();

    this->coloredEdges.resize(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER, std::vector<std::string>(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER));
    this->graphVertex.resize(this->dataBfs.getNumVertices()+ZERO_INDEX_REMOVER);
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
            if (this->graphVertex[neighbor].getSearchIndex() == 0) {
                this->coloredEdges[current.getVertex()][neighbor] = BLUE;
                this->coloredEdges[neighbor][current.getVertex()] = BLUE;
                this->graphVertex[neighbor].setAncestral(current.getVertex());   
                this->graphVertex[neighbor].setLevel(current.getLevel()+1);
                incrementGlobalTimer();
                this->graphVertex[neighbor].setSearchIndex(getGlobalTimer());
                auxQueue.push(this->graphVertex[neighbor]);
            }
            else if (neighborVertex.getLevel() == current.getLevel()) {
                if (neighborVertex.getAncestral() == current.getAncestral()) {
                    this->coloredEdges[current.getVertex()][neighbor] = RED;
                    this->coloredEdges[neighbor][current.getVertex()] = RED;
                } else {
                    this->coloredEdges[current.getVertex()][neighbor] = YELLOW;
                    this->coloredEdges[neighbor][current.getVertex()] = YELLOW;
                }
            }
            else if (neighborVertex.getLevel() == current.getLevel()) {
                this->coloredEdges[current.getVertex()][neighbor] = GREEN;
                this->coloredEdges[neighbor][current.getVertex()] = GREEN;

            }
         }
    }
}

void BFS::initializeParams() {
    for (int i = 1; i <= dataBfs.getNumVertices(); ++i) {
        this->graphVertex[i].setVertex(i);
        this->graphVertex[i].setSearchIndex(0);
        this->graphVertex[i].setAncestral(-1);
        this->graphVertex[i].setLevel(0);
    }
}

void BFS::calculateMetrics() {
        int numVertices = dataBfs.getNumVertices();
        int ecc = 0;
        int radius = MAX;
        int diameter = MIN;
        double acumulator = 0;
        double count = numVertices*(numVertices-1);
        std::vector<int> eccVec;
        setGlobalTimer(0);

        for (int i = 1; i <= numVertices; ++i) {
            initializeParams();
            interactiveBfs(this->graphVertex[i]);
            int eccMaxAux = 0;

            for (int j = 1; j <= numVertices; ++j) {
                acumulator += this->graphVertex[j].getLevel();

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
        std::cout << "\n\nAverage distance: " << acumulator/count << std::endl;
}

void BFS::showBreadth() {
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