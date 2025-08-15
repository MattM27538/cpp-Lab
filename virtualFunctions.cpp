#include <iostream>
#include <string_view>

class Base{
    public:
    /*A virtual function is a special type of member function that, when called, resolves to the 
      most-derived version of the function for the actual type of the object being referenced or 
      pointed to. A derived function is considered a match if it has the same signature (name, 
      parameter types, and whether it is const) and return type as the base version of the 
      function. Such functions are called overrides.
    */
        virtual std::string_view getClassType() const{
            return "Base";
        }

        std::string_view nonVirtualgetClassType() const{
            return "Base";
        }

        virtual std::string_view testImplicitVirtualgetClassType() const{
            return "Base";
        }
};

class Derived: public Base{
    public:
        virtual std::string_view getClassType() const{
            return "Derived";
        }

        std::string_view nonVirtualgetClassType() const{
            return "Derived";
        }

        virtual std::string_view testImplicitVirtualgetClassType() const{
            return "Derived";
        }
};

class DerivedV2: public Derived{
    public:
        virtual std::string_view getClassType() const{
            return "DerivedV2";
        }

        std::string_view nonVirtualgetClassType() const{
            return "DerivedV2";
        }
        
        virtual std::string_view testImplicitVirtualgetClassType() const{
            return "DerivedV2";
        }
};

int main(){
    /*Note that virtual function resolution only works when a virtual member function is called 
      through a pointer or reference to a class type object. This works because the compiler can
      differentiate the type of the pointer or reference from the type of the object being 
      pointed to or referenced. We see this in example above. Calling a virtual member function 
      directly on an object (not through a pointer or reference) will always invoke the member 
      function belonging to the same type of that object.
    */

    Derived derived{};

    Base* basePtr{&derived};

    std::cout << "basePtr is a " << basePtr->getClassType() << "\n";

    std::cout << "Calling non virtual getClassType() returns " << basePtr->nonVirtualgetClassType() << "\n";
    
    std::cout << "Calling implicit virtual getClassType() returns " << basePtr->testImplicitVirtualgetClassType() << "\n";

    /*Note that virtual function resolution only works when a virtual member function is called 
      through a pointer or reference to a class type object. This works because the compiler can 
      differentiate the type of the pointer or reference from the type of the object being pointed
      to or referenced. We see this in example above. Calling a virtual member function directly 
      on an object (not through a pointer or reference) will always invoke the member function 
      belonging to the same type of that object.
    */

    /*Rule: If a function is virtual, all matching overrides in derived classes are implicitly virtual.
      This does not work the other way around -- a virtual override in a derived class does not 
      implicitly make the base class function virtual.
    */

    //Best practice: Never call virtual functions from constructors or destructors.

    /*If you were to call a virtual function from the Base constructor, and Derived portion of the class 
      hadn’t even been created yet, it would be unable to call the Derived version of the function 
      because there’s no Derived object for the Derived function to work on. In C++, it will call the 
      Base version instead.
    */

    return 0;
}