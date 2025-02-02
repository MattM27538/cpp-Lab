#include <iostream>

using std::cout;
using std::endl;

struct myStruct{

};

struct myStructWithIntMember{
    int intmember={6};

};

struct myStructWithIntMemberAndChar{
    int intMember={7};
    char charMember1={'l'};
};

struct myStructWith2CharMembers{
    char charMember2={'l'};
    char charMember3={'l'};
};

struct myStructWithCharAnd2IntMembers{
    int intMember2={8};
    char charMember4={'l'};
    int intMember3={9};
};

int main(){
    //Test size of to see sizes of different data types
    //int
    int x={5};
    cout << "Size of int is " << sizeof(x) << " bytes" << endl;

    cout << "Size of empty struct is " << sizeof(myStruct) << " bytes" << endl;

    long long longlongTest={5};
    cout << "Size of long long is " << sizeof(longlongTest) << " bytes" << endl;
    
    cout << "Size of struct with 1 int member is " << sizeof(myStructWithIntMember) << " bytes" << endl;

    //Note the struct is 8 bytes even though int takes 4bytes and char usually takes 1byte. This is because 
    //sizeof gives you the size of the struct, not the sum of the sizes of its members. Due to alignment requirements 
    //(ints generally like to be aligned on natural boundaries; 4 bytes on most platforms), the compiler will pad the 
    // struct to 12 bytes, so that when you have multiple instances of the struct adjacent to each other 
    // (e.g. in an array), they stay correctly aligned.
    cout << "Size of struct with 1 int member and 1 char member is " << sizeof(myStructWithIntMemberAndChar) << " bytes" << endl;

    //Note the struct is only 2 bytes when there are only two char members in the struct.
    cout << "Size of struct with 2 char members is " << sizeof(myStructWith2CharMembers) << " bytes" << endl;
    
    cout << "Size of struct with 2 int members and 1 char member is " << sizeof(myStructWithCharAnd2IntMembers) << " bytes" << endl;
}