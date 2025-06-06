#include <iostream>

class MyClass1{
    public:
        //  static member variables are shared by all objects of the class.
        //  static members are global variables that live inside the scope region of the class.
        /*  static members exist even if no objects of the class have been instantiated.
            hey are created at the start of the program and destroyed at the end 
            of the program, so their lifetime is not bound to a class object 
            like a normal member.
        */ 
        static int m_myStaticInt;

        /*  when the static member is a constant integral type (which includes char and bool) 
            or a const enum, the static member can be initialized inside the class definition
            because the static member variable is a const int, no explicit definition line is
            needed. This shortcut is allowed because these specific const types are 
            compile-time constants.
        */
        static inline bool m_myStaticBool{true};

        /*  Because constexpr members are implicitly inline (as of C++17), static constexpr
            members can also be initialized inside the class definition without explicit use 
            of the inline keyword
        */
        //  Best practice :Make your static members inline or constexpr so they can be 
        //  initialized inside the class definition.

        static constexpr int myConstexprInt{4};

        //Only static members may use type deduction
        static constexpr auto myStaticAutoInt{1};
};

//  Best practice: Access static members using the class name and the scope resolution operator (::).
/*  Note that this static member definition is not subject to access controls: you can define and
    initialize the value even if it’s declared as private (or protected) in the class (as definitions
    are not considered to be a form of access).*/

    //You can only initialize non const static members outside of class definition.
int MyClass1::m_myStaticInt{2};

int main(){
    std::cout<<"MyStaticInt = "<<MyClass1::m_myStaticInt<<"\n";
    
    ++MyClass1::m_myStaticInt;

    std::cout<<"MyStaticInt = "<<MyClass1::m_myStaticInt<<"\n";

    return 0;
}