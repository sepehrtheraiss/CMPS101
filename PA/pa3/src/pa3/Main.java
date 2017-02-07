package pa3;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws FileNotFoundException {

		File file = new File("/Users/sepehr/Desktop/in1");
		Scanner in =  new Scanner(file);
		int n,a,b;
		n = Integer.parseInt(in.next());
		a = Integer.parseInt(in.next());
		b = Integer.parseInt(in.next());
		Matrix A = new Matrix(n);
		Matrix B = new Matrix(n);
		//System.out.println();
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
			
	}

}
