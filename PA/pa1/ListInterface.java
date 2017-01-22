
public interface ListInterface {
	// Access functions
	int length(); // Returns the number of elements in this List.
	int index(); // If cursor is defined, returns the index of the cursor element,
	 // otherwise returns -1.
	int front(); // Returns front element. Pre: length()>0
	int back(); // Returns back element. Pre: length()>0
	int get(); // Returns cursor element. Pre: length()>0, index()>=0
	boolean equals(List L); // Returns true if this List and L are the same integer
	 // sequence. The cursor is ignored in both lists.
	// Manipulation procedures
	void clear(); // Resets this List to its original empty state.
	void moveFront(); // If List is non-empty, places the cursor under the front element,
	 // otherwise does nothing.
	void moveBack(); // If List is non-empty, places the cursor under the back element,
	 // otherwise does nothing.
	void movePrev(); // If cursor is defined and not at front, moves cursor one step toward
	 // front of this List, if cursor is defined and at front, cursor becomes
	// undefined, if cursor is undefined does nothing.
	void moveNext(); // If cursor is defined and not at back, moves cursor one step toward
	 // back of this List, if cursor is defined and at back, cursor becomes
	// undefined, if cursor is undefined does nothing.
	void prepend(int data); // Insert new element into this List. If List is non-empty,
	 // insertion takes place before front element.
	void append(int data); // Insert new element into this List. If List is non-empty,
	 // insertion takes place after back element.
	void insertBefore(int data); // Insert new element before cursor.
	 // Pre: length()>0, index()>=0
	void insertAfter(int data); // Inserts new element after cursor.
	 // Pre: length()>0, index()>=0
	void deleteFront(); // Deletes the front element. Pre: length()>0
	void deleteBack(); // Deletes the back element. Pre: length()>0
	void delete(); // Deletes cursor element, making cursor undefined.
	 // Pre: length()>0, index()>=0
	
	// Other methods
	public String toString(); // Overrides Object's toString method. Returns a String
	 // representation of this List consisting of a space
	// separated sequence of integers, with front on left.
	List copy(); // Returns a new List representing the same integer sequence as this
	 // List. The cursor in the new list is undefined, regardless of the
	 // state of the cursor in this List. This List is unchanged.
}
