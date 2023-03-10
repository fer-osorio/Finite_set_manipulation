//- Class that encapsulate an array of bytes and its length.
#include<cstdlib>
#include<iostream>
#define SIZE_ARRAY(array) sizeof(array)/sizeof(array[0])

typedef unsigned char byte;
typedef unsigned int ui32;

class ByteArray {
    byte* Elements;
    ui32 Length;

    public:
    //- Constructors.
    //- Initializing elements with null pointer.
    ByteArray();
    //- Initializing array of bytes (unsigned char) with _length elements. The default value for all the elements is zero.
    ByteArray(ui32 _length);
    //- Initializing with an  array. Elements<-array and Length<-sizeof(arr).
    ByteArray(byte* arr,ui32 _length);

    //- Return attributes.
    byte* elements();
    ui32 length();
    
    //- Delete array.
    void deleteArray();
};

//- Prints a unsigned integer in binary base.
void printBinary(byte number);

//- Prints the unsigned integers in an array in binary base.
void printBinary(byte* array, ui32 length);

//- Maximum number of an unsigned integer array.
ui32 max(ui32* arr, ui32 length);

//- Maximum number of two unsigned integers.
ui32 max(ui32 num1, ui32 num2);

//- Minimum number of two unsigned integers.
ui32 min(ui32 num1, ui32 num2);

//- Rotation operation over a byte
byte RotRight(byte x, ui32 n);

//- Returns the complement of a byte, that is, interchange the ones by zeros and the zeros by ones.
byte byteComplement(byte x);








