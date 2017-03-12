//
// Created by sepehr on 2/24/17.
//
#include "Graph.h"
int main()
{
//    Graph g = newGraph(8);
//    addArc(g,1,2);
//    addArc(g,2,3);
//    addArc(g,2,5);
//    addArc(g,2,6);
//    addArc(g,3,4);
//    addArc(g,3,7);
//    addArc(g,4,3);
//    addArc(g,4,8);
//    addArc(g,5,1);
//    addArc(g,5,6);
//    addArc(g,6,7);
//    addArc(g,7,6);
//    addArc(g,7,8);
//    addArc(g,8,8);
//    List S = newList();
//    for(int i=1;i<=8;i++)
//    {
//        prepend(S,i);
//    }
//    printGraph(stdout,g);
//    //printList(stdout,S);
//    DFS(g,S);
    Graph g = newGraph(11);
    addArc(g,1,2);
    addArc(g,2,5);
    addArc(g,3,2);
    addArc(g,3,5);
    addArc(g,4,1);
    addArc(g,5,4);
    addArc(g,6,3);
    addArc(g,6,5);
    addArc(g,6,9);
    addArc(g,6,10);
    addArc(g,7,3);
    addArc(g,7,6);
    addArc(g,8,4);
    addArc(g,9,4);
    addArc(g,9,5);
    addArc(g,9,8);
    addArc(g,10,9);
    addArc(g,10,11);
    addArc(g,11,7);
    printGraph(stdout,g);
    List S = newList();
    for(int i=1;i<=11;i++)
    {
        prepend(S,i);
    }
    DFS(g,S);
    printList(stdout,S);
    printf("\n");
    Graph T = transpose(g);
    printGraph(stdout,T);
    Graph C = copyGraph(g);
    printGraph(stdout,C);
    freeGraph(&g);
    return 0;
}
