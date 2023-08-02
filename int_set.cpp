//---------------------------------------------------------------------------
// INT_SET.CPP
// Author:  Thomas Ampalloor, CSS343
//---------------------------------------------------------------------------
// IntSet class: An abstract Data Type for an Integer set called IntSet
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
#include "int_set.h"

using namespace std; 

//---------------------------------------------------------------------------
// Default constructor 
// Preconditions:   None
// Postconditions:  ptr points to an IntSet of size 1 and all
//        elements of the IntSet have been initialized to false.
IntSet::IntSet()
{
	 set_ = new bool[1];
	 size_ = 1;
	 initializeAll(set_, size_);



}

//---------------------------------------------------------------------------
// Copy constructor 
// Preconditions:   IntSet set is a valid IntSet
// Postconditions:  set is copied into *this, *this new values will equal 
//						  IntSet set values
IntSet::IntSet(const IntSet& set)
{
	*this = set; //calls assignment operator

}

//---------------------------------------------------------------------------
// One argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Creates an IntSet of size val1
//						  Initializes val1 to true in IntSet
//						  Handles negative integer by creating an IntSet of size 1
IntSet::IntSet(int val1)
{
	if (val1 >= 0) { //checks if val1 is a negative
		 set_ = new bool[val1 + 1];
		 size_ = val1 + 1; 
		 initializeAll(set_, size_); //initializes everything in set_ to false
		 set_[val1] = true; 
	}
	else {
		 set_ = new bool[1];
		 size_ = 1; 
		 initializeAll(set_, size_);

	}
}

//---------------------------------------------------------------------------
// Two argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1 and val2 are valid, they will be set to true
//						  Handles negative integers by inializing index to false 
//						  or creating IntSet of size 1
IntSet::IntSet(int val1, int val2)
{
	if (val1 >= 0 && val1 >= val2) { //checks if val1 is the biggest int
		 set_ = new bool[val1 + 1];
		 size_ = val1 + 1;
		 initializeAll(set_, size_);


		 set_[val1] = true; 
		 if (val2 >= 0) { //checks if val2 is a nonnegative
			  set_[val2] = true; 
		 }

	}
	else if (val2 >= 0 && val1 < val2) {
		 set_ = new bool[val2 + 1];
		 size_ = val2 + 1;
		 initializeAll(set_, size_);

		 set_[val2] = true;
		 if (val1 >= 0) {
			  set_[val1] = true;
		 }

	}
	else {
		 set_ = new bool[1];
		 size_ = 1;
		 initializeAll(set_, size_);

	}
}

//---------------------------------------------------------------------------
// Three argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1, val2, and val3 are valid, they will be set to 
//						  true
//						  Handles negative integers by inializing index to false 
//						  or creating IntSet of size 1
IntSet::IntSet(int val1, int val2, int val3)
{
	if (val1 >= 0 && val1 >= val2 && val1 >= val3) {
		 set_ = new bool[val1 + 1];
		 size_ = val1 + 1;
		 initializeAll(set_, size_);

		 set_[val1] = true;
		 if (val2 >= 0) {
			  set_[val2] = true;
		 }
		 if (val3 >= 0) {
			  set_[val3] = true; 
		 }

	}
	else if (val2 >= 0 && val2 >= val3 && val2 >= val1) {
		 set_ = new bool[val2 + 1];
		 size_ = val2 + 1;
		 initializeAll(set_, size_);

		 set_[val2] = true;
		 if (val1 >= 0) {
			  set_[val1] = true;
		 }
		 if (val3 >= 0) {
			  set_[val3] = true;
		 }
	}
	else if (val3 >= 0 && val3 >= val1 && val3 >= val2) {
		 set_ = new bool[val3 + 1];
		 size_ = val3 + 1;
		 initializeAll(set_, size_);

		 set_[val3] = true;
		 if (val1 >= 0) {
			  set_[val1] = true;
		 }
		 if (val2 >= 0) {
			  set_[val2] = true;
		 }
		 
	}
	else {
		 set_ = new bool[1];
		 size_ = 1;
		 initializeAll(set_, size_);

	}

	
}

