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
    int n_vertices; // num of vertices, order
    int n_edges; // num of edges, size
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
    graph->source = NIL;
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
/*** Access functions ***/
// getOrder()
// pre: G != NULL
int getOrder(Graph G)
{
    if( G==NULL ){
        printf("Graph Error: Calling getOrder() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return G->n_vertices;
}
// getSize()
// pre: G != NULL
int getSize(Graph G)
{
    if( G==NULL ){
        printf("Graph Error: Calling getSize() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return G->n_edges;
}
// getSource()
// pre: G != NULL
int getSource(Graph G)
{
    if( G==NULL ){
        printf("Graph Error: Calling getSource() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return G->source;
}
// getParent()
// pre: G != NULL 1<=u<=getOrder()
int getParent(Graph G, int u)
{
    if( G==NULL ){
        printf("Graph Error: Calling getParent() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if(u<1)
    {
        printf("Graph Error: Calling getParent() on u < 1\n");
        exit(EXIT_FAILURE);
    }
    if(u > getOrder(G))
    {
        printf("Graph Error: Calling getParent() on u > getOrder()");
        exit(EXIT_FAILURE);
    }
    return G->p[u];
}
// getDist()
// pre: G != NULL 1<=u<=getOrder()
int getDist(Graph G, int u)
{
    if( G==NULL ){
        printf("Graph Error: Calling getDist() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if(u<1)
    {
        printf("Graph Error: Calling getDist() on u < 1\n");
        exit(EXIT_FAILURE);
    }
    if(u > getOrder(G))
    {
        printf("Graph Error: Calling getDist() on u > getOrder()");
        exit(EXIT_FAILURE);
    }
    return G->d[u];
}
// getPath
// pre: G != NULL 1<=u<=getOrder()
void getPath(List L, Graph G, int u)
{
    if( G==NULL ){
        printf("Graph Error: Calling getPath() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if(u<1)
    {
        printf("Graph Error: Calling getPath() on u < 1\n");
        exit(EXIT_FAILURE);
    }
    if(u > getOrder(G))
    {
        printf("Graph Error: Calling getPath() on u > getOrder()");
        exit(EXIT_FAILURE);
    }

}
/*** Manipulation procedures ***/
// addEdge()
// pre: G != NULL
void addEdge(Graph G, int u, int v)
{
    if( G==NULL ){
        printf("Graph Error: Calling addEdge() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
}
// addArc
// pre: G != NULL
void addArc(Graph G, int u, int v)
{
    if( G==NULL ){
        printf("Graph Error: Calling addArc() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
}
// BFS()
// pre: G != NULL
void BFS(Graph G, int s)
{
    if( G==NULL ){
        printf("Graph Error: Calling BFS() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
}
/*** Other operations ***/
// printGraph()
// pre: G != NULL
void printGraph(FILE* out, Graph G)
{
    if( G==NULL ){
        printf("Graph Error: Calling printGraph() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
}