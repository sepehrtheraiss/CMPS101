// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa4
// Due date: 3/1/17
// FindPath.c
// This program will find the shortest path to the given destination from source in a graph representation
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
    int flag = 0;// when to switch to bfs mode
    List l = newList();
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
    fgets(c,MAX_LEN,in);
    sscanf(c,"%i",&n);
    Graph g = newGraph(n);
    while(fgets(c,MAX_LEN,in)!=NULL)
    {
        sscanf(c,"%i %i",&v,&e);
        if(flag != 1 && v!=0 && e !=0)
        {
            addEdge(g,v,e);
        }
        else if(flag != 1)
        {
            flag =1;
            printGraph(out,g);
            fprintf(out,"\n");
        }
        if(flag == 1&& v!=0 && e!=0)
        {
            BFS(g,v);
            fprintf(out,"The distance from %i to %i is %i\n",v,e,getDist(g,e));
            fprintf(out,"A shortest %i-%i path is: ",v,e);
            getPath(l,g,e);
            printList(out,l);
            fprintf(out,"\n");
            clear(l);
        }
    }
    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
}
