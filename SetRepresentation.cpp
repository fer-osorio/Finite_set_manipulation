//-Representing a finite set of non-negative integer numbers.

#include"SetRepresentation.hpp"

//- Constructor with no arguments. Returns the representation
// of an empty set wtih no container.
Set::Set() {
    container = ByteArray(0);
}

//- Constructor for an empty set with a container of 'length'
// bytes.
Set::Set(ui32 length) {
    container = ByteArray(length);
}

ui32 Set::get_minimum() {
    int i = 0, j = 0;
    while( i < container.length() && container.elements()[i] == 0) i++;
    while( (RIGHT_BIT >> j & container.elements()[i]) == 0) j++;

    return i*8 + j;
}

ui32 Set::get_maximum() {
    
}