//---------------------------------------------------------------------------
// Four argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1, val2, val3 and val4 are valid they will be set
//						  to true
//						  Handles negative integers by inializing index to false
//						  or creating IntSet of size 1
IntSet::IntSet(int val1, int val2, int val3, int val4)
{
	 if (val1 >= 0 && val1 >= val2 && val1 >= val3 && val1 >= val4) {
		  set_ = new bool[val1 + 1];
		  size_ = val1 + 1;
		  initializeAll(set_, size_);

		  set_[val1] = true;
		  if (val2 >= 0) {
				set_[val2] = true;
		  }
		  if (val3 >= 0) {
				set_[val3] = true;
		  }
		  if (val4 >= 0) {
				set_[val4] = true; 
		  }

	 }
	 else if (val2 >= 0 && val2 >= val3 && val2 >= val1 && val2 >= val4) {
		  set_ = new bool[val2 + 1];
		  size_ = val2 + 1;
		  initializeAll(set_, size_);

		  set_[val2] = true;
		  if (val1 >= 0) {
				set_[val1] = true;
		  }
		  if (val3 >= 0) {
				set_[val3] = true;
		  }
		  if (val4 >= 0) {
				set_[val4] = true;
		  }

	 }
	 else if (val3 >= 0 && val3 >= val1 && val3 >= val2 && val3 >= val4) {
		  set_ = new bool[val3 + 1];
		  size_ = val3 + 1;
		  initializeAll(set_, size_);

		  set_[val3] = true;
		  if (val1 >= 0) {
				set_[val1] = true;
		  }
		  if (val2 >= 0) {
				set_[val2] = true;
		  }
		  if (val4 >= 0) {
				set_[val4] = true;
		  }

	 }
	 else if (val4 >= 0 && val4 >= val1 && val4 >= val2 && val4 >= val3) {
		  set_ = new bool[val4 + 1];
		  size_ = val4 + 1;
		  initializeAll(set_, size_);

		  set_[val4] = true;
		  if (val1 >= 0) {
				set_[val1] = true;
		  }
		  if (val3 >= 0) {
				set_[val3] = true;
		  }
		  if (val2 >= 0) {
				set_[val2] = true;
		  }

	 }
	 else {
		  set_ = new bool[1];
		  size_ = 1;
		  initializeAll(set_, size_);

	 }
}

//---------------------------------------------------------------------------
// Five argument constructor 
// Preconditions:   Values inputted is an integer
// Postconditions:  Checks which value inputted is larger 
//						  Creates an IntSet of which ever value is larger
//						  If val1, val2, val3, val4, and val5 are valid they
//						  will be set to true
//						  Handles negative integers by inializing index to false
//						  or creating IntSet of size 1
IntSet::IntSet(int val1, int val2, int val3, int val4, int val5)
{
	 if (val1 >= 0 && val1 >= val2 && val1 >= val3 && val1 >= val4 
		  && val1 >= val5) {
		  set_ = new bool[val1 + 1];
		  size_ = val1 + 1;
		  initializeAll(set_, size_);

		  set_[val1] = true;
		  if (val2 >= 0) {
				set_[val2] = true;
		  }
		  if (val3 >= 0) {
				set_[val3] = true;
		  }
		  if (val4 >= 0) {
				set_[val4] = true;
		  }
		  if (val5 >= 0) {
				set_[val5] = true;
		  }

	 }
	 else if (val2 >= 0 && val2 >= val3 && val2 >= val1 && val2 >= val4 && 
		val2 >= val5) {
		  set_ = new bool[val2 + 1];
		  size_ = val2 + 1;
		  initializeAll(set_, size_);

		  set_[val2] = true;
		  if (val1 >= 0) {
				set_[val1] = true;
		  }
		  if (val3 >= 0) {
				set_[val3] = true;
		  }
		  if (val4 >= 0) {
				set_[val4] = true;
		  }
		  if (val5 >= 0) {
				set_[val5] = true;
		  }

	 }

	 else if (val3 >= 0 && val3 >= val1 && val3 >= val2 && val3 >= val4 
		  && val3 >= val5) {
		  set_ = new bool[val3 + 1];
		  size_ = val3 + 1;
		  initializeAll(set_, size_);

		  set_[val3] = true;
		  if (val1 >= 0) {
				set_[val1] = true;
		  }
		  if (val2 >= 0) {
				set_[val2] = true;
		  }
		  if (val4 >= 0) {
				set_[val4] = true;
		  }
		  if (val5 >= 0) {
				set_[val5] = true;
		  }

	 }
	 else if (val4 >= 0 && val4 >= val1 && val4 >= val2 && val4 >= val3 
		  && val4 >= val5) {
		  set_ = new bool[val4 + 1];
		  size_ = val4 + 1;
		  initializeAll(set_, size_);

		  set_[val4] = true;
		  if (val1 >= 0) {
				set_[val1] = true;
		  }
		  if (val3 >= 0) {
				set_[val3] = true;
		  }
		  if (val2 >= 0) {
				set_[val2] = true;
		  }
		  if (val5 >= 0) {
				set_[val5] = true;
		  }

	 }
	 else if (val5 >= 0 && val5 >= val1 && val5 >= val2 && val5 >= val3 
		  && val5 >= val4) {
		  set_ = new bool[val5 + 1];
		  size_ = val5 + 1;
		  initializeAll(set_, size_);

		  set_[val5] = true;
		  if (val1 >= 0) {
				set_[val1] = true;
		  }
		  if (val3 >= 0) {
				set_[val3] = true;
		  }
		  if (val4 >= 0) {
				set_[val4] = true;
		  }
		  if (val2 >= 0) {
				set_[val2] = true;
		  }

	 }
	 else {
		  set_ = new bool[1];
		  size_ = 1;
		  initializeAll(set_, size_);

	 }
}

