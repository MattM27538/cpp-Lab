#include <iostream>
#include <typeinfo>

void printNumericPromotion(int x){
    std::cout << "Promoted type is now: "<<typeid(x).name()<<"\n";
    std::cout<<x<<"\n";
}

void printFloatingPointPromotion(float f){
    std::cout << "Promoted type is now: "<<typeid(f).name()<<"\n";
    std::cout<<f<<"\n";
}

/*
A numeric promotion is\nthe type conversion of certain narrower numeric types (such as a char) 
to certain wider numeric types (typically int or double) that can be processed efficiently.
*/
int main(){
    char myChar={'d'};
    unsigned char myUnsignedChar={'d'};
    bool myBool={false};

    //myChar gets promoted from signed char to int.
    std::cout<<"Type of var is: "<<typeid(myChar).name()<<"\n";
    printNumericPromotion(myChar);

    //myUnsigned Char gets promoted from unsigned char to int.
    std::cout<<"Type of var is: "<<typeid(myUnsignedChar).name()<<"\n";
    printNumericPromotion(myUnsignedChar);

    //myBool gets promoted from bool to int.
    std::cout<<"Type of var is: "<<typeid(myBool).name()<<"\n";
    printNumericPromotion(myBool);
    
    //Double gets promoted from double to float.
    std::cout<<"Type of var is: "<<typeid(15.0).name()<<"\n";
    printFloatingPointPromotion(15.0f);

    //Note: While integral promotion is value-preserving, it does not necessarily preserve the signedness (signed/unsigned) of the type.
    return 0;
}