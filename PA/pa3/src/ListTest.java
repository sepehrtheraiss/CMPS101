// ---------------------------------------------------------------
// Sepehr Raissian
// Sraissia@ucsc.edu
// CMPS101 pa3
// Due date: 2/11/17
// ListTest.java
// ----------------------------------------------------------------
public class ListTest {
	public static void main(String args[])
	{
		List A = new List();
		System.out.println(A.index());
		//System.out.println(A.get());
		for(int i =0;i<5;i++)
		{
			A.append(i);
		}
		System.out.println(A);
		List B = new List();
		System.out.println(A.equals(B));
		System.out.println(A.length());
		System.out.println(B.length());
		//A.insertAfter(10);
		A.moveBack();
		A.insertBefore(10);
		System.out.println(A);
		A.append(2);
		A.prepend(2);
		System.out.println(A);
		A.deleteBack();
		System.out.println(A);
		A.clear();
		System.out.println(A);
		A.append(1);
		A.append(1);
		System.out.println(A);
		//A.delete();
		A.moveBack();
		A.delete();
		System.out.println(A);
	}
}