//---------------------------------------------------------------------------
// Destructor 
// Preconditions:   ptr points to memory on the heap
// Postconditions:  set_ for IntSet is deallocated
IntSet::~IntSet()
{
	 delete[] set_; 
	 set_ = nullptr; 
}

//----------------------------- getSize -------------------------------------
// size 
// Gets the size of the IntSet
// Preconditions:   None
// Postconditions:  Returns the size of the IntSet
int IntSet::size()
{
	 return size_;
}

//---------------------------------------------------------------------------
// isEmpty 
// Preconditions:  None
// Postconditions: returns true if all elements in IntSet are false
bool IntSet::isEmpty()
{
	 if (size_ == 1) {
		  if (set_[0] == false) {
				return true;
		  }
	 }
	 else {
		  for (int i = 0; i < size_; i++) {
				if (set_[i] == true) {
					 return false; 
				}
		  }
	 }

	 return true;;
}

//---------------------------------------------------------------------------
// isInSet 
// Preconditions:	  value inputted is an integer
// Postconditions:  Returns true if the value inputted is in IntSet
//						  Handles negative value and value outside of size by 
//						  returning false
bool IntSet::isInSet(int value)
{
	 if (value > size_) { //checks if value is out of range
		  return false; 
	 }
	 if (value < 0) { //checks if value is non negative
		  return false; 
	 }
	 if (set_[value] == true) {
		  return true; 
	 }
	 return false;
}


//---------------------------------------------------------------------------
// insert 
// Preconditions:   Value is an integer
// Postconditions:  Returns true if the value is successfully inserted
//						  Checks if value is greater than size and handles by 
//						  resizing IntSet (deallocates temp memory) 
//						  Doesn't insert negative value
//						  
bool IntSet::insert(int value)
{
	 if (value >= 0) { //checks if value is non negative
		  if (value < size_) { //if value is within range of size then...
				if (set_[value] == true) {
					 return false; 
				}
				else {
					 set_[value] = true; //...value will be changed to true
				}
				return true; 
		  }
		  else {
				bool* temp = new bool[size_]; 
				for (int i = 0; i < size_; i++) {//creates new pointer array and..
					 temp[i] = false;					//...makes an exact copy of set_ 
				}
				for (int i = 0; i < size_; i++) {
					 if (set_[i] == true) {
						  temp[i] = true; 
					 }
				}
				delete[] set_;  //deallocates memory so no memory leaks
				set_ = nullptr;
				set_ = new bool[value + 1];

				initializeAll(set_, size_);

				for (int i = 0; i < size_; i++) {
					 if (temp[i] == true) {
						  set_[i] = true; 
					 }
				}

				set_[value] = true; //inserts value
				size_ = value + 1; 

				delete[] temp;
				temp = nullptr; 
				return true;
		  }
	 }
	
	 return false;
}

