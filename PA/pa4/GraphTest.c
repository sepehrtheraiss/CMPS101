//
// Created by sepehr on 2/24/17.
//
#include "Graph.h"
int main()
{
    Graph g = newGraph(5);
    freeGraph(&g);
    g = newGraph(5);
    printf("%i\n",getOrder(g));
    printf("%i\n",getSize(g));
    printf("%i\n",getDist(g,1));
    printf("%i\n",getParent(g,1));
    //printf("%i\n",getParent(g,0));
    //printf("%i\n",getDist(g,6));
    printf("%i\n",getDist(g,5));
    freeGraph(&g);
    //printf("%i\n",getDist(g,5));
    g = newGraph(5);
    addEdge(g,1,2);
    addEdge(g,1,3);
    addEdge(g,1,4);
    addEdge(g,2,3);
    //addEdge(g,6,1);
    //addEdge(g,0,1);
    //addEdge(g,5,0);
    //addEdge(g,5,6);
    printf("%i\n",getSize(g));
    printGraph(stdout,g);
    makeNull(g);
    printGraph(stdout,g);
    g = newGraph(6);
    addEdge(g,1,3);
    addEdge(g,1,2);
    addEdge(g,2,4);
    addEdge(g,2,5);
    addEdge(g,2,6);
    addEdge(g,3,4);
    addEdge(g,4,5);
    addEdge(g,5,6);
    printGraph(stdout,g);
    int s = 3;
    int d = 2;
    BFS(g,s);
    List l = newList();
    printf("The distance from %i to %i is %i\n",s,d,getDist(g,d));
    getPath(l,g,2);
    printList(stdout,l);
    makeNull(g);
    freeGraph(&g);
    return 0;
}
