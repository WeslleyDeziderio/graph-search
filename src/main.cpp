#include <iostream>
#include <chrono>
#include "../include/utils/Data.hpp"
#include "../include/utils/Vertex.hpp"
#include "../include/utils/DFS.hpp"

int main(int argc, char** argv) {
    DFS dfs(argc, argv[1]);
    
    auto startTime = std::chrono::high_resolution_clock::now();

    auto finalTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeTaken = finalTime-startTime;
    std::cout << "Time taken: " << timeTaken.count() << " ms\n" << std::endl;
    return 0;
}