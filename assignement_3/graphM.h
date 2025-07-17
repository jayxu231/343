// ------------------------------------------------ graphM.h -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/15/2025
// Date of Last Modification : 
// ------------------------------------------------------------------------------------------------------------------
// Purpose: 
// ------------------------------------------------------------------------------------------------------------------
// Notes: 
// ------------------------------------------------------------------------------------------------------------------

#ifndef GRAPHM_H
#define GRAPHM_H

#include "nodedata.h"

const int MAXNODES = 100;

class GraphM {
    public:
        GraphM();

        void buildGraph(ifstream &infile);
        bool insertEdge(int from, int to, int weight);
        bool removeEdge(int from, int to);
        void findShortestPath();
        void displayAll() const;
        void display(int fromNode, int toNode) const;
    private:
        void dijkstra(int source);
        int findMinDist(int source);
        void printPath(int from, int to) const;
        void printPathNames(int from, int to) const;
        struct TableType {
            bool visited;
            int dist;
            int path;
        };
    
        NodeData data[MAXNODES];
        int costM[MAXNODES][MAXNODES];
        int size;
        TableType shortP[MAXNODES][MAXNODES];
};
#endif