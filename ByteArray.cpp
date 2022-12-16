//- Class that encapsulate an array of bytes and its length.

#include"ByteArray.hpp"

ByteArray::ByteArray() {
    Elements = nullptr;
    Length = 0;
}

ByteArray::ByteArray(ui32 _length) {
    if(_length == 0)
        Elements = nullptr;
    else
        Elements = new byte[_length];
    
    Length = _length;
}

ui32 ByteArray::length() {
    return Length;
}

byte* ByteArray::elements() {
    return Elements;
}