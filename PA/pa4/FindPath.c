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
    int line_num =0;
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
    while (fgets(c,MAX_LEN,in)!=NULL)
    {
        line_num++;
    }
    fclose(in);
    fclose(out);
    // open files for reading and writing
    in = fopen(argv[1], "r");
    out = fopen(argv[2], "w");
    fgets(c,MAX_LEN,in);
    sscanf(c,"%i",&n);
    Graph g = newGraph(n);
    int i=0;//just not to print the last \n I had to do this annoying stuff
    while(fgets(c,MAX_LEN,in)!=NULL)
    {
        i++;
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
            if(getDist(g,e)!=INF)
            {
                fprintf(out,"The distance from %i to %i is %i\n",v,e,getDist(g,e));
                fprintf(out,"A shortest %i-%i path is: ",v,e);
                getPath(l,g,e);
                printList(out,l);
            }
            else
            {
                fprintf(out,"The distance from %i to %i is infinity\n",v,e);
                fprintf(out,"No %i-%i path exists",v,e);
            }
            fprintf(out,"\n");
            if(i != line_num-2) // i cant belive just not to print the last \n i had to add bunch of line of code
            {
                fprintf(out,"\n");
            }
            clear(l);
        }
    }
    fclose(in);
    fclose(out);
    return (EXIT_SUCCESS);
}
