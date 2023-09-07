#ifndef BFS_HPP
#define BFS_HPP

#include <queue>

#include "../../include/utils/Data.hpp"
#include "../../include/utils/Vertex.hpp"

#define RED 'r'
#define GREEN 'g'
#define BLUE 'b'
#define YELLOW 'y'
#define ZERO_INDEX_REMOVER 1
class BFS {
protected:
    Data dataBfs;
    int globalTimer = 0;
    std::vector<Vertex> graphVertex;
    std::queue<Vertex> auxQueue;
    std::vector<std::vector<char>> coloredEdges;
public:
    BFS(int, char*);
    void setGlobalTimer(int);
    int getGlobalTimer();
    void incrementGlobalTimer();
    void interactiveBfs(Vertex);
    void showBreadth();
};

#endif // BFS_HPP