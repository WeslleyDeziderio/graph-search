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