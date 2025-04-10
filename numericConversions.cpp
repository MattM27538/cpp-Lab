#include <iostream>
#include <typeinfo>



int main(){
    //There are five basic types of numeric conversions:
    
    //1. Converting an integral type to any other integral type (excluding integral promotions):
    short myShort=3; // convert int to short.
    long myLong=3; // convert int to long.
    char myChar=myShort; // convert short to char.
    unsigned int myUInt=3; // convert int to unsigned int.

    //2. Converting a floating point type to any other floating point type (excluding floating point promotions):
    float myFloat=3.0; // convert double to float.
    long double myLongDouble=3.0; // convert double to long double.

    //3. Converting a floating point type to any integral type:
    int myInt=3.5; // convert double to int.

    //4. Converting an integral type to any floating point type:
    double myDouble=3; // convert int to double.

    //5. Converting an integral type or a floating point type to a bool:
    bool myBool=3; // convert int to bool.
    bool myBool2=3.0; // convert double to bool.

    //Numeric conversions fall into three general safety categories:

    //1. Value-preserving conversions are safe numeric conversions where the destination type can 
    //   exactly represent all possible values in the source type.
    short myShort2={5};
    double myDouble2=2; // okay, produces double value 5.0.

    //2. Reinterpretive conversions are unsafe numeric conversions where the converted value 
    //   may be different than the source value, but no data is lost. Signed/unsigned conversions fall into this category.
    int myInt2={-5};
    unsigned int myUInt2={myInt2}; // bad: will result in large integer outside range of signed int.

    //3. Lossy conversions are unsafe numeric conversions where data may be lost during the conversion.
    int myInt3=3.5; // data lost: double will be converted to int value 3 (fractional value 0.5 lost).
    float myFloat2=1.23456789; // data lost: double will be converted to float 1.23457 (precision lost).

    return 0;
}