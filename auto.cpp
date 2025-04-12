#include <iostream>
#include <typeinfo>
#include <string_view>
#include <vector>

std::string_view getHelloWorld(){
    constexpr std::string_view myStringView{"Hello World"};
    return myStringView;
}

int main(){
    //Type deduction (also sometimes called type inference) is a feature that allows 
    //the compiler to deduce the type of an object from the object’s initializer.
    auto myAutoVar1{2};

    std::cout<<"Type of myAutoVar1{2} = "<<typeid(myAutoVar1).name()<<"\n";
    
    //Because function calls are valid expressions, we can even use type deduction when our initializer is a non-void function call.
    auto myAutoVar2{getHelloWorld()};
    
    std::cout<<"Type of myAutoVar2{getHelloWorld()} = "<<typeid(myAutoVar2).name()<<"\n";
    
    //Literal suffixes can be used in combination with type deduction to specify a particular type.
    //Deduces float instead of default double.
    auto myAutoVar3{1.23f};
    
    std::cout<<"Type of myAutoVar3{1.23f} = "<<typeid(myAutoVar3).name()<<"\n";

    //Type deduction drops const from the deduced type. You have to readd it yourself when deducing type.
    constexpr auto myInt{3};

    [[maybe_unused]] const auto myAutoVar4{myInt};


    //Prefer auto for ranged for loops to prevent type conversions
    std::vector<double> myVector{1.1,2.1,3.2};

    //Not using auto causes val to be converted from double to int outputting incorrect values.
    std::cout<<"Values from const int &val:myVector: ";
    for(const int val:myVector){
        std::cout<<val<<" ";
    }
    std::cout<<"\n";
    
    //Using auto prevents unintended conversion from double to int outputting the correct values.
    std::cout<<"Values from const auto &val:myVector: ";
    for(const auto &val:myVector){
        std::cout<<val<<" ";
    }
    std::cout<<"\n";

    /*
    *Best practice: Use type deduction for your variables when the type of the object doesn't matter. 
    *Favor an explicit type when you require\na specific type that differs from the type of the initializer, 
    *or when your object is used in a context where making the type obvious is useful."
    */

    return 0;
}