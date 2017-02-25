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
    printf("%i\n",getDist(g,5));
    return 0;
}
