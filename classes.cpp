#include <iostream>
#include <string>
class myClass{
    private:
    // Classes should generally make member variables private (or protected),
    // and member functions public.

    /*It is a common convention to name private data members starting with an “m_” prefix.
      The “m_” prefix allows us to easily differentiate data members from function
      parameters or local variables within a member function.The “m_” prefix also helps prevent
      naming collisions between private member variables and the names of local variables,
      function parameters, and member functions.
    */
    int m_classInt{25}; //default member initializer "25".
    bool m_classBool{true};
    std::string m_classString{"hello"};

    public:
    // Constructors have the same name as the class type and have no return type.

    //Member variables in a member initializer list should be listed in order
    //that they are defined in the class.

    //The rightmost parameters of constructors can have default arguments.
    myClass(int myInt,bool myBool):m_classInt{myInt},m_classBool{myBool}
    {}

    //Overloaded constructor, default value for m_classBool and m_classString will be used.
    myClass(int myInt):m_classInt{myInt}
    {}

    //getter
    constexpr int getClassInt(){
        return m_classInt;
    }

    /*
    Since member functions are always called on an object, and that object
    must exist in the scope of the caller, it is generally safe for a member
    function to return a data member by (const) lvalue reference (as the member
    being returned by reference will still exist in the scope of the caller when
     the function returns).
    */
    const std::string& getClassString(){
        return m_classString;
    }

    //
};

int main(){
    myClass myClass1{2};
    myClass myClass2{false};

    std::cout<<myClass1.getClassInt()<<"\n";
    std::cout<<myClass1.getClassString()<<"\n";
}