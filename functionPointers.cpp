#include <cstdlib>
#include <iostream>

int foo() {
    return 2;
}

int foo2() {
    return 3;
}

int main(){
    //Points to function foo. Can also point to any other function of
    //matching type(returns int takes no parameters).
    int (*funcPtr)(){foo};

    funcPtr=&foo2; //funcPtr now points to foo2.

    (*funcPtr)(); //Call foo2 via explicit dereference.

    funcPtr(); //Call foo2 via implicit dereference. Not possible with all compilers.

    std::cout<<"funcPtr call returns "<<funcPtr()<<"\n";

    return EXIT_SUCCESS;
}