#include <iostream>

int main(){
    //Note references are not objects they are merely aliases.

    //Modifiable values can be const referenced but they may not be changed
    //though the const l value reference.
    auto myInt{5};
    const int& myIntRef{myInt};

    std::cout<<"myIntRef = "<<myIntRef<<"\n";

    //This would cause an error.
    // myIntRef=6;

    /*Favor lvalue references to const over lvalue references to non-const
    * unless you need to modify the object being referenced.
    */
   
    /*Lvalues references to const can also bind to rvalues
    * When this happens, a temporary object is created and initialized with
    * the rvalue, and the reference to const is bound to that temporary object.
    * The lifespan of the temporary object increases to the lifetime of the reference.
    */

    [[maybe_unused]]const auto& myBoolRef2{true};

    /*If you try to bind a const lvalue reference to a value of a different type,
    * the compiler will create a temporary object of the same type as the reference,
    * initialize it using the value, and then bind the reference to the temporary.
    */
    auto myChar{'b'};
    const int& myCharToInt{myChar};

    //Note: this will print out the char to int conversion of 98.
    std::cout<<"myCharToInt = "<<myCharToInt<<"\n";

    /* Note: Normally a reference is identical to the object it is bound
    to but this does not apply when a reference is bound to a temporary copy
    of the object or a temporary resulting from the conversion of the object instead.
    Any modifications subsequently made to the original object will not be seen by the
    reference (as it is referencing a different object), and vice-versa.
    */


    return 0;
}