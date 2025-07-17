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

int MAXNODES = 100;

class GraphM {
    public:

    private:
    struct TableType {
        bool visited;
        int dist;
        int path;
    };

    NodeData data[MAXNODES];
    int C[MAXNODES][MAXNODES];
    int size;
    TableType T[MAXNODES][MAXNODES];
}
#endif