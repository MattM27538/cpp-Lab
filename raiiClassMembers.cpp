#include <iostream>
#include <memory>

/*When constructors fail: Constructors are another area of classes in which exceptions can 
  be very useful. If a constructor must fail for some reason (e.g. the user passed in 
  invalid input), simply throw an exception to indicate the object failed to create. In
  such a case, the object’s construction is aborted, and all class members (which have 
  already been created and initialized prior to the body of the constructor executing) 
  are destructed as per usual. However, the class’s destructor is never called (because 
  the object never finished construction). Because the destructor never executes, you 
  can’t rely on said destructor to clean up any resources that have already been 
  allocated such as dynamic allocations.
*/

/*Fortunately, there is a better way. Taking advantage of the fact that class members 
  are destructed even if the constructor fails, if you do the resource allocations 
  inside the members of the class (rather than in the constructor itself), then those 
  members can clean up after themselves when they are destructed.
*/

class MyClass{
    public:
        MyClass()=default;

        MyClass(int myInt): m_myUniquePtr(std::make_unique<int>(myInt)){
            std::cout << "Attempting initialization of m_myUniquePtr.\n";

            throw "Throwing exception.\n";
        };

    private:
        //instead of this:  
        //int* ptr; // Foo will handle allocation/deallocation

        //Do this:
        std::unique_ptr<int> m_myUniquePtr;  // std::unique_ptr will handle allocation/deallocation
};

int main(){
    try{
        MyClass MyClass{2};
    }
    catch(const char* exceptionMessage){
        std::cerr << exceptionMessage << "m_myUniquePtr will now clean itself up.\n";
    }

    return 0;
}

