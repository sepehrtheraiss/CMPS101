// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa1
// 1/21/17
// Lex.java
// This program will read a set of strings and store it into an array,
// the function insertion_sort will use a modified veriosn of insertion_sort using ADT to make it more efficient.
// The List will contain the sorted indicies of the string and using the indicies it will insert the sorted string into an output file.
// ----------------------------------------------------------------
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lex {
        // insertion_sort()
        // pre:none
        // 1.we append the first indicie which is sorted namely j
        // 2. if j+1 is bigger than j then we simply append j+1
        // 3. if j+1 is smaller we loop j-1 times and move the cursor back starting from j,
        // once the j-1th element is not smaller we insert in the indicie after it.(yes I said we, cuz me and my computer are a team)
        // 4.since the cursor is moving with the loop, if it goes out of bond (-1) we simply prepend the indicie,
        // becuase it wasn't smaller than any of the previous sorted indicies.
        public static void insertion_sort(String[] A,List list)
        {
                //Scanner keyboard = new Scanner(System.in);
                int in;
                int i;
                String temp;
                list.append(0);
                for(int j=1;j<A.length;j++)
                {
                //      keyboard.nextInt();
                        temp = A[j];
                        i = j-1;
                        if(temp.compareTo(A[list.back()]) > 0)
                        {                               
                                //System.out.println("i: "+i+" "+temp+" "+A[i]);
                                list.append(j);
                        }
                        else
                        {
                                list.moveBack();
                                // stop once A[i] is not less than temp so we can add after the element that is not smaller than temp
                                while(i >=0 && temp.compareTo(A[list.get()])<=0)
                                {
                                        list.movePrev();
                                        i--;
                                }
                                if(list.index() != -1)
                                {
                                        list.insertAfter(j);
                                }
                                // index out of bond
                                else
                                {
                                        list.prepend(j);
                                }
                        }
                }// end for

        }
        public static void main(String[] args)throws IOException{
              if(args.length < 2){
                  System.err.println("Usage: FileIO infile outfile");
                  System.exit(1);
               }
              Scanner in = new Scanner(new File(args[0])); 
              PrintWriter out = new PrintWriter(new FileWriter(args[1]));
              List list = new List();
              int line_number=0;
                  while(in.hasNextLine())
                  {
                          in.nextLine();
                          line_number++;
                  }
                  in.close();
                  
                  String[] str = new String[line_number];
                  in = new Scanner(new File(args[0]));
                  int i=0;
                  while(in.hasNextLine())
                  {
                          str[i]= in.nextLine();
                          i++;
                  }
                  insertion_sort(str,list);
              in.close();
              list.moveFront();
              while(list.index() != -1)
              {
                        out.println(str[list.get()]);
                        list.moveNext();
              }
              out.close();
                
        }
}
