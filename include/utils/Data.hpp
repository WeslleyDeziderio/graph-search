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
    mutable std::list<std::list<int>> adjacencyList;
public:
    Data();
    Data(int params, char* instance);
    void readData();
    std::string getInstanceName();
    int getNumVertices() const;
    const std::vector<std::vector<int>>& getAdjacencyMatrix() const;
    void printAdjacencyMatrix();
    const std::list<std::list<int>>& getAdjacencyList() const;
    void printAdjacencyList();
    bool isAdjacency(int, int) const;
    std::list<int> getNeighborhoodList(int) const;
    std::vector<int> getNeighborhoodMatrix(int) const;
};

#endif // DATA_HPP