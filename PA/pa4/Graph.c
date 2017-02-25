// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa4
// Graph.c
// ----------------------------------------------------------------
//-----------------------------------------------------------------------------
// Graph.c
// Implementation file for List ADT
//-----------------------------------------------------------------------------
#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "Graph.h"
#define INF -1
#define NIL 0
// struct --------------------------------------------------------------------

// private GraphObj type
typedef struct GraphObj{
    List* list;
    int* colors;// -1-> white, 0 -> grey, 1 -> black
    int* p; // parent vertex
    int* d; // destination
    int n_vertices; // num of vertices
    int n_edges; // num of edges
    int source; // label of the most recently visited vertex
} GraphObj;

/*** Constructors-Destructors ***/
/**returns a Graph pointing to a newly created GraphObj representing a graph having
n vertices and no edges***/
Graph newGraph(int n)
{
    Graph graph = malloc(sizeof(GraphObj));
    graph->list = malloc(sizeof(List)*(n+1));
    graph->p = malloc(sizeof(int)*(n+1));
    graph->colors = malloc(sizeof(int)*(n+1));
    graph->d = malloc(sizeof(int)*(n+1));
    graph->n_vertices = n;
    graph->n_edges = 0;
    graph->source = 0;
    for(int i =1;i<n+1;i++)
    {
        graph->list[i] = newList();
        graph->p[i] = NIL;
        graph->colors[i] = -1;
        graph->d[i] = INF;
    }
    return graph;
}
/*** frees all dynamic memory associated with the Graph
*pG, then sets the handle *pG to NULL.***/
// freeGraph()
// pre: *pG != NULL, pG != NULL
void freeGraph(Graph* pG)
{
    if(pG!=NULL && *pG!=NULL) {
        for(int i=1;i<(*pG)->n_vertices+1;i++)
        {
            freeList(&((*pG)->list[i]));
        }
        free((*pG)->list);
        free((*pG)->p);
        free((*pG)->colors);
        free((*pG)->d);
        free(*pG);
        *pG = NULL;
    }
}
