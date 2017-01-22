import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Lex {
	public static void insertion_sort(String[] A,List list)
	{
		//Scanner keyboard = new Scanner(System.in);
		int in;
		int i;
		String temp;
		list.append(0);
		for(int j=1;j<A.length;j++)
		{
		//	keyboard.nextInt();
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
//			list.moveFront();
//			while(list.index() != -1)
//			{
//				System.out.print(A[list.get()]+" ");
//				list.moveNext();
//			}
//			System.out.println();
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
