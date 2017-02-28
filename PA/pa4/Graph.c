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
// returns the number of vertices
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
// returns the number of edges
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
// returns the source vertex most recently used in function BFS(),
// or NIL if BFS() has not yet been called.
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
// returns the parent of vertex u in the BreadthFirst tree created by BFS(),
// or NIL if BFS() has not yet been called
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
// returns the distance from the most recent BFS source to vertex u,
// or INF if BFS() has not yet been called
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
// pre: G != NULL, 1<=u<=getOrder(), getSource(G)!=NIL
// appends to the List L the vertices of a shortest path in G from source to u,
// or appends to L the value NIL if no such path exists
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
    if(getSource(G)==NIL)
    {
        printf("Graph Error: Calling getPath() on getSource(G)==NIL)");
        exit(EXIT_FAILURE);
    }
    // just the last vertex
    printf("to V: %i distance is: %i\n",u,G->d[u]);

}
/*** Manipulation procedures ***/
// makeNUll()
// pre: G != NULL
// deletes all edges of G, restoring it to its original (no edge) state.
void makeNull(Graph G)
{
    if(G == NULL)
    {
        printf("Graph Error: Calling makeNull() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    for(int i =1 ;i<G->n_vertices+1;i++)
    {
        clear(G->list[i]);
    }

}
// addEdge()
// pre: G != NULL 1<=u<=getOrder() && 1<=v<=getOrder()
void addEdge(Graph G, int u, int v)
{
    if( G==NULL ){
        printf("Graph Error: Calling addEdge() on NULL Graph reference\n");
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
    if(v<1)
    {
        printf("Graph Error: Calling getPath() on v < 1\n");
        exit(EXIT_FAILURE);
    }
    if(v > getOrder(G))
    {
        printf("Graph Error: Calling getPath() on v > getOrder()");
        exit(EXIT_FAILURE);
    }
    append((G->list[u]),v);
    append((G->list[v]),u);
    G->n_edges++;
}
// addArc
// pre: G != NULL 1<=u<=getOrder() && 1<=v<=getOrder()
void addArc(Graph G, int u, int v)
{
    if( G==NULL ){
        printf("Graph Error: Calling addArc() on NULL Graph reference\n");
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
    if(v<1)
    {
        printf("Graph Error: Calling getPath() on v < 1\n");
        exit(EXIT_FAILURE);
    }
    if(v > getOrder(G))
    {
        printf("Graph Error: Calling getPath() on v > getOrder()");
        exit(EXIT_FAILURE);
    }
    append((G->list[u]),v);
    G->n_edges++;
}
// BFS()
// pre: G != NULL
void BFS(Graph G, int s)
{
    if( G==NULL ){
        printf("Graph Error: Calling BFS() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    G->source = s;
    for(int i =1;i<G->n_vertices+1;i++)
    {
        G->colors[i]=-1;
        G->d[i]=INF;
        G->p[i]=NIL;
    }
    G->colors[s]=0;
    G->d[s]=0;
    G->p[s]=NIL;
    int x =0;
    int y=0;
    List Q = newList();
    append(Q,s);
    while(length(Q)!=0)
    {
        x = front(Q);
        deleteFront(Q);
        moveFront(G->list[x]);
        while(index(G->list[x])!=-1)
        {
            y = get(G->list[x]);
            if(G->colors[y]== -1)
            {
                G->colors[y]=0;
                G->d[y]= G->d[x]+1;
                G->p[y] = x;
                append(Q,y);
            }
            moveNext(G->list[x]);
        }
        G->colors[x]=1;
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
    for(int i=1;i<G->n_vertices+1;i++)
    {
        printf("%i: ",i);
        moveFront(G->list[i]);
        while(index(G->list[i])!= -1)
        {
            printf("%i ",get(G->list[i]));
            moveNext(G->list[i]);
        }
        printf("\n");
    }
}