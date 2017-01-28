#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
void insertion_sort(char** A,List l,int cCount)
{
    int in;
    int i;
    char* temp;
    append(l,0);
    for(int j=1;j<cCount;j++)
    {
        temp = &A[j];
        i = j-1;
        if(strcmp(temp,&A[back(l)]) > 0)
        {
            append(l,j);
        }
        else
        {
            moveBack(l);
            // stop once A[i] is not less than temp so we can add after the element that is not smaller than temp
            while(i >=0 && strcmp(temp,&A[get(l)])<=0)
            {
                movePrev(l);
                i--;
            }
            if(index(l) != -1)
            {
                insertAfter(l,j);
            }
                // index out of bond
            else
            {
                prepend(l,j);
            }
        }

    }// end for

}
int main(int argc, char** argv)
{

    int cCount=0;//character count
    char** str;
    FILE *in, *out;

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
    while(fgetc(in)!=EOF){cCount++;}
    /* close files */
    fclose(in);
    fclose(out);
    return EXIT_SUCCESS;
}
