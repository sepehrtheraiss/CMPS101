package pa3;


import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {

		File file = new File("/Users/sepehr/Desktop/in2");
		Scanner in =  new Scanner(file);
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
				//System.out.println(i);
				A.changeEntry(Integer.parseInt(in.next()),Integer.parseInt(in.next()),Double.parseDouble(in.next()));
			}	
			else if(i-a < b)
			{
				i++;
				B.changeEntry(Integer.parseInt(in.next()),Integer.parseInt(in.next()),Double.parseDouble(in.next()));
			}
			else
			{
				System.out.println("last");
				in.nextLine();
			}
		}
		in.close();
		System.out.println("A:\n"+A);
		System.out.println("B:\n"+B);
		System.out.println(A.equals(A));
		System.out.println("A+B=\n"+A.add(B));
		System.out.println("A+A=\n"+A.add(A));
		System.out.println("B-A=\n"+B.sub(A));
//		System.out.println("A-A\n"+A.sub(A));
//		System.out.println("Transpose(A)\n"+A.transpose());
//		System.out.println("A*B =\n"+A.mult(B));
//		System.out.println("B*B =\n"+B.mult(B));
		
	}

}
