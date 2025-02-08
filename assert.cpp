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
    
    //Test assert, result is false.
    assert(y<myDouble);

    //Fail to print to console to confirm second assert failure.
    std::cout << "First assert passed." << std::endl;
}