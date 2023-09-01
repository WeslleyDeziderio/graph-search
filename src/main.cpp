#include <iostream>
#include "../include/utils/Data.hpp"

int main(int argc, char** argv) {
    Data data(argc, argv[1]);
    std::string instanceName = data.getInstanceName();
    std::cout << "Reading: " << instanceName << std::endl;
    
    data.readData();
    data.printAdjacencyMatrix();
    data.printAdjacencyList();
}