#include <iostream>

/*When C++ constructs derived objects, it does so in phases. First, the most-base class
  (at the top of the inheritance tree) is constructed.\nThen each child class is constructed 
  in order, until the most-child class (at the bottom of the inheritance tree) is constructed last
*/

class Base{
    public:
    Base()=default;

    Base(int myInt): myBaseInt{myInt} {};

    int getMyBaseInt() const{
        return myBaseInt;
    }

    private:
        int myBaseInt;
};

/*When you inherit a base class publicly, inherited public members stay public, and inherited
  protected members stay protected. Inherited private members, which were inaccessible because 
  they were private in the base class, stay inaccessible.
*/
class Derived : public Base{
    public:
    Derived()=delete;

    //To set the value of a base class member call the constructor to the base class in the 
    //constructor of the derived class.
    Derived(int myBaseInt, int myDerivedInt): 
        Base{myBaseInt},    
        myDerivedInt{myDerivedInt}
        {};

    private:
        int myDerivedInt;

};

int main(){
    /*Note: public members can be accessed by anybody. Private members can only be accessed by
      member functions of the same class or friends. This means derived classes can not access 
      private members of the base class directly!
    */

    Derived myDerivedClass{2, 3};

    std::cout << "myBaseInt = " << myDerivedClass.getMyBaseInt() << "\n";

    /*When a member function is called on a derived class object, the compiler first looks to 
      see if any function with that name exists in the derived class. If so, all overloaded 
      functions with that name are considered, and the function overload resolution process is 
      used to determine whether there is a best match. If not, the compiler walks up the inheritance
      chain, checking each parent class in turn in the same way.
    */
    return 0;
}