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
    int level;
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
    void setLevel(int);
    int getLevel();
};

#endif // VERTEX_HPP