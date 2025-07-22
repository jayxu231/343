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
#include <sstream>


GraphM::GraphM() {
    size = 0;

    for (int i = 0; i < MAXNODES_H; ++i) {
        for (int j = 0; j < MAXNODES_H; ++j) {
            if (i == j) {
                costM[i][j] = 0; 
            } else {
                costM[i][j] = INF; 
            }
        }
    }

    for (int i = 0; i < MAXNODES_H; ++i) {
        for (int j = 0; j < MAXNODES_H; ++j) {
            shortP[i][j].visited = false;
            shortP[i][j].dist = INF;
            shortP[i][j].path = 0;
        }
    }
}

GraphM::~GraphM() {

}
bool GraphM::isEmpty() const {
    return size == 0;
}

void GraphM::buildGraph(ifstream &infile) {
    infile >> size;
    if (infile.fail() || size == 0) {
        return;
    }

    infile.ignore(INF, '\n');

    string line;
    for (int i = 1; i <= size; i++) {
        getline(infile, line);
        istringstream ss(line);
        data[i].setData(ss);    
    }

    int from, to, cost;
    while (infile >> from >> to >> cost) {
        // cout << "from " << from << " to " << to << " cost " << cost << endl;
        if (from == 0 && to == 0 && cost == 0) break;
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
                costM[v][w] != INF && shortP[source][v].dist + costM[v][w] < shortP[source][w].dist) {

                shortP[source][w].dist = shortP[source][v].dist + costM[v][w];
                shortP[source][w].path = v;
            }
        }
    }
}

int GraphM::findMinDist(int source) {
    int minDist = INF;
    int minIndex = 0;

    for(int i = 1; i <= size ; i++) {
        if(!shortP[source][i].visited && shortP[source][i].dist < minDist){
            minDist = shortP[source][i].dist;
            minIndex = i;
        }
    }
    return minIndex;
}

void GraphM::displayAll() const {
    cout << left
         << setw(20) << "Description"
         << setw(12) << "From node"
         << setw(10) << "To node"
         << setw(15) << "Dijkstra's"
         << "Path" << endl;

    for (int from = 1; from <= size; from++) {
        cout << data[from] << endl;

        for (int to = 1; to <= size; to++) {
            if (from == to) continue;

            cout << setw(24) << " "  // indent
                 << setw(10) << from
                 << setw(10) << to;

            if (shortP[from][to].dist == INF) {
                cout << setw(15) << "----" << endl;
            } else {
                cout << setw(15) << shortP[from][to].dist;
                printPath(from, to);
                cout << endl;
            }
        }
    }
}




void GraphM::display(int fromNode, int toNode) const {
    if (fromNode < 1 || fromNode > size || toNode < 1 || toNode > size) return;
    if (fromNode == toNode) return;

    if (shortP[fromNode][toNode].dist == INF) {
        cout << "From Node:     " << fromNode << "    To Node:     " << toNode ;
        cout << "          ----" << endl;
        return;
    }

    cout << "From Node:     " << fromNode << "    To Node:     " << toNode << "        ";
    cout << "Shortest Distance:  " << shortP[fromNode][toNode].dist << "                ";
    printPath(fromNode, toNode);
    cout << endl;

    printPathNames(fromNode, toNode);
    cout << endl;
}


void GraphM::printPath(int from, int to) const {
    if (from == to) {
        cout << from << " ";
        return;
    }

    if (shortP[from][to].path == 0) {
        cout << to << " "; // No path, just print destination
        return;
    }

    printPath(from, shortP[from][to].path);
    cout << to << " ";
}

 

void GraphM::printPathNames(int from, int to) const {
    if (from == to) {
        cout << data[from] << endl;
        return;
    }

    if (shortP[from][to].path == 0) {
        cout << data[to] << endl;  // No path, just print destination
        return;
    }

    printPathNames(from, shortP[from][to].path);
    cout << endl << data[to] << endl;
}