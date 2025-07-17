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

GraphM::GraphM() {
    size = 0;

    for (int i = 0; i < MAXNODES; ++i) {
        for (int j = 0; j < MAXNODES; ++j) {
            if (i == j) {
                costM[i][j] = 0; 
            } else {
                costM[i][j] = 999999; 
            }
        }
    }

    for (int i = 0; i < MAXNODES; ++i) {
        for (int j = 0; j < MAXNODES; ++j) {
            shortP[i][j].visited = false;
            shortP[i][j].dist = 999999;
            shortP[i][j].path = 0;
        }
    }
}

GraphM::~GraphM() {

}

void GraphM::buildGraph(ifstream &infile) {

}

bool GraphM::insertEdge(int from, int to, int weight) {

}

bool GraphM::removeEdge(int from, int to) {

}

void GraphM::findShortestPath() {

}

void GraphM::dijkstra(int source) {

}

void GraphM::displayAll() const {

}

void GraphM::display(int fromNode, int toNode) const {

}

void GraphM::printPath(int from, int to) const {

}

void GraphM::printPathNames(int from, int to) const {
    
}