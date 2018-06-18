#ifndef FIND_SHORTEST_WAY_VIRTGRAPH_H
#define FIND_SHORTEST_WAY_VIRTGRAPH_H

#include <vector>

struct VirtGraph {
    virtual ~VirtGraph() {
    }

    virtual void AddEdge(int from, int to) = 0;

    virtual int VerticesCount() const = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;

    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};


#endif //FIND_SHORTEST_WAY_VIRTGRAPH_H
