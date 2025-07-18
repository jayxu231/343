// ------------------------------------------------ graphM.cpp -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/15/2025
// Date of Last Modification : 
// ------------------------------------------------------------------------------------------------------------------
// Purpose: 
// ------------------------------------------------------------------------------------------------------------------
// Notes: 
// ------------------------------------------------------------------------------------------------------------------

#include "graphM.h"       
#include <iomanip>  
#include <climits>

const int INF = INT_MAX;

GraphM::GraphM() {
    size = 0;

    for (int i = 0; i < MAXNODES; ++i) {
        for (int j = 0; j < MAXNODES; ++j) {
            if (i == j) {
                costM[i][j] = 0; 
            } else {
                costM[i][j] = INF; 
            }
        }
    }

    for (int i = 0; i < MAXNODES; ++i) {
        for (int j = 0; j < MAXNODES; ++j) {
            shortP[i][j].visited = false;
            shortP[i][j].dist = INF;
            shortP[i][j].path = 0;
        }
    }
}

GraphM::~GraphM() {

}

void GraphM::buildGraph(ifstream &infile) {
    infile >> size; 
    infile.ignore();

   for(int i = 1; i <= size; i++) {
    data[i].setData(infile);
   }
   int from, to, cost;
   while(infile >> from >> to >> cost) {
        if(from == 0 && to == 0 && cost == 0) {
            break;
        }
        costM[from][to] = cost;
   }
}

bool GraphM::insertEdge(int from, int to, int weight) {
    if(from < 1 || from > size || to < 1 || to > size || weight == 0) {
        return false;
    }
    costM[from][to] = weight;
    return true;
}

bool GraphM::removeEdge(int from, int to) {
    if(from < 1 || from > size || to < 1 || to > size) {
        return false;
    }
    costM[from][to] = INF;
    return true;
}

void GraphM::findShortestPath() {
    for(int source = 1; source <= size; ++source) {
        dijkstra(source);
    }
}

void GraphM::dijkstra(int source) {
    for (int i = 1; i <= size; ++i) {
        shortP[source][i].dist = INF;
        shortP[source][i].visited = false;
        shortP[source][i].path = 0;
    }
    shortP[source][source].dist = 0;

    for (int i = 1; i <= size; ++i) {
        int v = findMinDist(source);  
        if (v == 0) return;           
        shortP[source][v].visited = true;

        for (int w = 1; w <= size; ++w) {
            if (!shortP[source][w].visited &&
                costM[v][w] != INF &&
                shortP[source][v].dist + costM[v][w] < shortP[source][w].dist) {

                shortP[source][w].dist = shortP[source][v].dist + costM[v][w];
                shortP[source][w].path = v;
            }
        }
    }
}

int GraphM::findMinDist(int source) {
    
}

void GraphM::displayAll() const {

}

void GraphM::display(int fromNode, int toNode) const {

}

void GraphM::printPath(int from, int to) const {

}

void GraphM::printPathNames(int from, int to) const {
    
}