//-Representing a finite set of non-negative integer numbers.

#include"Set.hpp"

//- Constructor with no arguments. Returns the representation of an empty set with no container.
Set::Set() {
    container = ByteArray(0);
}

//- Constructor for an empty set with a container of 'length' bytes.
Set::Set(ui32 length) {
    container = ByteArray(length);
}

ui32 Set::get_minimum() {
    //- Handling the case of an empty set. This is just a provisional answer.
    if(container.Length == 0) {
        std::cout << "\n Trying to get the minimum of an empty set, returning zero.\n";
        return 0;
    }
    int i = 0, j = 0, len = container.length();
    int elements[] = container.elements();
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
    if(container.Length == 0) {
        std::cout << "\n Trying to get the minimum of an empty set, returning zero.\n";
        return 0;
    }
    int i = container.Length - 1, j = 7;
    int elements[] = container.elements();
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
    if(container.Length == 0) {
        std::cout << "}";
        return 0;
    }
    ui32 n = 0, i ,j;
    bool first = true;
    byte selector = LEFT_BIT;
    for(i = 0; i < container.Length; i++) {
        for(j = 0; j < 8; j++) {
            if(selector & container[i])
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













