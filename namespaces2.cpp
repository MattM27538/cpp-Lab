#include <iostream>

/*Unnamed namespaces have internal linkage by default and are treated
 as if they are a part of their parent namespace.
*/
namespace{
    void doSomething(){
        std::cout<<"Called from unnamed namespace\n";
    }
}

/*Much like an unnamed namespace, anything declared inside an inline
  namespace is considered part of the parent namespace. However, unlike
  unnamed namespaces, inline namespaces don’t affect linkage.
 
  Note: the above unnamed namespace and MyInlineNamespace share the same
  scope so similar func signatures will create a compile error.
*/
inline namespace MyInlineNamespace{
    // This would cause a compile error due to function call ambiguity.
    // void doSomething(){
    //     std::cout<<"Called from unnamed namespace\n";
    // }

    constexpr int myNamespaceInt={0};
}

/*A namespace can be both inline and unnamed.
  Note: You cannot have an unnamed namespace and an inline unnamed
  namespace in the same translational unit. Creates compiler error
  due to having two different types of anonymous namespaces but you
  can have two of the same type of anonymous namespace e.g.
  2 unnamed namespaces or two inline unnamed namespaces.
*/

// inline namespace{
//     void doSomethingV2(){
//         std::cout<<"Called from inline unnamed namespace\n";
//     }
// }

/* You can also nest an anonymous namespace inside an
   inline namespace. This the effect: all functions inside the
   anonymous namespace have internal linkage by default but still gives
   you an explicit namespace name you can use.
*/

inline namespace MyNestedNamespace{
    namespace{
        void doSomethingV2(){
            std::cout<<"Called from nested unnamed namespace\n";
        }
    }
}


int main(){
    /*Calling doSomething() calls the function from the unnamed namespace
      as it is treated as though it were part of its parent namespace
      i.e. the global namespace.
    */
    doSomething();

    //Uncomment inline unnamed namespace and comment out unnamed namespace to use.
    // doSomethingV2();

    std::cout<<"myNamespaceInt = "<<myNamespaceInt<<"\n";

    MyNestedNamespace::doSomethingV2();
    return 0;
}