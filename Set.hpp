//- Representing a finite set of non-negative integer numbers.
//  Most left bit of a byte. (10000000).
#define LEFT_BIT  0x80
//- Most right bit of a byte.(00000001).
#define RIGTH_BIT 0x01

#include"ByteArray.hpp"

class Set {
	public:
    //- Representing the elements inside our set. The idea is:
    // if the bit in the position 'i' (0 <= i < 8) in the byte
    // of the position 'k' (0 <= k < length(container)) is equal to 1, then the number 'k*8 + i' is in the set.
    //- We can see the container as the "universal" set.
    ByteArray container;

    //- Constructors.
    //- Constructor for an empty set with no container.
    Set();
    //- Constructor for an empty set with a container of 'length'
    // bytes.
    Set(ui32 length);
    //- Constructor for a set containing the numbers of the array 'elements'.
    //- The array members of 'elements' are going to be interpreted as numbers.
    Set(ui32* elements,ui32 length);
    //- Constructor for a set witch members are determined by 'members'.
    //- The 'elements' members will be consider direct representation of the set members.
    Set(byte* elements,ui32 lenght);

    ui32 get_minimum();
    ui32 get_maximum();
    
    int print();
    //- Printing a line break after printing the set.
    void println();

	//- Prints a number using the binary base.
    void deleteSet();

	//- Deletes the right zero bytes of the container array.
	//- This function leafs at leas one byte in the container array.
    void fit();
};

//- Union of sets.
Set operator + (Set set1, Set set2);

//- Intersection of sets.
Set operator * (Set set1, Set set2);

//- Returns true if the number belongs to the set, otherwise it returns false.
bool belongs(ui32 number, Set set);

//- Returns a exact copy of this object.
Set copy(Set original);










