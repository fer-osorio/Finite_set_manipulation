//- Class that encapsulate an array of bytes and its length.

#include"ByteArray.hpp"

ByteArray::ByteArray() {
    Elements = nullptr;
    Length = 0;
}

//- Initializing array of bytes (unsigned char) with _length elements. The default value for all the elements is zero.
ByteArray::ByteArray(ui32 _length) {
    if(_length == 0) {
        Elements = nullptr;
        Length = 0;
    }
    else {
        Elements = new byte[_length];
        //- Initializing array with zeros.
        for(int i = 0; i < _length; i++)
            Elements[i] = 0;
        
        Length = _length;
    }
}

ByteArray::ByteArray(byte* arr, ui32 _length) {
    Elements = arr;
    Length = _length;
}

ui32 ByteArray::length() {
    return Length;
}

byte* ByteArray::elements() {
    return Elements;
}

void ByteArray::deleteArray(){
    delete[] Elements;
    Length = 0;
}

//- Prints a unsigned integer in binary base.
void printBinary(byte number) {
    //- Binary representation.
    byte* bin_rep = new byte[8];
    byte residue;
    int i;
    for(i = 7; i >= 0; i--) {
        residue = number % 2;
        //- Saving binary digits in bin_rep.
        bin_rep[i] = residue;
        number -= residue;
        number /= 2;
    }
    //- Printing.
    for(i = 0; i < 8; i++)
        std::cout << static_cast<ui32>(bin_rep[i]);
    delete [] bin_rep;
}

void printBinary(byte* array,ui32 length) {
    std::cout << "{";
    for(ui32 i = 0; i < length; i++ ) {
        if(i) std::cout << ", ";
        printBinary(array[i]);
    }
    std::cout << "}";
}














