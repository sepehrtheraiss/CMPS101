// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa5
// Graph.c
// ----------------------------------------------------------------
//-----------------------------------------------------------------------------
// Graph.c
// Implementation file for Graph ADT
//-----------------------------------------------------------------------------
#include "Graph.h"

// struct --------------------------------------------------------------------

// private GraphObj type
typedef struct GraphObj{
    List* list;
    int* colors;// -1-> white, 0 -> grey, 1 -> black
    int* p; // parent vertex
    int* d; // destination
    int* discover_time; // disover time of vertex
    int* finish_time;  // finish time of finding all edges in a vertex
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
    graph->discover_time = malloc(sizeof(int)*(n+1));
    graph->finish_time = malloc(sizeof(int)*(n+1));
    graph->n_vertices = n;
    graph->n_edges = 0;
    graph->source = NIL;
    for(int i =1;i<n+1;i++)
    {
        graph->list[i] = newList();
        graph->p[i] = NIL;
        graph->colors[i] = -1;
        graph->d[i] = INF;
        graph->discover_time[i] = UNDEF;
        graph->finish_time[i] = UNDEF;

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
        free((*pG)->discover_time);
        free((*pG)->finish_time);
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
    if(G->d[u]==INF)
    {
        append(L,INF);
    }
    else
    {
        if(G->p[u]!=NIL)
        {
            getPath(L,G,G->p[u]);
            append(L,u);
        }
        else
        {
            append(L,u);
        }
    }

}
/* Pre: 1<=u<=n=getOrder(G) */
int getDiscover(Graph G, int u)
{
    if(G == NULL)
    {
        printf("Graph Error: Calling getDiscover() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return G->discover_time[u];
}
/* Pre: 1<=u<=n=getOrder(G) */
int getFinish(Graph G, int u)
{
    if(G == NULL)
    {
        printf("Graph Error: Calling getFinish() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    return G->finish_time[u];
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
        G->p[i] = NIL;
        G->colors[i] = -1;
        G->d[i] = INF;
    }
    G->n_edges=0;

}
// addEdge()
// pre: G != NULL 1<=u<=getOrder() && 1<=v<=getOrder()
// inserts a new edge joining u to v, i.e. u is added to the adjacency List of v,
// and v to the adjacency List of u. In sorting order
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
    if(length(G->list[u])==0)
    {
        append((G->list[u]),v);
    }
    else
    {
        moveBack(G->list[u]);
        while(index(G->list[u])!=-1 && get(G->list[u]) > v)
        {
            movePrev(G->list[u]);
        }
        if(index(G->list[u])==-1)// u < than list[1]
        {
            prepend(G->list[u],v);
        }
        else if(get(G->list[u]) == v) // if the same then replace
        {
            insertAfter(G->list[u],v);
            delete(G->list[u]);
        }
        else            // u > than list[1]
        {
            insertAfter(G->list[u],v);
        }
    }
    if(length(G->list[v])==0)
    {
        append((G->list[v]),u);
    }
    else
    {
        moveBack(G->list[v]);
        while(index(G->list[v])!=-1 && get(G->list[v]) > u)
        {
            movePrev(G->list[v]);
        }
        if(index(G->list[v])==-1) // v < than list[1]
        {
            prepend(G->list[v],u);
        }
        else if(get(G->list[v]) == u) // if the same then replace
        {
            insertAfter(G->list[v],u);
            delete(G->list[v]);
        }
        else // v > than list[1]
        {
            insertAfter(G->list[v],u);
        }
    }
    G->n_edges++;
}
// addArc
// pre: G != NULL 1<=u<=getOrder() && 1<=v<=getOrder()
// inserts a new directed edge from u to v, i.e.
// v is added to the adjacency List of u (but not u to the adjacency List of v) In sorting order
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
    if(length(G->list[u])==0)
    {
        append((G->list[u]),v);
    }
    else
    {
        moveBack(G->list[u]);
        while(index(G->list[u])!=-1 && get(G->list[u]) > v)
        {
            movePrev(G->list[u]);
        }
        if(index(G->list[u])==-1) // u < than list[1]
        {
            prepend(G->list[u],v);
        }
        else if(get(G->list[u]) == v) // if the same then replace
        {
            insertAfter(G->list[u],v);
            delete(G->list[u]);
        }
        else    // v > than list[1]
        {
            insertAfter(G->list[u],v);
        }
    }
    G->n_edges++;
}
// BFS()
// pre: G != NULL
// runs the BFS algorithm on the Graph G with source s, setting the color,
// distance, parent, and source fields of G accordingly.
void BFS(Graph G, int s)
{
    if( G==NULL )
    {
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
    freeList(&Q);
}
void Visit(Graph G,List S,int x,int* time)
{
    if( G==NULL )
    {
        printf("Graph Error: Calling Visit() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    G->colors[x] = 0;
    G->discover_time[x] = ++(*time);
    moveFront(G->list[x]);
    while(index(G->list[x])!=-1)
    {
        if(G->colors[get(G->list[x])] == -1)
        {
            G->p[get(G->list[x])] = x;
            Visit(G,S,get(G->list[x]),time);
        }
        moveNext(G->list[x]);
    }
    G->colors[x]=1;
    G->finish_time[x] = ++(*time);
    prepend(S,x);
}
 /* Pre: length(S)==getOrder(G) */
void DFS(Graph G, List S)
{
    if( G==NULL )
    {
        printf("Graph Error: Calling DFS() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    if( length(S) != getOrder(G))
    {
        printf("Graph Error: Calling DFS() on length(S) != getOrder(G)\n");
        exit(EXIT_FAILURE);
    }
    for(int i =1;i<G->n_vertices+1;i++)
    {
        G->colors[i]=-1;
        G->p[i]=NIL;
        G->discover_time[i]=UNDEF;
        G->finish_time[i]=UNDEF;
    }
    int time=0;
    moveFront(S);
    while(index(S)!=-1)
    {
        if(G->colors[get(S)] == -1)
        {
            Visit(G,S,get(S),&time);
        }
        moveNext(S);
    }
    // delete unwanted vertices
    for(int i =0;i<getOrder(G);i++)
    {
        deleteBack(S);
    }
}

/*** Other operations ***/
// transpose()
// pre: G!= NULL
// returns transpose of G
Graph transpose(Graph G)
{
    Graph T = newGraph(getOrder(G));
    for(int i=1;i<getOrder(G)+1;i++)
    {
        moveFront(G->list[i]);
        while(index(G->list[i])!=-1)
        {
            addArc(T,get(G->list[i]),i);
            moveNext(G->list[i]);
        }
    }
    return T;
}
// copyGraph()
// pre: G!= NULL
Graph copyGraph(Graph G)
{
    Graph C = newGraph(getOrder(G));
    for(int i=1;i<getOrder(G)+1;i++)
    {
        moveFront(G->list[i]);
        while(index(G->list[i])!=-1)
        {
            addArc(C,i,get(G->list[i]));
            moveNext(G->list[i]);
        }
    }
    return C;
}
// printGraph()
// pre: G != NULL
// prints the adjacency list representation of G
// to the file pointed to by out.
void printGraph(FILE* out, Graph G)
{
    if( G==NULL ){
        fprintf(out,"Graph Error: Calling printGraph() on NULL Graph reference\n");
        exit(EXIT_FAILURE);
    }
    for(int i=1;i<G->n_vertices+1;i++)
    {
        fprintf(out,"%i:",i);
        moveFront(G->list[i]);
        if(index(G->list[i])==-1) // this is ridiculous why would you want to print space if its null!
        {
            fprintf(out," ");
        }
        while(index(G->list[i])!= -1)
        {
            fprintf(out," %i",get(G->list[i]));
            moveNext(G->list[i]);
        }
        fprintf(out,"\n");
    }
}
