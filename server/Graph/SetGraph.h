#ifndef FIND_SHORTEST_WAY_SETGRAPH_H
#define FIND_SHORTEST_WAY_SETGRAPH_H

#include<unordered_set>
#include "VirtGraph.h"


class SetGraph: public VirtGraph {
public:
    explicit SetGraph(unsigned int n );
    explicit SetGraph( const VirtGraph* other );

    void AddEdge( int from, int to ) final;

    int VerticesCount() const final;

    std::vector<int> GetNextVertices( int vertex ) const final;
    std::vector<int> GetPrevVertices( int vertex ) const final;
    void setUp(std::string stringMap);

private:
    std::vector<std::unordered_set<int>> adjacencyHashTable;
    bool isValidIndex( int index ) const;
};


#endif //FIND_SHORTEST_WAY_SETGRAPH_H
