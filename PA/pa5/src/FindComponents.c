// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa5
// Due date: 3/13/17
// FindComponents.c
// This program will find strongly connected components ina graph using DFS
// ----------------------------------------------------------------
#include "Graph.h"
#define MAX_LEN 160
int main(int argc, char** argv) {
    // check command line for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *c = malloc(MAX_LEN);
    int n=0;    // graph vertex size
    int v=0;    // vertex
    int e=0;    // edge

    List S = newList();
    FILE *in, *out;
    // open files for reading and writing
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    if( in==NULL ){
        printf("Unable to open file %s for reading\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if( out==NULL ){
        printf("Unable to open file %s for writing\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    // open files for reading and writing
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    fgets(c,MAX_LEN,in); // gets vertices size
    sscanf(c,"%i",&n);   // converts char to int
    Graph G = newGraph(n);
    while(fgets(c,MAX_LEN,in)!=NULL)
    {
        sscanf(c,"%i %i",&v,&e);
        if(v!=0 && e !=0)
        {
            addArc(G,v,e);
        }
    }
    // adding vertices to the so called stack
    for(int i=1;i<=n;i++)
    {
        append(S,i);
    }
    // finding the connected components
    DFS(G,S);
    Graph T = transpose(G);
    DFS(T,S);
    // find number of vertices with parent of nil
    int cc=0; // number of connected components
    moveFront(S);
    while(index(S)!=-1)
    {
        if(getParent(T,get(S)) == NIL)
        {
            cc++;
        }
        moveNext(S);
    }
    List* SCC = malloc(sizeof(List)*(cc+1)); // strongly connected components
    for(int i =1;i<cc+1;i++)
    {
        SCC[i] = newList();
    }
    // adding strongly connected components vertices to the new stack
    int i =1; // SCC index
    moveBack(S);
    while(index(S)!=-1)
    {
        if(getParent(T,get(S)) != NIL)
        {
            prepend(SCC[i],get(S));
        }
        else
        {
            prepend(SCC[i],get(S));
            i++; // go the next list
        }

        movePrev(S);
    }
    fprintf(out,"Adjacency list representation of G:\n");
    printGraph(out,G);
    fprintf(out,"\n");
    fprintf(out,"G contains %i strongly connected components:\n",cc);
    for(int i=1;i<cc+1;i++)
    {
        fprintf(out,"Component %i:",i);
        printList(out,SCC[i]);
        fprintf(out,"\n");
    }
    freeGraph(&G);
    freeList(&S);
    free(c);
    fclose(in);
    fclose(out);
    return (EXIT_SUCCESS);
}