//---------------------------------------------------------------------------
// remove 
// Preconditions:   Value is an integer
// Postconditions:  Returns true if the value was successfully changed to 
//						  false
//						  Checks if value is non negative
bool IntSet::remove(int value)
{
	 if (value >= 0) {
		  if (value <= size_) {
				if (set_[value] == true) {
					 set_[value] = false;
					 return true;
				}
		  }
	 }

	 return false;
}

//---------------------------------------------------------------------------
// initializeAll 
// Preconditions:   arr is a boolean array, size is an integer
// Postconditions:  Initializes every element in arr to false
void IntSet::initializeAll(bool arr[], int size)
{
	 for (int i = 0; i < size_; i++) {
		  set_[i] = false; 
	 }
}

//---------------------------------------------------------------------------
// operator=
// Overloaded assignment operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: *this is assigned the same IntSet as set (deep copy)
IntSet& IntSet::operator=(const IntSet& set)
{
	 if (*this == set) {
		  return *this;
	 }


	 delete[] set_; //deallocates set_
	 set_ = nullptr;

	 set_ = new bool[set.size_];
	 this->size_ = set.size_;

	 initializeAll(set_, size_);

	 for (int i = 0; i < set.size_; i++) {
		  if (set.set_[i] == true) {
				this->set_[i] = true;
		  }
	 }

	 return *this; 
}

//---------------------------------------------------------------------------
// operator==  
// Determine if two IntSets are equal.
// Preconditions:	  Both the calling object and parameter object have ptr
//						  arrays with a valid size
// Postconditions:  true is returned if the IntSets have the same size and 
//						  elements false is return otherwise
bool IntSet::operator==(const IntSet& set) const
{
	 if (this->size_ != set.size_) {
		  return false;
	 }
	 //checking each index of each set
	 for (int i = 0; i < this->size_ + 1; i++) {
		  if ((this->set_[i] == true && set.set_[i] == false)
				|| (this->set_[i] == false && set.set_[i] == true)) {
				return false;
		  }
	 }
	 return true;
}

//---------------------------------------------------------------------------
// operator!=
// Determine if two IntSets are not equal.
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: false is returned if the IntSets have the same size and 
//     elements true is return otherwise
bool IntSet::operator!=(const IntSet& set) const
{
	 //if sizes aren't equal, they are automatically not equal 
	 if (this->size_ != set.size_) { 
		  return true;
	 }
	 //checking each index of each set
	 for (int i = 0; i < this->size_ + 1; i++) { 
		  if ((this->set_[i] == true && set.set_[i] == false) 
				|| (this->set_[i] == false && set.set_[i] == true) ) {
				return true; 
		  }
	 }
	 return false;
}

//---------------------------------------------------------------------------
// operator<<
// Overloaded output operator for class Array
// Preconditions: Parameter object have ptr arrays with a valid size
// Postconditions: Prints values for the IntSet with in brackets and a space
//						 before each number
//						 If it is empty then it will print an empty bracket
ostream& operator<<( ostream& stream, const IntSet& set)
{
	 if (set.size_ == 1) {
		  if (set.set_[0]) {
				stream << "{ 0}" << endl;
				return stream; 
		  }
		  else {
				stream << "{ }" << endl; //empty set
				return stream; 
		  }
	 }
	 stream << "{"; 
	 for (int i = 0; i < set.size_; i++) { 
		  if (set.set_[i] == true) { //checks each element in set_ prints them
				stream << " " << i;
		  }
	 }
	 stream << "}" << endl;
	 return stream;
}

