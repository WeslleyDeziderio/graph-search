#ifndef DFS_HPP
#define DFS_HPP

#include <string>

#include "../../include/utils/Data.hpp"
#include "../../include/utils/Vertex.hpp"
#include "../../include/utils/Constants.hpp"

class DFS {
protected:
    Data dataDfs;
    std::vector<Vertex> graphVertex;
    int globalTimer = 0;
    std::vector<std::vector<std::string>> coloredEdges;
public:
    DFS(int params, char* instance);
    void recursiveDFS(Vertex);
    void setGlobalTimer(int);
    int getGlobalTimer();
    void incrementGlobalTimer();
    void initializeParams();
    void showDepths();
};

#endif // DFS_HPP