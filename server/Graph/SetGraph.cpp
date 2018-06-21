#include <cassert>
#include "SetGraph.h"
#include <Constants/ConstValues.h>


SetGraph::SetGraph(unsigned int n) : adjacencyHashTable(n) {}

SetGraph::SetGraph(const VirtGraph *other)
        : adjacencyHashTable(other->verticesCount()) {
    for (int i = 0; i < verticesCount(); ++i) {
        for (int v : other->getNextVertices(i)) {
            adjacencyHashTable[i].insert(v);
        }
    }
}

void SetGraph::addEdge(int from, int to) {
    if (!isValidIndex(from)) {
        throw std::out_of_range("invalid index from");
    }
    if (!isValidIndex(to)) {
        throw std::out_of_range("invalid index to");
    }
    adjacencyHashTable[from].insert(to);
}

int SetGraph::verticesCount() const {
    return static_cast<int>(adjacencyHashTable.size());
}

std::vector<int> SetGraph::getNextVertices(int vertex) const {
    if (!isValidIndex(vertex)) {
        throw std::out_of_range("invalid vertex index");
    }
    std::vector<int> buf;
    for (int it : adjacencyHashTable[vertex]) {
        buf.push_back(it);
    }
    return buf;
}

std::vector<int> SetGraph::getPrevVertices(int vertex) const {
    if (!isValidIndex(vertex)) {
        throw std::out_of_range("invalid vertex index");
    }
    std::vector<int> buf;
    for (std::unordered_set<int> fromVertices : adjacencyHashTable) {
        std::unordered_set<int>::const_iterator v = fromVertices.find(vertex);
        if (v != fromVertices.end()) {
            buf.push_back(*v);
        }
    }
    return buf;
}

bool SetGraph::isValidIndex(int index) const {
    return index >= 0 && index < adjacencyHashTable.size();
}

void SetGraph::setUp(std::string stringMap) {
    for (int i = 0; i < GameMap::HEIGHT * GameMap::WIDTH; ++i) {

        if (stringMap[i] == ' ') {
            int neighbor = i - GameMap::WIDTH;
            if (stringMap[neighbor] == ' ') {
                this->addEdge(i, neighbor);
            }
            neighbor = i + 1;
            if (stringMap[neighbor] == ' ') {
                this->addEdge(i, neighbor);
            }
            neighbor = i - 1;
            if (stringMap[neighbor] == ' ') {
                this->addEdge(i, neighbor);
            }
            neighbor = i + GameMap::WIDTH;
            if (stringMap[neighbor] == ' ') {
                this->addEdge(i, neighbor);
            }
        }
    }
}