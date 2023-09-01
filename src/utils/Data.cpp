#include "../../include/utils/Data.hpp"

Data::Data(int params, char* instance) {
    if (params != 2) {
        std::cerr << "ERROR: Missing parameters!" << std::endl;
        std::cout << "Usage: ./concepts <Instance>" << std::endl;
        exit(1);
    }

    instanceName = instance;
    numVertices = 0;
}

void Data::readData() {
	std::ifstream inputData(instanceName, std::ios::in);

	if (!inputData) {
		std::cerr << "ERROR: File not found!" << std::endl;
        exit(1);
	}

    inputData >> numVertices;
    std::cout << "Number of vertices: " << numVertices << std::endl;
    adjacencyMatrix.assign(numVertices, std::vector<int>(numVertices, 0));

    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            inputData >> this->adjacencyMatrix[i][j];
        }
    }

    inputData.close();
    std::cout << "Data read successfully! \n" << std::endl;
}

std::string Data::getInstanceName() {
    return instanceName;
}

void Data::printAdjacencyMatrix() {  
    std::cout << "Adjacency Matrix: \n";
    for (int i = 0; i < this->numVertices; ++i) {
        for (int j = 0; j < this->numVertices; ++j) {
            std::cout << this->adjacencyMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";
}

std::list<std::list<int>> Data::getAdjacencyList() {
    for (int i = 0; i < numVertices; ++i) {
        std::list<int> neighbors;
        for (int j = 0; j < numVertices; ++j) {
            if (adjacencyMatrix[i][j] == 1) {
                neighbors.push_back(j+1);
            }
        }

        adjacencyList.push_back(neighbors);
    }

    return adjacencyList;
}

void Data::printAdjacencyList() {
    adjacencyList = getAdjacencyList();
    int vertex = 0;
    
    std::cout << "Adjacency List: \n";
    for (const auto& neighbors : adjacencyList) {
        std::cout << vertex+1 << " --> ";
        for (int neighbor : neighbors) {
            std::cout << neighbor << " ";
        }
        std::cout << "\n";
        ++vertex;
    }
}

void Data::depthFirstSearch(int vertex) {
 
}