//---------------------------------------------------------------------------
// operator>>
// Overloaded input operator for class IntSet 
// inputs values for entire IntSet
// Preconditions: Parameter object have ptr arrays with a valid size
// Postconditions: Reads integers and inserts them into 'set'
//						 User types -1 to exit
istream& operator>>(istream& stream,  IntSet& set)
{
	 int value = -2; 
	 while (value != -1) { //exits at -1
		  cout << "Input value, or type -1 to exit" << endl;
		  stream >> value; 
		  set.insert(value); //inserts value
	 }
	 return stream; 
}


//----------------------------------------------------------------------------
// operator+  
// overloaded + operator 
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the union of two sets, sets of elements that are 
//						 contained in either or both sets
IntSet IntSet::operator+(const IntSet& set) const
{
	 IntSet newSet =  IntSet();
	 bool* newSetArray; 

	 if (this->size_ >= set.size_) {  //checks which size is greater
		  newSetArray = new bool[this->size_]; 
		  newSet.size_ = this->size_;
	 }
	 else {
		  newSetArray = new bool[set.size_]; 
		  newSet.size_ = set.size_;
	 }

	 for (int i = 0; i < newSet.size_; i++) { //initializes indexes to false
		  newSetArray[i] = false;
	 }

	 for (int i = 0; i < this->size_; i++) {
		  if (this->set_[i] == true) { //assigns true accordingly 
				newSetArray[i] = true;

		  }
	 }

	 for (int i = 0; i < set.size_; i++) {
		  if (set.set_[i] == true) { //assigns true accordingly 
				newSetArray[i] = true;
		  }
	 }
	 
	 delete[] newSet.set_;

	 newSet.set_ = newSetArray;
	 newSetArray = nullptr;
	 return newSet;
}

//----------------------------------------------------------------------------
// operator*  
// overloaded * operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the intersection of two sets, the set of all 
//						 elements that are common to both sets
IntSet IntSet::operator*(const IntSet& set) const
{
	 IntSet newSet; 
	 bool* newSetArray; 
	 if (this->size_ <= set.size_) { //checks which size is greater
		  newSetArray = new bool[size_];
		  newSet.size_ = size_;
		  for (int i = 0; i < size_; i++) {
				newSetArray[i] = false;
		  }
		  for (int i = 0; i < size_; i++) { //checks which values are similar
				if (this->set_[i] == true && set.set_[i] == true) {
					 newSetArray[i] = true; 
				}
		  }
	 }
	 else {
		  newSetArray = new bool[set.size_];
		  newSet.size_ = set.size_;
		  for (int i = 0; i < set.size_; i++) { //initializes indexes to false
				newSetArray[i] = false;
		  }

		  for (int i = 0; i < set.size_; i++) { //checks which values are similar
				if (this->set_[i] == true && set.set_[i] == true) {
					 newSetArray[i] = true;
				}
		  }
	 }
	 delete[] newSet.set_;

	 newSet.set_ = newSetArray;
	 newSetArray = nullptr;
	 return newSet;
}

//----------------------------------------------------------------------------
// operator-  
// overloaded - operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: Returns the difference of two sets
//						 Set of elements in 'this' but not in 'set'
IntSet IntSet::operator-(const IntSet& set) const
{
	 IntSet newSet;
	 bool* newSetArray = new bool[this->size_];
	 newSet.size_ = this->size_;

	 for (int i = 0; i < size_; i++) {
		  newSetArray[i] = false;
	 }
	 if (this->size_ <= set.size_) { //checks which size is greater
		  for (int i = 0; i < this->size_; i++) {
				if (this->set_[i] == true && !(set.set_[i] == true)) {
					 newSetArray[i] = true; //assigns true accordingly
				}
		  }
	 }
	 else {
		  for (int i = 0; i < set.size_; i++) {
				if (this->set_[i] == true && !(set.set_[i] == true)) {
					 newSetArray[i] = true; //assigns true accordingly
				}
		  }

		  for (int i = set.size_ + 1; i < this->size_; i++) {
				if (this->set_[i] == true) {
					 newSetArray[i] = true; //assigns true accordingly
				}
		  }
	 }
	 delete[] newSet.set_;

	 newSet.set_ = newSetArray;
	 newSetArray = nullptr;
	 return newSet;
}

