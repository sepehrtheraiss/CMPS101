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
		public boolean equal(Entry e)
		{
			if(this.column == e.column && this.value == e.value)
			{
				return true;
			}
			else
			{
				return false;
			}
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
					if(L[i].length() != 0 && B.L[i].length() != 0)
					{
						Entry e1 = (Entry)L[i].get();
						Entry e2 = (Entry)B.L[i].get();
						while(B.L[i].index() != -1 && L[i].index() != -1)
						{
							if(e1.equal(e2))
							{
								L[i].moveNext();
								B.L[i].moveNext();	
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
						}// end while
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
		
		if(L[i-1].length() ==0 && x != 0)
		{
			L[i-1].append(new Entry(j,x));
			NNZ++;
		}
		else
		{
			L[i-1].moveBack();
			while(L[i-1].index() != -1 && ((Entry)L[i-1].get()).column > j)
			{
				L[i-1].movePrev();
			}
			if(L[i-1].index() == -1)
			{
				L[i-1].prepend(new Entry(j,x));
				NNZ++;
			}
			else if(((Entry)L[i-1].get()).column == j)
			{
				L[i-1].insertAfter(new Entry(j,x));
				L[i-1].delete();
			}
			else
			{
				NNZ++;
				L[i-1].insertAfter(new Entry(j,x));
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
		boolean NNZE1;
		boolean NNZE2;
		Entry e1=null;
		Entry e2=null;
		for(int i =0;i<size;i++)
		{
			L[i].moveFront();
			M.L[i].moveFront();
			NNZE1=true;
			NNZE2=true;
			while(NNZE1 || NNZE2)// it will only exit when both list reach index of -1
			{
				if(L[i].index() != -1) {e1 =(Entry) L[i].get();NNZE1 = true;}
				else{NNZE1 = false;}
				
				if(M.L[i].index() != -1){e2 =(Entry) M.L[i].get();NNZE2 = true;}
				else{NNZE2 = false;}
				
				if(NNZE1 && NNZE2)
				{
					if(e1.column == e2.column)
					{
						n.changeEntry(i+1, e1.column, e1.value + e2.value);
						L[i].moveNext();
						if(!equal)
						{
							M.L[i].moveNext();
						}
					}
					else if(e1.column > e2.column) // e2 is the smaller column, meaning e1 had a zero entry
					{
						n.changeEntry(i+1, e2.column, e2.value);
						M.L[i].moveNext();
					}
					else if(e1.column < e2.column) // e1 is the smaller column, meaning e2 had a zero entry
					{
						n.changeEntry(i+1, e1.column, e1.value);
						L[i].moveNext();
					}
				}// end if
				else if(NNZE1)
				{
					n.changeEntry(i+1,e1.column,e1.value);
					L[i].moveNext();
				}
				else if(NNZE2)
				{
					n.changeEntry(i+1, e2.column, e2.value);
					M.L[i].moveNext();
				}
			}// end while
		}
		return n;
	}
	// pre: getSize()==M.getSize()
	// returns a new Matrix that is the difference of this Matrix with M
	Matrix sub(Matrix M)
	{
		Matrix n = new Matrix(size);
		boolean equal = this.equals(M);
		boolean NNZE1;
		boolean NNZE2;
		Entry e1=null;
		Entry e2=null;
		double value;
		for(int i =0;i<size;i++)
		{
			L[i].moveFront();
			M.L[i].moveFront();
			NNZE1=true;
			NNZE2=true;
			while(NNZE1 || NNZE2)// it will only exit when both list reach index of -1
			{
				if(L[i].index() != -1) {e1 =(Entry) L[i].get();NNZE1 = true;}
				else{NNZE1 = false;}
				
				if(M.L[i].index() != -1){e2 =(Entry) M.L[i].get();NNZE2 = true;}
				else{NNZE2 = false;}
				
				if(NNZE1 && NNZE2)
				{
					if(e1.column == e2.column)
					{
						value = e1.value - e2.value;
						if(value != 0)
						{
							n.changeEntry(i+1, e1.column, value);
						}
						L[i].moveNext();
						if(!equal)
						{
							M.L[i].moveNext();
						}
					}
					else if(e1.column > e2.column) // e2 is the smaller column, meaning e1 had a zero entry
					{
						n.changeEntry(i+1, e2.column, e2.value*-1);
						M.L[i].moveNext();
					}
					else if(e1.column < e2.column) // e1 is the smaller column, meaning e2 had a zero entry
					{
						n.changeEntry(i+1, e1.column, e1.value);
						L[i].moveNext();
					}
				}// end if
				else if(NNZE1)
				{
					n.changeEntry(i+1,e1.column,e1.value);
					L[i].moveNext();
				}
				else if(NNZE2)
				{
					n.changeEntry(i+1, e2.column, e2.value*-1);
					M.L[i].moveNext();
				}
			}// end while
		}
		return n;
	}
	// returns a new Matrix that is the transpose of this Matrix
	Matrix transpose()
	{
		Matrix n = new Matrix(size);
		Entry e = null;
		int j=0;
		for(int i=0;i<size;i++)
		{
			L[i].moveFront();
			while(L[i].index() != -1)
			{
				if(j+1 ==((Entry)L[i].get()).column)
				{
					n.changeEntry(j+1, i+1, ((Entry)L[i].get()).value);
					L[i].moveNext();
				}
				j++;
			}
			j=0;
			
		}
		return n;
	}
	// pre: getSize()==M.getSize()
	// returns a new Matrix that is the product of this Matrix with M
	Matrix mult(Matrix M)
	{
		Matrix n = new Matrix(size);
		M = M.transpose();
		double value = 0.0;
		for(int i =0;i<size;i++)
		{
			for(int j=0;j<size;j++)
			{
				value = dot(L[i],M.L[j]);
				if(value != 0)
				{
					n.changeEntry(i+1, j+1,value);
				}
			}
		}
		return n;
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
			if(L[i].length() != 0)
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
		}
		return buff.toString();
	}
	private double dot(List P, List Q)
	{
		double value = 0.0;
		P.moveFront();
		Q.moveFront();
		
		while(P.index() != -1 && Q.index() != -1)
		{
			if(((Entry)P.get()).column >((Entry)Q.get()).column) // P had a zero entry
			{
				Q.moveNext(); // since it has to be multiplied by a zero we can just ignore adding the number
			}
			else if(((Entry)P.get()).column <((Entry)Q.get()).column)// Q had a zero entry
			{
				P.moveNext();
			}
			else
			{
				value += ((Entry)P.get()).value * ((Entry)Q.get()).value;
				P.moveNext();
				Q.moveNext();
			}
		}//end while

		return value;
	}
	
}
