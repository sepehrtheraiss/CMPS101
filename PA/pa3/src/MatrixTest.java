// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa3
// Due date: 2/11/17
// MatrixTest.java
// ----------------------------------------------------------------
public class MatrixTest {
	public static void main(String args[])
	{
		Matrix A = new Matrix(2);
		Matrix B = new Matrix(3);
		A.changeEntry(1, 1, 1);
		A.changeEntry(1, 2, 2);
		A.changeEntry(2, 1, 3);
		A.changeEntry(2, 2, 4);
		B.changeEntry(1, 1, 1);
		B.changeEntry(1, 2, 2);
		B.changeEntry(1, 3, 3);
		B.changeEntry(2, 1, 4);
		B.changeEntry(2, 2, 5);
		B.changeEntry(2, 3, 6);
		B.changeEntry(3, 1, 7);
		B.changeEntry(3, 2, 8);
		B.changeEntry(3, 3, 9);
		System.out.println(A.add(B));
//		//Matrix A = new Matrix(0);
//		Matrix A = new Matrix(1);
//		System.out.println(A.getNNZ());
//		//A.changeEntry(0, 0, 1);
//		//A.changeEntry(1, 1, 1);
//		//A.changeEntry(1, 2, 1);
//		A.changeEntry(1, 1, 0);
//		System.out.println(A.getNNZ());
//		System.out.println(A);
//		A.changeEntry(1, 1, 2);
//		System.out.println(A.getNNZ());
//		System.out.println(A);
//		Matrix B = new Matrix(2);
//		B = A.copy();
//		System.out.println(B);
//		B = new Matrix(2);
//		//System.out.println(B.add(A));
//		B.changeEntry(1, 1, 1);
//		B.changeEntry(1, 2, 2);
//		//System.out.println(B.add(A));
//		B.changeEntry(2, 1, 3);
//		System.out.println("B scalar\n"+B.scalarMult(0));
//		System.out.println("B scalar\n"+B.scalarMult(2));
//		System.out.println("B scalar\n"+B.transpose());
//		B.changeEntry(2, 2, 4);
//		System.out.println(B.getNNZ());
//		System.out.println("B=\n"+B);
//		A = B.copy();
//		System.out.println("A=\n"+A);
//		System.out.println("B=\n"+B);
//		System.out.println(B.add(A));
//		System.out.println(A.sub(B));
//		System.out.println(A.sub(A));
//		Matrix C = new Matrix(2);
//		C.changeEntry(1, 1, 3);
//		System.out.println("A-c=\n"+A.sub(C));
//		A = C.copy();
//		System.out.println("A==C\n"+A.equals(C));
//		System.out.println("A==B\n"+A.equals(B));
//		System.out.println("A==A\n"+A.equals(A));
//		System.out.println("A-C\n"+A.sub(C));
//		System.out.println("C-C\n"+C.sub(C));
//		System.out.println("A*C\n"+A.mult(C));
//		C.makeZero();
////		System.out.println(C);
//		System.out.println(C.getNNZ());
//		B.makeZero();
//		System.out.println("B==C\n"+B.equals(C));
//		C.changeEntry(1, 1, 1);
//		B.changeEntry(1, 1, 1);
//		System.out.println(C.equals(B));		
	}
}
