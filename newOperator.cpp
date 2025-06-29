#include <cstdlib>
#include <iostream>

int main(){
    /*To allocate a single variable dynamically, we use the scalar (non-array) form of the new 
      operator. The new operator creates the object using that memory, and then returns a 
      pointer containing the address of the memory that has been allocated.
    */
    int* myPtr{new int{5}};

    std::cout<<"Address of myPtr after initialization = "<<&myPtr <<"\n";
    
    //Reassign dynamic variable. Note how address doesn't change.
    *myPtr=7;
    std::cout<<"Address of myPtr after reassignment = "<<&myPtr <<"\n";

    /*When we are done with a dynamically allocated variable, we need to explicitly tell C++ to
    free the memory for reuse. For single variables, this is done via the scalar (non-array) 
    form of the delete operator:
    */
    delete myPtr; // return the memory pointed to by myPtr to the operating system.
    myPtr=nullptr; // set ptr to be a null pointer as accessing it now would be undefined behavior (dangling pointer).
   
    /*Best practice: Deleting a null pointer is okay, and does nothing. There is no need to 
    conditionalize your delete statements.
    */
    delete myPtr;

    return EXIT_SUCCESS;
}