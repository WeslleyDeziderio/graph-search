#ifndef BFS_HPP
#define BFS_HPP

#include <deque>
#include <string>

#include "../../include/utils/Data.hpp"
#include "../../include/utils/Vertex.hpp"
#include "../../include/utils/Constants.hpp"

class BFS {
protected:
    Data dataBfs;
    int globalTimer = 0;
    std::vector<Vertex> graphVertex;
    std::deque<Vertex> auxQueue;
    std::vector<std::vector<std::string>> coloredEdges;
public:
    BFS(int, char*);
    void setGlobalTimer(int);
    int getGlobalTimer();
    void incrementGlobalTimer();
    void interactiveBfs(Vertex);
    void initializeParams();
    void calculateMetrics();
    void showBreadth();
};

#endif // BFS_HPP