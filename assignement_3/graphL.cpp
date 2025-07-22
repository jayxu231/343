// ------------------------------------------------ graphL.cpp -------------------------------------------------------
// Jayden Sastradi CSS 343
// Creation Date : 7/15/2025
// Date of Last Modification : 
// ------------------------------------------------------------------------------------------------------------------
// Purpose: 
// ------------------------------------------------------------------------------------------------------------------
// Notes: 
// ------------------------------------------------------------------------------------------------------------------

#include "graphL.h"
#include <iomanip>
#include <sstream>


GraphL::GraphL() {
    for (int i = 0; i < MAXNODES; i++) {
        graph[i].edgeHead = nullptr;
        graph[i].data = nullptr;        
        graph[i].visited = false;
    }
    size = 0;

}

GraphL::~GraphL() {
    makeEmpty();
}

void GraphL::makeEmpty() {
    for (int i = 1; i <= size; i++) {
        EdgeNode * curr = graph[i].edgeHead;
        while( curr != nullptr) {
            EdgeNode * toDelete = curr;
            curr = curr->nextEdge;
            delete toDelete;
        }
        
        graph[i].edgeHead = nullptr;
        delete graph[i].data;
        graph[i].data = nullptr;
        graph[i].visited = false; 
    }
    size = 0;
    
}
void GraphL::buildGraph(ifstream &infile) {
    infile >> size;

    if (infile.fail() || size == 0) {
        return;
    }

    infile.ignore(INF, '\n');
    
    string line;
    for(int i = 1; i <= size; i++) {
        getline(infile, line);
        istringstream ss(line);
        graph[i].data = new NodeData();
        graph[i].data->setData(ss);
    }

    
    int from, to;
    while (infile >> from >> to) {
        if (from == 0 && to == 0) break;
        EdgeNode* newEdge = new EdgeNode;
        newEdge->adjGraphNode = to;

        newEdge->nextEdge = graph[from].edgeHead;
        graph[from].edgeHead = newEdge;
    }
}

void GraphL::displayGraph() const {
    cout << "Graph:" << endl;

    for (int i = 1; i <= size; i++) {

        cout << left << setw(8) << ("Node" + to_string(i))
             << *graph[i].data << endl;

        EdgeNode* curr = graph[i].edgeHead;
        while (curr != nullptr) {
            cout << setw(4) << " " << setw(6) << "edge" << setw(4) << i << curr->adjGraphNode << endl;
            curr = curr->nextEdge;
        }

        cout << endl; 
    }
}


void GraphL::depthFirstSearch() {
    for (int i = 1; i <= size; i++) {
        graph[i].visited = false;
    }


    cout << "Depth-first ordering:";
    dfsHelper(1);
    cout << endl;
}


void GraphL::dfsHelper(int v) {
    if (graph[v].visited) return;

    graph[v].visited = true;
    cout << " " << v;

    EdgeNode* curr = graph[v].edgeHead;
    while (curr != nullptr) {
        int neighbor = curr->adjGraphNode;
        if (!graph[neighbor].visited) {
            dfsHelper(neighbor);
        }
        curr = curr->nextEdge;
    }
}