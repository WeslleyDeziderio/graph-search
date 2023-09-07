#include "../../include/utils/Vertex.hpp"

Vertex::Vertex() {}

void Vertex::setEntryDepth(int entryDepth) {
    this->entryDepth = entryDepth;
}

int Vertex::getEntryDepth() {
    return entryDepth;
}

void Vertex::setExitDepth(int exitDepth) {
    this->exitDepth = exitDepth;
}

int Vertex::getExitDepth() {
    return exitDepth;
}

void Vertex::setVertex(int vertex) {
    this->vertex = vertex;
}

int Vertex::getVertex() {
    return vertex;
}

void Vertex::setAncestral(int ancestral) {
    this->ancestral = ancestral;
}

int Vertex::getAncestral() {
    return ancestral;
}

void Vertex::setSearchIndex(int searchIndex) {
    this->searchIndex = searchIndex;
}

int Vertex::getSearchIndex() {
    return searchIndex;
}

void Vertex::setLevel(int level) {
    this->level = level;
}

int Vertex::getLevel() {
    return level;
}