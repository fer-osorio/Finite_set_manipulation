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
    //- Initializing array of bytes (unsigned char) with _length elements. The default value for all the elements is zero.
    ByteArray(ui32 _length);

    //- Return attributes.
    ui32 length();
    byte* elements();
    
    //- Delete array.
    void deleteArray();
};