package pa3;


public class List{
	private class Node
	{
		// private inner Node class
		Object data;
		Node next;
		Node prev;
		Node(Object data)
		{
			this.data = data;
			next = prev = null;
		}
	}
	// Fields for the List class
		private Node head; // points to the front of the list
		private Node tail; // points to the back of the list
		private Node cursor; // it will point to a specific index of an element 
		private int index;   // index of the cursor
		private int numItems; // stores number of the nodes
	// List()	
	// Create a new empty list.
	List()
	{
		head = tail = cursor = null;
		numItems = 0;
		index=-1;
	} 

	// Access functions
	//------------------------------------------------
	// length() 
	// pre: none
	// Returns the number of elements in this List.
	int length() 
	{
		return numItems;
	}
	
	// index()
	// pre:none
	// If cursor is defined, returns the index of the cursor element,
    // otherwise returns -1.
	int index() 
	{
		if(cursor!=null)
		{
			return index;
		}
		else
		{
			return -1;
		}
	}
	// front()
	// Pre: length()>0
	// Returns front element.
	Object front() throws RuntimeException
	{
		if(length()>0)
		{
			return head.data;
		}
		else
		{
			throw new RuntimeException("length() <= 0");
		}
	}
	// back()
	// Pre: length()>0
	// Returns back element. 
	Object back() throws RuntimeException
	{
		if(length()>0)
		{
			return tail.data;
		}
		else
		{
			throw new RuntimeException("length() <= 0");
		}
	}
	// get()
	// Pre: length()>0, index()>=0
	// Returns cursor element.
	Object get() throws RuntimeException
	{
		if(length()<=0)
		{
			throw new RuntimeException("length() <= 0");
		}
		if(index()<0)
		{
			throw new RuntimeException("index < 0");
		}
		
		return cursor.data;
	}
	// equals()
	// Returns true if this List and L are the same integer
    // sequence. The cursor is ignored in both lists.
    // Manipulation procedures
	public boolean equals(Object x)
	{
		List L = null;
		if(x instanceof List)
		{
			L = (List)x;
			if(this.length() != L.length())
			{
				return false;
			}
			else
			{
				Node r = head;
				Node l = L.head;
				boolean flag = true;
				while(r != null && flag)// since its already checked for same length, it doesn't matter which Node pointer I use 
				{
					if(r.data == l.data)
					{
						r = r.next;
						l = l.next;
					}
					else
					{
						flag = false;
					}
				}
				return flag;
			}
		}
		else
		{
			return false;
		}
	}
	// clear()
	// Resets this List to its original empty state.
	void clear()
	{
		head = tail = cursor = null;
		numItems=0;
	}
	// moveFront()
	// If List is non-empty, places the cursor under the front element,
    // otherwise does nothing.
	void moveFront()
	{
		if(this.length()!=0)
		{
			cursor = head;
			index=0;
		}
	}
	// moveBack()
	// If List is non-empty, places the cursor under the back element,
    // otherwise does nothing.
	void moveBack()
	{
		if(this.length()!=0)
		{
			cursor = tail;
			index = length()-1;
		}
	}
	// movePrev()
	// pre: none
	// If cursor is defined and not at front, moves cursor one step toward
    // front of this List, if cursor is defined and at front, cursor becomes
    // undefined, if cursor is undefined does nothing.
	void movePrev()
	{
		if(cursor != null && cursor!=head)
		{
			cursor = cursor.prev;
			index--;
		}
		else if(cursor != null && cursor == head)
		{
			cursor = null;
		}
	}
	// moveNext()
	// pre: none
	// If cursor is defined and not at back, moves cursor one step toward
    // back of this List, if cursor is defined and at back, cursor becomes
    // undefined, if cursor is undefined does nothing.
	void moveNext()
	{
		if(cursor != null && cursor!=tail)
		{
			cursor = cursor.next;
			index++;
		}
		else if(cursor != null && cursor == tail)
		{
			cursor = null;
		}
	}
	// prepend()
	// Insert new element into this List. If List is non-empty,
    // insertion takes place before front element.
	void prepend(Object data)
	{
		if(length() != 0)
		{
			head.prev = new Node(data);
			head.prev.next = head;
			head = head.prev;
		}
		else
		{
			tail = head = new Node(data);
		}
		numItems++;
	}
	// append()
	// Insert new element into this List. If List is non-empty,
    // insertion takes place after back element.
	void append(Object data) 
	{
		if(length() != 0)
		{
			tail.next =  new Node(data);
			tail.next.prev = tail;
			tail = tail.next;
		}
		else
		{
			tail = head = new Node(data);
		}
		numItems++;
	}
	// insertBefore()
	// Pre: length()>0, index()>=0
	// Insert new element before cursor.
	void insertBefore(Object data) throws RuntimeException
	{
		if(length()<=0)
		{
			throw new RuntimeException("length() <= 0");
		}
		if(index()<0)
		{
			throw new RuntimeException("index() < 0");
		}
		 
		Node prev = cursor.prev; 
		Node n = new Node(data); // new node
		cursor.prev = n;
		n.next = cursor;
		if(prev != null)
		{
			prev.next = n;
		}
		n.prev = prev;
		if(index == 0)
		{
			head = n;
		}
		numItems++;
		index++;
	}
	// insertAfter()
	// Pre: length()>0, index()>=0
	// Inserts new element after cursor.
	void insertAfter(Object data)  throws RuntimeException
	{
		if(length()<=0)
		{
			throw new RuntimeException("length() <= 0");
		}
		if(index()<0)
		{
			throw new RuntimeException("index() < 0");
		}

		Node n = new Node(data);
		Node next = cursor.next;
		cursor.next = n;
		n.prev = cursor;
		n.next = next;
		if(next != null)
		{
			next.prev = n;
		}
		if(index == numItems-1)
		{
			tail = n;
		}
		numItems++;
	}
	// deleteFront()
	// Pre: length()>0
	// Deletes the front element. 
	void deleteFront() throws RuntimeException
	{
		if(length()<=0)
		{
			throw new RuntimeException("length() <= 0");
		}
		if(head.next != null)
		{
			head = head.next;
		}
		head.prev = null;
		numItems--;
	}
	// deleteBack()
	// Pre: length()>0
	// Deletes the back element.
	void deleteBack() throws RuntimeException
	{
		if(length()<=0)
		{
			throw new RuntimeException("length() <= 0");
		}
		if(tail.prev != null)
		{
			tail = tail.prev;
		}
		tail.next = null;
		numItems--;
	}
	// delete() 
	// Pre: length()>0, index()>=0
	// Deletes cursor element, making cursor undefined.
	void delete() throws RuntimeException
	{
		if(index()<0)
		{
			throw new RuntimeException("indedx() <= 0");
		}
		if(length()<=0)
		{
			throw new RuntimeException("length() <= 0");
		}

		Node prev = cursor.prev;
		Node next = cursor.next;
		if(prev != null && next != null)
		{
			prev.next = next;
			next.prev = prev;
		}
		else if(next == null)
		{
			prev.next = next;
		}
		else if(prev == null)
		{
			next.prev = prev;
		}
		cursor.next=null;
		cursor.prev=null;
		cursor = null;
		numItems--;
	}
	// Other methods
	
	// toString()
	// Overrides Object's toString method. Returns a String
    // representation of this List consisting of a space
	// separated sequence of integers, with front on left.
	public String toString()
	{
		StringBuffer str = new StringBuffer();
		
		for(Node ptr = head;ptr!=null;ptr = ptr.next)
		{
			str.append(ptr.data+" ");
		}
		return str.toString();
	}
	
}
