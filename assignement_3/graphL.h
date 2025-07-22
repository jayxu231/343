// ------------------------------------------------ graphL.h -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/15/2025
// Date of Last Modification : 
// ------------------------------------------------------------------------------------------------------------------
// Purpose: 
// ------------------------------------------------------------------------------------------------------------------
// Notes: 
// ------------------------------------------------------------------------------------------------------------------
#ifndef GRAPHL_H
#define GRAPHL_H


#include "nodedata.h"



int const MAXNODES = 101;
class GraphL {
public:
    GraphL();
    ~GraphL();
    void buildGraph(ifstream &infile);
    void displayGraph() const;
    void depthFirstSearch();

private:
    struct EdgeNode {
        int adjGraphNode;
        EdgeNode *nextEdge;
    };

    struct GraphNode {
        EdgeNode *edgeHead;
        NodeData *data;
        bool visited;
    };

    GraphNode graph[MAXNODES];
    int size;

    void dfsHelper(int index);
    void makeEmpty();
};


#endif