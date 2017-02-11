// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa3
// Due date: 2/11/17
// Sparse.java
// This program will read and make nxn matrix and fill the rows and column, then it will do some mathematical operation then output it to a output file.
// ----------------------------------------------------------------
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;
public class Sparse {

	public static void main(String[] args) throws IOException {
                if(args.length < 2)
                    {
                        System.err.println("Usage: FileIO infile outfile");
                        System.exit(1);
                    }

		File file = new File(args[0]);
               	Scanner in =  new Scanner(file);
                PrintWriter out = new PrintWriter(new FileWriter(args[1]));
		int n,a,b;
		n = Integer.parseInt(in.next());
		a = Integer.parseInt(in.next());
		b = Integer.parseInt(in.next());
		//System.out.println("s: "+in.next());
		Matrix A = new Matrix(n);
		Matrix B = new Matrix(n);
		int i =0;// counting the number lines required for each matrix
		while(in.hasNextLine())
		{
			if(i < a)
			{
				i++;
				A.changeEntry(Integer.parseInt(in.next()),Integer.parseInt(in.next()),Double.parseDouble(in.next()));
			}	
			else if(i-a < b)
			{
				i++;
				B.changeEntry(Integer.parseInt(in.next()),Integer.parseInt(in.next()),Double.parseDouble(in.next()));
			}
			else
			{
				in.nextLine();
			}
		}
		in.close();
		out.println("A has "+A.getNNZ()+" non-zero entries:\n"+A);
		out.println("B has "+B.getNNZ()+" non-zero entries:\n"+B);
		out.println("(1.5)*A =\n"+A.scalarMult(1.5));
		out.println("A+B =\n"+A.add(B));
		out.println("A+A =\n"+A.add(A));
		out.println("B-A =\n"+B.sub(A));
		out.println("A-A =\n"+A.sub(A));
		out.println("Transpose(A) =\n"+A.transpose());
		out.println("A*B =\n"+A.mult(B));
		out.println("B*B =\n"+B.mult(B));
                out.close();
		
	}

}
