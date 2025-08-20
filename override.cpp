#include <string_view>

// override - The C++ standard calls them “identifiers with special meaning”, but they are 
// often referred to as “specifiers”.

/*To help address the issue of functions that are meant to be overrides but aren’t, the 
  override specifier can be applied to any virtual function to tell the compiler to enforce 
  that the function is an override. The override specifier is placed at the end of a member
  function declaration (in the same place where a function-level const goes). If a member 
  function is const and an override, the const must come before override.
*/

/*Because there is no performance penalty for using the override specifier and it helps 
  ensure you’ve actually overridden the function you think you have, all virtual override 
  functions should be tagged using the override specifier. Additionally, because the override 
  specifier implies virtual, there’s no need to tag functions using the override specifier 
  with the virtual keyword.
*/

class Base{
    public:
        virtual std::string_view getClassName() const{
            return "Base";
        }

        virtual std::string_view getClassNameV2() const{
            return "Base";
        }

};

class Dervied : public Base{
    public:
        // This member function will not compile because it is not const and so won't override 
        // Base::getClassName.

        // std::string_view getClassName() override{
        //     return "Derived";
        // }

        /*Best practice: Use the virtual keyword on virtual functions in a base class.
          Use the override specifier (but not the virtual keyword) on override functions in derived 
          classes. This includes virtual destructors.
        */
        std::string_view getClassNameV2() const override {
            return "Derived";
        }
};


int main(){

    return 0;
}