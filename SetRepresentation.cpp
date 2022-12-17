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
    int i = 0, j = 0, len = container.length();
    int elements[] = container.elements();
    byte selector = LEFT_BIT;
    while( i < len && elements[i] == 0) i++;
    //- The set has no elements. This is a just
    //  a preventive answer; this is not the co-
    //  rrect answer.
    if(i==len)  return 0;
    while( (selector & elements[i]) == 0) {
        j++;
        selector >> 1;
    }
    return i*8 + j;
}

ui32 Set::get_maximum() {
    int i = container.Length - 1, j = 7;
    int elements[] = container.elements();
    byte selector = RIGTH_BIT;
    while(i >= 0 && elements == 0) i--;
    if(i==-1)   return 0;
    while((selector & elements[i]) == 0) {
        j--;
        selector << 1;
    }
    return i*8+j;
}















