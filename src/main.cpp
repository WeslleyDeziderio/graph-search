#include <iostream>
#include <chrono>
#include "../include/utils/Data.hpp"
#include "../include/utils/Vertex.hpp"
#include "../include/utils/DFS.hpp"
#include "../include/utils/BFS.hpp"

int main(int argc, char** argv) {   
    auto startTime = std::chrono::high_resolution_clock::now();

    std::cout << "Executing Depth-First-Search" << std::endl;
    DFS dfs(argc, argv[1]);
    Vertex initialVertexDfs;
    initialVertexDfs.setVertex(1);
    dfs.recursiveDFS(initialVertexDfs);
    dfs.showDepths();

    std::cout << "\nExecuting Breadth-First-Search" << std::endl;
    BFS bfs(argc, argv[1]);
    Vertex initialVertexBfs;
    initialVertexBfs.setVertex(1);
    bfs.interactiveBfs(initialVertexBfs);
    bfs.showBreadth();

    auto finalTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeTaken = finalTime-startTime;
    std::cout << "\nTime taken: " << timeTaken.count() << " ms\n" << std::endl;
    return 0;
}