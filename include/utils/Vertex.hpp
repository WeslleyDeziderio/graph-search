#ifndef VERTEX_HPP
#define VERTEX_HPP

#define RED 'r'
#define BLUE 'b'

#include "../../include/utils/Data.hpp"

class Vertex {
protected:
    Data data;
    int vertex;
    int entryDepth;
    int exitDepth;
    int ancestral;
public:
    Vertex();
    void setEntryDepth(int);
    int getEntryDepth();
    void setExitDepth(int);
    int getExitDepth();
    void setVertex(int);
    int getVertex();
    void setAncestral(int);
    int getAncestral();
};

#endif // VERTEX_HPP