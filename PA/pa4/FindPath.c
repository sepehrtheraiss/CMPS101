// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa4
// Due date: 3/1/17
// FindPath.c
// This program will find the shortest path to the given destination from source in a graph representation
// ----------------------------------------------------------------
#include "Graph.h"
int main(int argc, char** argv) {
    // check command line for correct number of arguments
    if (argc != 3) {
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int line_count=0;//line count
    int n=0;    // graph vertex size
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
    /*reading number of characters and lines*/
    char c;
    while((c=fgetc(in))&& c!=EOF)
    {
        if(c=='\n')
        {
            line_count++;
        }
    }
    fclose(in);//to free the memory it was pointed to
    in = fopen(argv[1], "r");//because the cursor needs to start from the beginning
    n = getc(in);
    fclose(in);
    printf("n: \n",n);
    return EXIT_SUCCESS;
}