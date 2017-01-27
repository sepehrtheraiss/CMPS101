#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#define MAX_LEN 160
int main(int argc, char** argv)
{

    int n, cCount=0;//character count
    FILE *in, *out;
    char line[MAX_LEN];
    char tokenlist[MAX_LEN];
    char* token;

    // check command line for correct number of arguments
    if( argc != 3 ){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

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

    int c ;
    while((c=fgetc(in)))
    {
        cCount++;
    }
    printf("c count: %i\n",cCount);

    /* close files */
    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
}