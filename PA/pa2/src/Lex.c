// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa2
// 1/28/17
// Lex.c
// This program will read a set of strings and store it into an array,
// the function insertion_sort will use a modified veriosn of insertion_sort using ADT to make it more efficient.
// The List will contain the sorted indicies of the string and using the indicies it will insert the sorted string into an output file.
// ----------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
// insertion_sort()
// pre:none
// 1.we append the first indicie which is sorted namely j
// 2. if j+1 is bigger than j then we simply append j+1
// 3. if j+1 is smaller we loop j-1 times and move the cursor back starting from j,
// once the j-1th element is not smaller we insert in the indicie after it.(yes I said we, cuz me and my computer are a team)
// 4.since the cursor is moving with the loop, if it goes out of bond (-1) we simply prepend the indicie,
// becuase it wasn't smaller than any of the previous sorted indicies.
void insertion_sort(char** A,List l,int lineNum)
{
    int i;
    char* temp;
    append(l,0);
    for(int j=1;j<lineNum;j++)
    {
        temp = A[j];
        i = j-1;
        if(strcmp(temp,A[back(l)]) > 0)
        {
            append(l,j);
        }
        else
        {
            moveBack(l);
            // stop once A[i] is not less than temp so we can add after the element that is not smaller than temp
            while(i >=0 && strcmp(temp,A[get(l)])<=0)
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
    // check command line for correct number of arguments
    if( argc != 3 ){
        printf("Usage: %s <input file> <output file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    List l = newList();
    int line_count=0;//line count
    int cCount=0;//character count
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
        else
        {
            cCount++;
        }
    }    

    fclose(in);//to free the memory it was pointed to
    in = fopen(argv[1], "r");//because the cursor needs to start from the beginning
    /*constructing string array*/
    char* str[line_count];
    for(int a=0;a<line_count;a++)
    {
        str[a]=malloc(cCount);
    }
    /*reading from the file as a string*/
    int i =0;
    char temp[cCount];
    while(fgets(temp,cCount*2,in)!=NULL)
    {
        strcpy(str[i],temp);
        i++;
    }
    /*sorting then printing it to out file*/
    insertion_sort(str,l,line_count);
    moveFront(l);
    while(index(l)!=-1)
    {
        fprintf(out,"%s",str[get(l)]);
        moveNext(l);
    }
    /* close files */
    fclose(in);
    fclose(out);
    /*freeing memories*/
    for(int a=0;a<line_count;a++)
    {
        free(str[a]);
        str[a]=NULL;
    }
    freeList(&l);
return EXIT_SUCCESS;
}
