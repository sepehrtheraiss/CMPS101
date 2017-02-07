package pa3;

public class Matrix {
	// ENRTY ************************************************
	private class Entry
	{
		private int column;
		private double value;
		public Entry(int column,double value)
		{
			this.column = column;
			this.value = value;
		}
		public String toString()
		{
			return "";
		}
		public boolean equals()
		{
			return true;
		}
	}// end of class Entry
	//*************************************************************
	// DATA FIELDS ************************************************
	List L[]; // Array of list, each list defines a row
	int n;//size of the Matrix
	int NNZ; // number of none-zero entries
	//*************************************************************
	// Constructor ************************************************
	//pre: n>=1
	// Makes a new n x n zero Matrix. 
	Matrix(int n) throws RuntimeException
	{
		if(n < 1)
		{
			throw new RuntimeException("Matrix size < 1");
		}
		
		L = new List[n];
		for(int i =0;i<n;i++)
		{
			L[i] = new List();
		}
		this.n = n;
	}	
	//*************************************************************	
	// Access functions ************************************************
	
	// Returns n, the number of rows and columns of this Matrix
	int getSize()
	{
		return this.n;
	}
	// Returns the number of non-zero entries in this Matrix
	int getNNZ()
	{
		return this.NNZ;
		
	}
	// overrides Object's equals() method
	public boolean equals(Object x)
	{
		return true;
	}
	//**********************************************************************
	// Manipulation procedures ************************************************
	
	// sets this Matrix to the zero state
	void makeZero()
	{
		for(int i =0;i<getSize();i++)
		{
			L[0].clear();
		}
		NNZ = n = 0;
	}
	// returns a new Matrix having the same entries as this Matrix
	Matrix copy()
	{
		Matrix copy = new Matrix(1);
		return copy;
	}
	// changeEntry()
	// pre: 1<=i<=getSize(), 1<=j<=getSize()
	// changes ith row, jth column of this Matrix to x
	void changeEntry(int i, int j, double x) throws RuntimeException
	{
		if(i > getSize())
		{
			throw new RuntimeException("Size of matrix < i");
		}
		if(i < 1)
		{
			throw new RuntimeException("i < 1");
		}
		if( j > getSize())
		{
			throw new RuntimeException("Size of matrix < j ");
		}
		if(j < 1)
		{
			throw new RuntimeException("j < 1");
		}
		L[i-1].append(new Entry(j,x));
	}

	// returns a new Matrix that is the scalar product of this Matrix with x
	Matrix scalarMult(double x)
	{
		return new Matrix(1);
	}
	
	// pre: getSize()==M.getSize()
	// returns a new Matrix that is the sum of this Matrix with M
	Matrix add(Matrix M)
	{
		return new Matrix(1);
	}
	// pre: getSize()==M.getSize()
	// returns a new Matrix that is the difference of this Matrix with M
	Matrix sub(Matrix M)
	{
		return new Matrix(1);
	}
	// returns a new Matrix that is the transpose of this Matrix
	Matrix transpose()
	{
		return new Matrix(1);
	}
	// pre: getSize()==M.getSize()
	// returns a new Matrix that is the product of this Matrix with M
	Matrix mult(Matrix M)
	{
		return new Matrix(1);
	}	
	//****************************************************************************
	// Other functions
	// overrides Object's toString() method
	public String toString() 
	{
		return "";
	}
	
}
