# IntSet
One IntSet object represents one mathematical set of non-negative integers (includes zero). One set keeps track
of unique integers, whether integers are in the set or not. Implement the internal representation as follows.

An IntSet object’s implementation is represented a bool array internally, containing true and false. For example,
if you call the array set, then set[num] is true if the integer num is in the set, false if num is not in the set. Use
"new" to dynamically allocate memory for the array. One object’s array stores one math set’s values.

Developed a full class with the following operations:
1. operator+: returns the union of two sets, the set of elements that are contained in either or both sets.
(Note - do not call any identifiers “union” as that is a keyword in C++.)
2. operator*: returns the intersection of two sets, the set of all elements that are common to both sets.
3. operator-: returns the difference of two sets, say A-B, which is the set of all elements that are in set A
but not in set B. (E.g., A = { 2 3 5 30}, B = { 3 5 10 40}, then A-B is { 2 30} )
4. operator=: the assignment operator to assign one set to another. Righthand side replaces lefthand side.
5. operators (+=, *=, -=): the union, intersection, difference assignment.
6. operators (==, !=): bool equality and inequality. A == B if the mathematical sets contain the same elements.
7. insert: insert an element into a set, has bool return value,, e.g., bool success = A.insert(5);
(Note: ignore invalid integers, return false, e.g., bool success = A.insert(-10);
If a value is already in the set and is inserted, return true).
8. remove: remove an element from a set, bool return value, e.g., bool success = A.remove(10);
(Note: ignore invalid integers, return false, e.g,. bool success = A.remove(-10); ).
9. isEmpty: determine if a set is empty or not, bool return value, e.g., if (A.isEmpty()) ...
10. isInSet: determine if an integer is in the set or not,
 e.g., if (A.isInSet(5)) ... (Note: returns false for invalid integers).
11. operator<<: Display { 5 10 12 20 25 100} to represent the set containing the integers
5, 10, 12, 20, 25, and 100. The empty set is displayed exactly as: {}
(Output exactly as shown, inside curly braces with one blank before each number;
output no other blanks. Note that operator<< should not do an endl.)
12. operator>>: to input an entire set. (Note: This is a simple loop to take integers; terminate at
some sentinel value, say -1. Ignore invalid integers. Zero is valid as it is non-negative.)
13. All proper constructor and destructor functions; constructor(s) initialize a set to
(1) The "empty set" (a set which has no elements) or,
(2) A set that can take up to five values to be inserted into the set
 e.g., IntSet A, B(3), C(12,5,5), D(5,-10,12), E(100,2,-5,45), F(1,2,3,4,5);
 IntSet X(D); // X is an exact copy of D.

Set A is the empty set. (For implementation, you could use nullptr, but using an array of one element keeps it
cleaner.) While A is currently the empty set, after the operator>> , operator=, etc. is used, the set could
contain many values. Set B holds the value 3. Set C has a current largest value of 12, also contains the value 5.

The constructor for D will ignore the -10, but is initialized to contain 5 and 12. E is { 2 45 100}. F is { 1 2
3 4 5}. X is a deep copy of D, is { 5 12}. You must initially size the arrays by the parameters, e.g., A's array
is size 1, B's array is size 4, C and D’s array are size 13, E’s array size is 101, etc. Later, after operations, the
size may change. You may need to make arrays larger for operations later (e.g., A = B;); but since new and
delete are costly operations, typically, for efficiency reasons, you don’t shrink arrays if less space is needed.
One component of this assignment is to be efficient, to minimize unnecessary new and delete operations.

Often, when more memory is needed for an array, applications will double the array size to minimize the number
of new and delete operations. Do not do that in your program. This assignment is about practice of memory
management (proper memory allocation and deallocation). Having a larger than needed array can mask errors.
