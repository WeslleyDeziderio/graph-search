#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

class Data {
protected:
    int paramsNumber;
    int numVertices;
    std::string instanceName;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::list<std::list<int>> adjacencyList;
    std::vector<std::vector<char>> coloredAdjacencyMatrix;
public:
    Data(int params, char* instance);
    void readData();
    std::string getInstanceName();
    void printAdjacencyMatrix();
    std::list<std::list<int>> getAdjacencyList();
    void printAdjacencyList();
};

#endif // DATA_HPP