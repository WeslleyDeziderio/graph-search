#ifndef DFS_HPP
#define DFS_HPP

#include <string>

#include "../../include/utils/Data.hpp"
#include "../../include/utils/Vertex.hpp"

#define RED "'255, 0 , 0'"
#define BLUE "'0, 0, 255'"
#define ZERO_INDEX_REMOVER 1
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
    void showDepths();
};

#endif // DFS_HPP