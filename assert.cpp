#include <cassert>
#include <iostream>


int main(){
    int x={5};
    int y={10};
    int z={3};
    double myDouble={2.1};

    //Test assert, result is true.
    assert(y>x);
    
    //Print to console to confirm success.
    std::cout << "First assert passed." << std::endl;
    
    //Test assert, result is false. Remove the line below to test the rest of the code.
    // assert(y<myDouble);

    //Fail to print to console to confirm second assert failure.
    std::cout << "Second assert passed. (This should not print)" << std::endl;

    int myArray[] ={0,1,2,3};

    //Test static_assert. Evaluated at compile time. Size of array is 16bytes. Compilation will fail.
    static_assert(sizeof(myArray)<4,"Static assert failure. Size of array is greater than 4.");

    return 0;
}