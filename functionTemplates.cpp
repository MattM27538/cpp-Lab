#include <iostream>
#include<typeinfo>

/*A function template is a function-like definition that is used to generate
* one or more overloaded functions, each with a different set of actual types.
* The initial function template that is used to generate other functions is 
* called the primary template. For each type template parameter, we use the 
* keyword typename (preferred) or class, followed by the name of the type 
* template parameter whcih acts as a placeholder type(e.g. T).
*/

/*Function templates are not actually functions -- their code isn’t compiled or 
* executed directly. Instead, function templates have one job: to generate 
* functions (that are compiled and executed). A function template is only 
* instantiated the first time a function call is made in each translation unit.
* Further calls to the function are routed to the already instantiated function.
*/
template<typename T>
T square(T base){
    std::cout<<"type of base = "<<typeid(base).name()<<"\n";
    return base*base;
};

//Function templates can use both template and non-template parameters.
template<typename T>
double multiply(T operand1, double operand2){
    return operand1*operand2;
}

//You can delete function templates that would cause errors.
template<>
const char* square(const char* base)=delete;

int main(){
    constexpr int myInt{5};
    constexpr double myDouble{3.2};
    
    //Note how the the base variable in square prints as type int.
    square(myInt);

    //Note how the the base variable in square prints as type double.
    square(myDouble);

    std::cout<<"multiply 2*3.1 = "<<multiply(2,3.1)<<"\n";

    //This would cause a runtime error in output.
    // std::cout<<square("hello world")<<"\n";

    return 0;
}