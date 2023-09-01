#ifndef DFS_HPP
#define DFS_HPP

#define RED 'r'
#define GREEN 'g'
#define BLUE 'b'
#define YELLOW 'y'

#include <list>
#include "../../include/utils/Data.hpp"

class DFS : public Data {
protected:
    int entryDepth;
    int exitDepth;
    int ancestral;
public:
    DFS();
};

#endif // DFS_HPP