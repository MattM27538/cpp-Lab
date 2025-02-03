#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;


int main(){
    //Review raw pointers
    int *rawPointer=new int{5};

    //Print pointer value
    cout << "rawPointer value = " << *rawPointer << endl;

    //Print pointer address
    cout << "rawPointer address = " << rawPointer << endl;

    //Sizeof pointer

    cout << "rawPointer size = " << sizeof(rawPointer) << endl;

    //Delete pointer
    delete(rawPointer);

    //Note: if you throw before you delete pointer function will end and you will create a memory leak.
    
    
    /*Review smart pointers: unique_ptr, shared_ptr, and weak_ptr. Ensure the dynamically allocated 
      object is properly cleaned up at the appropriate time.
    */

    /*Unique_ptr can only have one owner. std::unique_ptr is smart enough to know whether to use 
    scalar delete or array delete, so std::unique_ptr is okay to use with both scalar objects and arrays.
    However, std::array or std::vector (or std::string) are almost always better choices than using 
    std::unique_ptr with a fixed array, dynamic array, or C-style string.


    Best practice:
    Favor std::array, std::vector, or std::string over a smart pointer managing a fixed array, 
    dynamic array, or C-style string.

    There are two easy ways to misuse std::unique_ptrs, both of which are easily avoided. 
    First, don’t let multiple objects manage the same resource:
        Resource* res{ new Resource() };
        std::unique_ptr<Resource> res1{ res };
        std::unique_ptr<Resource> res2{ res };
    Second, don’t manually delete the resource out from underneath the std::unique_ptr:
        Resource* res{ new Resource() };
        std::unique_ptr<Resource> res1{ res };
        delete res;
    Both result in undefined behavior as already deleted resoures will be (attempted to be)
    deleted again.
    */

    unique_ptr<int>uniPtr1=make_unique<int>(7);

    //Print unique pointer value
    cout << "unique Pointer value = " << *uniPtr1 << endl;

    //Print unique pointer address using .get() method.
    cout << "unique Pointer address = " << uniPtr1.get() << endl;

    //Sizeof unique pointer
    cout << "unique Pointer size = " << sizeof(uniPtr1) << endl;

    //Unique ptrs cannot be shared. This will create compile error.
    //Unique_ptr<int>uniPtr2=uniPtr1;

    //To change ownership use the move member function.
    unique_ptr<int>uniPtr2=move(uniPtr1);

    //Print value of uniPtr2
    cout << "unique Pointer 2 value = " << *uniPtr2 << endl;

    //std::unique_ptr has a cast to bool that returns true if the std::unique_ptr is managing a resource.
    if(uniPtr1){
    cout << "(uniPtr1) is managing a resource."  << endl;
    } else {
    cout << "(uniPtr1) is not managing a resource."  << endl;
    }

    if(uniPtr2){
    cout << "(uniPtr2) is managing a resource."  << endl;
    } else {
    cout << "(uniPtr2) is not managing a resource."  << endl;
    }
    

    // uniPtr2 object deallocated here.
    return 0;

}