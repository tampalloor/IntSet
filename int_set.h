//---------------------------------------------------------------------------
// INT_SET.H
// Author:  Thomas Ampalloor, CSS343
//---------------------------------------------------------------------------
// Array class: An abstract Data Type for an Integer set called IntSet
//   -- allows input and output of the IntSet
//   -- allows for comparison of 2 IntSets, element by element
//   -- allows for assignment of 2 IntSets
//   -- size is part of the class (so no longer needs to be passed)
//   -- If a negative value is inputted, the program WILL NOT crash and will
//      handle it accordingly
//
// Assumptions:
//   -- IntSet is empty with the default size of 1 if nothing is inputted 
//   -- IntSet elements will be defaulted to false if nothing is inputted
//   -- user must enter valid integers when using >> or when inserting/
//		  removing/creating an object
//   -- in <<, integers are displayed within brackets, with space before 
//		  the integer
//---------------------------------------------------------------------------

#ifndef INT_SET_H_
#define INT_SET_H_
#include<iostream>
#include<string>

using namespace std; 
class IntSet
{
public: 
	//constructors and destructor


//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  ptr points to an IntSet of size 1 and all
//						  elements of the IntSet have been initialized to false.
	IntSet();  

//---------------------------------------------------------------------------
// Copy constructor 
// Preconditions:   IntSet set is a valid IntSet
// Postconditions:  set is copied into *this, *this new values will equal 
//						  IntSet set values
	IntSet(const IntSet& set);

//---------------------------------------------------------------------------
// One argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Creates an IntSet of size val1
//						  Initializes val1 to true in IntSet
//						  Handles negative integer by creating an IntSet of size 1
	IntSet(int val1); 

//---------------------------------------------------------------------------
// Two argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1 and val2 are valid, they will be set to true
//						  Handles negative integers by inializing index to false or
//						  creating IntSet of size 1
	IntSet(int val1, int val2); 

//---------------------------------------------------------------------------
// Three argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1, val2, and val3 are valid, they will be set to 
//						  true
//						  Handles negative integers by inializing index to false or
//						  creating IntSet of size 1
	IntSet(int val1, int val2, int val3); 

//---------------------------------------------------------------------------
// Four argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1, val2, val3 and val4 are valid they will be set
//						  to true
//						  Handles negative integers by inializing index to false or
//						  creating IntSet of size 1
	IntSet(int val1, int val2, int val3, int val4); 

//---------------------------------------------------------------------------
// Five argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1, val2, val3, val4, and val5 are valid they
//						  will be set to true
//						  Handles negative integers by inializing index to false or
//						  creating IntSet of size 1
	IntSet(int val1, int val2, int val3, int val4, int val5); 

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   ptr points to memory on the heap
// Postconditions:  set_ for IntSet is deallocated
	~IntSet();


//----------------------------- getSize -------------------------------------
// size 
// Gets the size of the IntSet
// Preconditions:   None
// Postconditions:  Returns the size of the IntSet
	int size(); 

	// actions
//---------------------------------------------------------------------------
// isEmpty 
// Preconditions:  None
// Postconditions: returns true if all elements in IntSet are false
	bool isEmpty(); 

//---------------------------------------------------------------------------
// isInSet 
// Preconditions:	  value inputted is an integer
// Postconditions:  Returns true if the value inputted is in IntSet
//						  Handles negative value and value outside of size by 
//						  returning false
	bool isInSet(int value);

//---------------------------------------------------------------------------
// insert 
// Preconditions:   Value is an integer
// Postconditions:  Returns true if the value is successfully inserted
//						  Checks if value is greater than size and handles by 
//						  resizing IntSet (deallocates temp memory) 
//						  Doesn't insert negative value
	bool insert(int value);

//---------------------------------------------------------------------------
// remove 
// Preconditions:   Value is an integer
// Postconditions:  Returns true if the value was successfully changed to 
//						  false
//						  Checks if value is non negative
	bool remove(int value);

//---------------------------------------------------------------------------
// initializeAll 
// Preconditions:   arr is a boolean array, size is an integer
// Postconditions:  Initializes every element in arr to false
	void initializeAll(bool arr[], int size);


	//operator overlaods

//----------------------------------------------------------------------------
// operator+  
// overloaded + operator 
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the union of two sets, sets of elements that are 
//						 contained in either or both sets
	IntSet operator+(const IntSet& set)const; 

//----------------------------------------------------------------------------
// operator*  
// overloaded * operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the intersection of two sets, the set of all 
//						 elements that are common to both sets
	IntSet operator*(const IntSet& set)const;

//----------------------------------------------------------------------------
// operator-  
// overloaded - operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: Returns the difference of two sets
//						 Set of elements in 'this' but not in 'set'
	IntSet operator-(const IntSet& set)const;

//----------------------------------------------------------------------------
// operator+=  
// overloaded += operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the union of two sets, sets of elements that are 
//						 contained in either or both sets and assigns it to 'this'
	IntSet& operator+=(const IntSet& set);

//----------------------------------------------------------------------------
// operator-=  
// overloaded -= operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: Returns the difference of two sets and assigns to 'this'
//						 Set of elements in 'this' but not in 'set'
	IntSet& operator-=(const IntSet& set);

//----------------------------------------------------------------------------
// operator*=  
// overloaded *= operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the intersection of two sets and assigns to 'this', 
//						 the set of all elements that are common to both sets 
	IntSet& operator*=(const IntSet& set);

//---------------------------------------------------------------------------
// operator=
// Overloaded assignment operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: *this is assigned the same IntSet as set (deep copy)
	IntSet& operator=(const IntSet& set); 

//---------------------------------------------------------------------------
// operator==  
// Determine if two IntSets are equal.
// Preconditions:	  Both the calling object and parameter object have ptr
//						  arrays with a valid size
// Postconditions:  true is returned if the IntSets have the same size and 
//						  elements false is return otherwise
	bool operator==(const IntSet& set)const;

//---------------------------------------------------------------------------
// operator!=
// Determine if two IntSets are not equal.
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: false is returned if the IntSets have the same size and 
//     elements true is return otherwise
	bool operator!=(const IntSet& set)const;

//---------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
// Preconditions: Parameter object have ptr arrays with a valid size
// Postconditions: Prints values for the IntSet with in brackets and a space
//						 before each number
//						 If it is empty then it will print an empty bracket
	friend ostream& operator<<( ostream& stream, const IntSet& set);

//---------------------------------------------------------------------------
// operator>>
// Overloaded input operator for class IntSet 
// inputs values for entire IntSet
// Preconditions: Parameter object have ptr arrays with a valid size
// Postconditions: Reads integers and inserts them into 'set'
//						 User types -1 to exit
	friend istream& operator>>( istream& stream,  IntSet& set);



private: 
	 bool* set_ = nullptr; //declaring a pointer boolean array which holds the values of IntSet
	 int size_; //Size of the set_ array 
};
#endif

