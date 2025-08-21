#include <string_view>

/*In the case where you don’t want someone to be able to override a virtual function, or inherit
  from a class. The final specifier can be used to tell the compiler to enforce this. If the user
  tries to override a function or inherit from a class that has been specified as final, the 
  compiler will give a compile error.
*/

class Base{
    public:
        virtual std::string_view getClassName() const{
            return "Base";
        }
};

class Derived: public Base{
    public:
        std::string_view getClassName() const override final{
            return "Derived";
        }
};

class DerivedV2: public Derived{
    public:
        /*This causes a compilation error as Derived::getClassName cannot
          be overridden by DerivedV2::getClassName as Derived::getClassName
          is marked as final.
        */
        // std::string_view getClassName() const override {
        //     return "DerivedV2";
        // }
};

int main(){
    return 0;
}

