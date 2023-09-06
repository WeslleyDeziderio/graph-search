#ifndef DFS_HPP
#define DFS_HPP

#include "../../include/utils/Data.hpp"
#include "../../include/utils/Vertex.hpp"

class DFS {
protected:
    Data dataDfs;
    std::vector<Vertex> graphVertex;
    int globalTimer = 0;
    std::vector<std::vector<char>> coloredEdges;
public:
    DFS(int params, char* instance);
    void recursiveDFS(Vertex);
    void setGlobalTimer(int);
    int getGlobalTimer();
    void incrementGlobalTimer();
};

#endif // DFS_HPP