//----------------------------------------------------------------------------
// operator+=  
// overloaded += operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the union of two sets, sets of elements that are 
//						 contained in either or both sets and assigns it to 'this'
IntSet& IntSet::operator+=(const IntSet& set)
{
	 if (this->size_ >= set.size_) { //checks which size is greater
		  for (int i = 0; i < set.size_; i++) {
				if (set.set_[i] == true) {
					 this->set_[i] = true; //assigns true accordingly
				}
		  }
	 }
	 else {
		  bool* temp = new bool[this->size_];
		  for (int i = 0; i < size_; i++) {
				temp[i] = false;
		  }
		  for (int i = 0; i < size_; i++) {
				if (set_[i] == true) { //assigns true accordingly
					 temp[i] = true;
				}
		  }
		  delete[] set_; //deallocates set_
		  set_ = nullptr; 

		  set_ = new bool[set.size_];
		  this->size_ = set.size_;

		  for (int i = 0; i < size_; i++) {
				if (temp[i] == true) {
					 set_[i] = true;
				}
		  }
		  for (int i = 0; i < set.size_; i++) {
				if (set.set_[i] == true) {
					 set_[i] = true;
				}
		  }
		  delete[] temp; //deallocates temp
		  temp = nullptr; 
	 }

	 return *this; 
}

//----------------------------------------------------------------------------
// operator-=  
// overloaded -= operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: Returns the difference of two sets and assigns to 'this'
//						 Set of elements in 'this' but not in 'set'
IntSet& IntSet::operator-=(const IntSet& set){
	 bool* temp = new bool[this->size_];
	 for (int i = 0; i < size_; i++) {
		  temp[i] = false;
	 }
	 for (int i = 0; i < size_; i++) {
		  if (set_[i] == true) {
				temp[i] = true;
		  }
	 }
	 delete[] set_; //deallocates set_
	 set_ = nullptr;

	 set_ = new bool[size_];
	 initializeAll(set_, size_); //initalizes everything in set_ 

	 if (this->size_ <= set.size_) {
		  for (int i = 0; i < this->size_; i++) {
				if (temp[i] == true && !(set.set_[i] == true)) {
					set_[i] = true;
				}
		  }

	 }
	 else {
		  for (int i = 0; i < set.size_; i++) {
				if (temp[i] == true && !(set.set_[i] == true)) {
					 set_[i] = true;
				}
		  }

		  for (int i = set.size_ + 1; i < this->size_; i++) {
				if (temp[i] == true) {
					set_[i] = true;
				}
		  }
	 }

	 delete[] temp; //deallocates temp
	 temp = nullptr; 
	 return *this; 
}

//----------------------------------------------------------------------------
// operator*=  
// overloaded *= operator
// Preconditions: Both the calling object and parameter object have ptr
//						arrays with a valid size
// Postconditions: returns the intersection of two sets and assigns to 'this', 
//						 the set of all elements that are common to both sets 
IntSet& IntSet::operator*=(const IntSet& set)
{
	 bool* temp = new bool[this->size_];
	 for (int i = 0; i < size_; i++) {
		  temp[i] = false;
	 }
	 for (int i = 0; i < size_; i++) {
		  if (set_[i] == true) {
				temp[i] = true;
		  }
	 }
	 delete[] set_; //deallocates set_
	 set_ = nullptr;

	 if (this->size_ <= set.size_) {
		  set_ = new bool[size_];
		  initializeAll(set_, size_); //initalizes everything in set_ 
		  for (int i = 0; i < size_; i++) {
				if (temp[i] == true && set.set_[i] == true) {
					 set_[i] = true;
				}
		  }
	 }
	 else {
		  set_ = new bool[set.size_];
		  size_ = set.size_;
		  initializeAll(set_, size_); //initalizes everything in set_ 
		  for (int i = 0; i < set.size_; i++) {
				if (temp[i] == true && set.set_[i] == true) {
					 set_[i] = true;
				}
		  }
	 }

	 delete[] temp; //deallocates temp
	 temp = nullptr; 

	 return *this;
}

