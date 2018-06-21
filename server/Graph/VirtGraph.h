#ifndef FIND_SHORTEST_WAY_VIRTGRAPH_H
#define FIND_SHORTEST_WAY_VIRTGRAPH_H

#include <vector>

struct VirtGraph {
    virtual ~VirtGraph() {
    }


    virtual void addEdge(int from, int to) = 0;

    virtual int verticesCount() const = 0;

    virtual std::vector<int> getNextVertices(int vertex) const = 0;

    virtual std::vector<int> getPrevVertices(int vertex) const = 0;
};


#endif //FIND_SHORTEST_WAY_VIRTGRAPH_H
