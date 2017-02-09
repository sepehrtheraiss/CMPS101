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
	         return new String("("+column+","+value+")");
		}
		public boolean equals()
		{
			return true;
		}
	}// end of class Entry
	//*************************************************************
	// DATA FIELDS ************************************************
	List L[]; // Array of list, each list defines a row
	int size;//size of the Matrix rows and columns
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
		size = n;
		NNZ = 0;
	}	
	//*************************************************************	
	// Access functions ************************************************
	
	// Returns size, the number of rows and columns of this Matrix
	int getSize()
	{
		return size;
	}
	// Returns the number of non-zero entries in this Matrix
	int getNNZ()
	{
		return NNZ;	
	}
	// overrides Object's equals() method
	public boolean equals(Object x)
	{
		if(x instanceof Matrix)
		{
			Matrix B = (Matrix)x;
			if(B.size != this.size)
			{
				return false;
			}
			else
			{
				for(int i =0;i<size;i++)
				{
					B.L[i].moveFront();
					L[i].moveFront();
					Entry e1 = (Entry)L[i].get();
					Entry e2 = (Entry)B.L[i].get();
					while(B.L[i].index() != -1 && L[i].index() != -1)
					{
						if(e1.column == e2.column)
						{
							if(e1.value == e2.value)
							{
								L[i].moveNext();
								B.L[i].moveNext();
							}
							else
							{
								return false;
							}
						}
						else
						{
							return false;
						}
						if(L[i].index() != -1 )
						{
							e1 = (Entry) L[i].get();
						}
						if(B.L[i].index() != -1)
						{
							e2 = (Entry) B.L[i].get();
						}	
					}
				}
				return true;
			}
		}
		else
		{
			return false;
		}
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
		NNZ = size = 0;
	}
	// returns a new Matrix having the same entries as this Matrix
	Matrix copy()
	{
		Matrix copy = new Matrix(size);
		for(int i=0;i<size;i++)
		{
			L[i].moveFront();
			while(L[i].index() != -1)
			{
				Entry e = (Entry)L[i].get();
				copy.changeEntry(i+1, e.column, e.value);
				L[i].moveNext();
			}
		}
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
		// row i-1 is empty 
		if(L[i-1].length() == 0 && x != 0)
		{
			L[i-1].append(new Entry(j,x));
			NNZ++;
		}
		// insert into the correct column
		else
		{
			L[i-1].moveFront();
			Entry e = new Entry(j,x);
			Entry t = null;
			// gets each element and inserts at the correct position
			while(L[i-1].index() != -1)
			{
				t = (Entry) L[i-1].get();
				if(j > t.column)
				{
					L[i-1].moveNext();
				}
				else if(j == t.column) // for replacement of entry 
				{
					L[i-1].insertAfter(e);
					L[i-1].delete();
				}
				else
				{
					L[i-1].insertAfter(e);
				}
				if(L[i-1].index() == -1)
				{
					L[i-1].append(e);
				}
			}
		}
	}

	// returns a new Matrix that is the scalar product of this Matrix with x
	Matrix scalarMult(double x)
	{
		Matrix m = new Matrix(size);
		for(int i =0;i<size;i++)
		{
			L[i].moveFront();
			while(L[i].index() != -1)
			{
				Entry e = (Entry)L[i].get();
				m.changeEntry(i+1, e.column, e.value*x);
				L[i].moveNext();
			}
		}
		return m;
	}
	
	// pre: getSize()==M.getSize()
	// returns a new Matrix that is the sum of this Matrix with M
	Matrix add(Matrix M)
	{
		Matrix n = new Matrix(size);
		boolean equal = this.equals(M);
		for(int i =0;i<size;i++)
		{
			L[i].moveFront();  // e1
			M.L[i].moveFront(); // e2
			Entry e1 = (Entry) L[i].get();
			Entry e2 = (Entry) M.L[i].get();
			while(M.L[i].index() != -1 && L[i].index() != -1)
			{
				if(e1.column == e2.column) // if the same column 
				{
					//System.out.println("e1: "+e1.column+":"+e1.value);
					//System.out.println("e2: "+e1.column+":"+e2.value);
					n.changeEntry(i+1, e1.column, e1.value + e2.value);
					if(!equal)// because if so it uses the same reference
					{
						M.L[i].moveNext();
					}
					L[i].moveNext();
				}
				else if(e1.column > e2.column) // e1.column has a zero entry
				{
					//System.out.println("else e2: "+e2.column+":"+e2.value);
					n.changeEntry(i+1, e2.column, e2.value);
					M.L[i].moveNext();
				}
				else if (e1.column < e2.column) // e2.column has a zero entry
				{
					//System.out.println("else e1: "+e1.column+":"+e1.value);
					n.changeEntry(i+1, e1.column, e1.value);
					L[i].moveNext();
				}
				if(L[i].index() != -1 )
				{
					e1 = (Entry) L[i].get();
				}
				if(M.L[i].index() != -1)
				{
					e2 = (Entry) M.L[i].get();
				}
			}//end while
			// last entry that doesn't get added because the loop exits when one of them hits -1
			if(L[i].index() != -1)
			{
				n.changeEntry(i+1, e1.column, e1.value);
			}
			else if(M.L[i].index() != -1)
			{
				n.changeEntry(i+1, e2.column, e2.value);
			}
		}
		return n;
	}
	// pre: getSize()==M.getSize()
	// returns a new Matrix that is the difference of this Matrix with M
	Matrix sub(Matrix M)
	{
		Matrix n = new Matrix(size);
		boolean equal = this.equals(M);
		for(int i =0;i<size;i++)
		{
			L[i].moveFront();  // e1
			M.L[i].moveFront(); // e2
			Entry e1 = (Entry) L[i].get();
			Entry e2 = (Entry) M.L[i].get();
			while(M.L[i].index() != -1 && L[i].index() != -1)
			{
				if(e1.column == e2.column) // if the same column 
				{
					n.changeEntry(i+1, e1.column, e1.value - e2.value);
					if(!equal)// because if so it uses the same reference
					{
						M.L[i].moveNext();
					}
					L[i].moveNext();
				}
				else if(e1.column > e2.column) // e1.column has a zero entry
				{
					n.changeEntry(i+1, e2.column, e2.value*-1);
					M.L[i].moveNext();
				}
				else if (e1.column < e2.column) // e2.column has a zero entry
				{
					n.changeEntry(i+1, e1.column, e1.value*-1);
					L[i].moveNext();
				}
				if(L[i].index() != -1 )
				{
					e1 = (Entry) L[i].get();
				}
				if(M.L[i].index() != -1)
				{
					e2 = (Entry) M.L[i].get();
				}
			}//end while
			// last entry that doesn't get added because the loop exits when one of them hits -1
			if(L[i].index() != -1)
			{
				n.changeEntry(i+1, e1.column, e1.value);
			}
			else if(M.L[i].index() != -1)
			{
				n.changeEntry(i+1, e2.column, e2.value);
			}
		}
		return n;
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
		StringBuffer buff = new StringBuffer();
		Entry e = null;
		if(NNZ == 0)
		{
			return "";
		}
		for(int i =0;i<size;i++)
		{
			buff.append(i+1+":");
			L[i].moveFront();
			while(L[i].index() != -1)
			{
				e = (Entry)L[i].get();
				buff.append(" "+e.toString());
				L[i].moveNext();
			}
			buff.append("\n");
		}
		return buff.toString();
	}
	
}
