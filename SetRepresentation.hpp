//- Representing a finite set of non-negative integer numbers.
//- Hexadecimal representation of the binary number 10000000.
#define RIGHT_BIT 0x80 

#include"ByteArray.hpp"

class Set {
    //- Representing the elements inside our set. The idea is:
    // if the bit in the position 'i' (0 <= i < 8) in the byte
    // of the position 'k' (0 <= k < length(container)) is equal
    // to 1, then the number 'k*8 + i' is in the set.
    //- We can see the container as the "universal" set.
    ByteArray container;

    //- Constructors.
    //- Constructor for an empty set with no container.
    Set();
    //- Constructor for an empty set with a container of 'length'
    // bytes.
    Set(ui32 length);

    ui32 get_minimum();
    ui32 get_maximum();
};