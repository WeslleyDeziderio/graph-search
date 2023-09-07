#ifndef VERTEX_HPP
#define VERTEX_HPP

#include "../../include/utils/Data.hpp"

class Vertex {
protected:
    int vertex;
    int entryDepth;
    int exitDepth;
    int ancestral;
    int searchIndex;
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
    void setSearchIndex(int);
    int getSearchIndex();
};

#endif // VERTEX_HPP