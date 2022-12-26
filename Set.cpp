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
Set::Set(ui32* elements) {
    //- Making an empty container big enough to contain all the numbers in the 'elements' array.
    ui32 size = max(elements)/8 + 1, i, j;
    byte* elemInSet = new byte[size];
    for( i = 0; i < size; i++)
        elemInSet[i] = 0;

    //- Placing the numbers inside the container of class ByteArray.
    size = sizeofArray(elements);
    ui32 bytesToTheRight, bitsToTheRight, selector;
    for(i = 0; i < size; i++) {
        bytesToTheRight = elements[i]/8;
        bitsToTheRight = elements[i]%8;
        selector = LEFT_BIT >> bitsToTheRight;
        elemInSet[bytesToTheRight] |= selector;
    }
    container = ByteArray(elemInSet);
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
        selector >> 1;
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
        selector << 1;
    }
    return i*8+j;
}

int Set::print(){
    std::cout << "{";
    //- Empty set.
    if(container.length() == 0) {
        std::cout << "}";
        return 0;
    }
    ui32 n = 0,i,j;
    bool first = true;
    byte selector = LEFT_BIT;
    byte* elements = container.elements();
    for(i = 0; i < container.length(); i++) {
        for(j = 0; j < 8; j++) {
            if(selector & elements[i])
                if(!first) {
                    std::cout << ", ";
                }
                std::cout << n;
            n++;
            first = false;
        }
    }
    std::cout << "}";
    return 0;
}

//- Returns the maximum number of an ui32 array.
ui32 Set::max(ui32 *arr) {
    ui32  maximum = arr[0], i;
    ui32 arr_size = sizeofArray(arr);
    for(i = 1; i < arr_size; i++)
        if(maximum < arr[i])
            maximum = arr[i];
    return maximum;
}











