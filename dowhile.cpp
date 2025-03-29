#include <iostream>

/*
In practice, do-while loops aren’t commonly used. Having the condition at 
the bottom of the loop obscures the loop condition, which can lead to errors.
Many developers recommend avoiding do-while loops altogether as a result.
Favor while loops over do-while when given an equal choice.
*/

int main(){
    int myNumber={};

    do
    {   
        std::cout<<"Enter a number between 1 and 4"<<"\n";
        std::cin>>myNumber;
    } while (myNumber>4 || myNumber<1);
    
    return 0;
}