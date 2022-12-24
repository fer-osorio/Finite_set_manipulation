//- Class that encapsulate an array of bytes and its length.

#include"ByteArray.hpp"

ByteArray::ByteArray() {
    Elements = nullptr;
    Length = 0;
}

//- Initializing array of bytes (unsigned char) with _length elements. The default value for all the elements is zero.
ByteArray::ByteArray(ui32 _length) {
    if(_length == 0)
        Elements = nullptr;
    else
        Elements = new byte[_length];
    //- Initializing array with zeros.    
    for(int i = 0; i < _length; i++)
        Elements[i] = 0;
        
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
















