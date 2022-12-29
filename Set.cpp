//-Representing a finite set of non-negative integer numbers.

#include"Set.hpp"

//- Constructor with no arguments. Returns the representation of an empty set with no container.
Set::Set() {
    container = ByteArray();
}

//- Constructor for an empty set with a container of 'length' bytes.
Set::Set(ui32 length) {
    container = ByteArray(length);
}

//- Constructor for a set containing the elements of the array 'elements'.
Set::Set(ui32* elements,ui32 length) {
    //- Making an empty container big enough to contain all the numbers in the 'elements' array.
    ui32 size = max(elements,length)/8 + 1, i, j;
    byte* elemInSet = new byte[size];
    for( i = 0; i < size; i++)
        elemInSet[i] = 0;

    ui32 bytesToTheRight, bitsToTheRight, selector;
    for(i = 0; i < length; i++) {
        bytesToTheRight = elements[i]/8;
        bitsToTheRight = elements[i]%8;
        selector = LEFT_BIT >> bitsToTheRight;
        elemInSet[bytesToTheRight] |= selector;
    }
    container = ByteArray(elemInSet, size);
}

//- Constructor for a set witch members are determined by 'members'.
//- The 'elements' members will be consider direct representation of the set members.
Set::Set(byte* elements, ui32 length) {
    container = ByteArray(elements,length);
}

ui32 Set::get_minimum() {
    //- Handling the case of an empty set. This is just a provisional answer.
    if(container.length() == 0) {
        std::cout << "\n Trying to get the minimum of an empty set, returning zero.\n";
        return 0;
    }
    int i = 0, j = 0, len = container.length();
    byte* elements = container.elements();
    byte selector = LEFT_BIT;
    while( i < len && elements[i] == 0) i++;
    while( (selector & elements[i]) == 0) {
        j++;
        selector >>= 1;
    }
    return i*8 + j;
}

ui32 Set::get_maximum() {
    //- Handling the case of an empty set. This is just a provisional answer.
    if(container.length() == 0) {
        std::cout << "\n Trying to get the minimum of an empty set, returning zero.\n";
        return 0;
    }
    int i = container.length() - 1, j = 7;
    byte* elements = container.elements();
    byte selector = RIGTH_BIT;
    while(i >= 0 && elements == 0) i--;
    while((selector & elements[i]) == 0) {
        j--;
        selector <<= 1;
    }
    return i*8+j;
}

int Set::print(){
    std::cout << "{";
    //- Empty set.
    ui32 len = container.length();
    if(len == 0) {
        std::cout << "}";
        return 0;
    }
    ui32 n = 0,i,j;
    bool first = true;
    byte selector = LEFT_BIT;
    byte* elements = container.elements();
    for(i = 0; i < len; i++) {
        for(j = 0; j < 8; j++) {
            if((selector & elements[i]) != 0) {
                if(!first)
                    std::cout << ", ";
                first = false;
                std::cout << n;
            }
            selector >>= 1;
            n++;
        }
        selector = LEFT_BIT;
    }
    std::cout << "}";
    return 0;
}

//- Printing a line break after printing the set.
void Set::println() {
    print();
    std::cout << "\n";
}

//- Free the memory used by a set.
void Set::deleteSet() {
    container.deleteArray();
}

//- Deletes the right zero bytes of the container array.
//- This function leafs at leas one byte in the container array.
void Set::fit() {
    ui32 length = container.length(), i;
    byte *elements = container.elements();
    //- Length of the new container array (length is at list 1).
    while(length > 1 && elements[length - 1] == 0)
        length--;
    //- Creating new container with no right zeros (unless length == 1).
    byte *newElements = new byte[length];
    for(i = 0; i < length; i++)
        newElements[i] = elements[i];
    //- Releasing memory of old container.
    container.deleteArray();
    ByteArray newContainer(newElements,length);
    container = newContainer;
}

//- Returns a exact copy of this object.
Set copy(Set original) {
    ui32 length = original.container.length();
    byte *cont_copy = new byte[length],
    *elements = original.container.elements();
    for(ui32 i = 0; i < length; i++)
        cont_copy[i] = elements[i];
    Set _copy(cont_copy, length);
    return _copy;
}

//- Union of sets.
Set operator + (Set set1, Set set2) {
    Set result, smallSet;
    if(set1.container.length() > set2.container.length()) {
        result = copy(set1);
        smallSet = set2;
    } else {
        result = copy(set2);
        smallSet = set1;
    }
    for(ui32 i = 0; i < smallSet.container.length(); i++)
        result.container.elements()[i] |= smallSet.container.elements()[i];
    result.fit();
    return result;
}

//- Intersection of sets.
Set operator * (Set set1, Set set2) {
    Set result, bigSet;
    if(set1.container.length() < set2.container.length()) {
        result = copy(set1);
        bigSet = set2;
    } else {
        result = copy(set2);
        bigSet = set1;
    }
    for(ui32 i = 0; i < result.container.length(); i++)
        result.container.elements()[i] &= bigSet.container.elements()[i];
    result.fit();
    return result;
}

//- Returns true if the number belongs to the set, otherwise it returns false.
bool belongs(ui32 number, Set set) {
    ui32 bytesToTheRight = number/8, bitsToTheRight = number%8;
    if(bytesToTheRight >= set.container.length())
        return false;
    if(set.container.elements()[bytesToTheRight] & LEFT_BIT >> bitsToTheRight)
        return true;
    return false;
}











