#include <iostream>
#include <string>

void print(int x){
    std::cout<<x<<"\n";
}

int main(){

    constexpr double myDouble={5.0};

    //Will cause compiler warning as implicit conversion from double to int will cause loss of data.
    //Also note this conversion creates a copy with the new data type it doesn't change the original var's type.
    print(myDouble);

    //Explicit type conversion.
    print(static_cast<int>(myDouble));


    constexpr uint8_t myFixedWidth={65};

    //Prints out 'A' as uint_8t tends to act as char.
    std::cout<<myFixedWidth<<"\n";
    
    //To print value you can cast to int.
    std::cout<<static_cast<int>(myFixedWidth)<<"\n";

    //Cast only works for related types. The following will not work.
    // std::string myString={"Hello World"};
    // int myInt=static_cast<int>(myString);

    return 0;
}