//- Class that encapsulate an array of bytes and its length.
#include<iostream>
typedef unsigned char byte;
typedef unsigned int ui32;

class ByteArray {
    byte* Elements;
    ui32 Length;

    public:
    //- Constructors.
    ByteArray();
    ByteArray(ui32 _length);

    //- Return attributes.
    ui32 length();
    byte* elements();
    
    //- Delete array.
    void deleteArray();
};