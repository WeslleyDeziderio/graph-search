#ifndef BFS_HPP
#define BFS_HPP

#include <queue>
#include <string>

#include "../../include/utils/Data.hpp"
#include "../../include/utils/Vertex.hpp"

#define RED "'255, 0, 0'"
#define GREEN "'0, 255, 0'"
#define BLUE "'0, 0, 255'"
#define YELLOW "'255, 255, 0'"
#define ZERO_INDEX_REMOVER 1
class BFS {
protected:
    Data dataBfs;
    int globalTimer = 0;
    std::vector<Vertex> graphVertex;
    std::queue<Vertex> auxQueue;
    std::vector<std::vector<std::string>> coloredEdges;
public:
    BFS(int, char*);
    void setGlobalTimer(int);
    int getGlobalTimer();
    void incrementGlobalTimer();
    void interactiveBfs(Vertex);
    void showBreadth();
};

#endif // BFS_HPP