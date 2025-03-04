#include <iostream>

void print(){
    std::cout<<"world!\n";
}

//Example of user defined namespace.
namespace MyNamespace1{
    /*  NOTE: if you don't forward declare MyNamespace1::print before printHelloWorld() the compiler will
        not check past printHelloWorld() for the MyNamespace1::print function. */
    void print(){
        std::cout<<"Hello ";
    }

    void printHelloWorld(){
        /*  If the identifier inside a namespace is called it will check within the namespace first for the identifier,
            the compiler will then check each containing namespace in sequence to see if a match is found,
            lastly the global namespace will be checked for the identifier. In this case a global identifier is found. */
        print();
        //If left side of scope resolution operator(::) is left empty the compiler will check the global namespace for the identifier.
        ::print();
    }
}

//Example of nested namespace.
namespace MyNestedNamespace{
    void containingNamespace(){
        std::cout<<"Hello from the containing namespace!\n";
    }

    namespace MyInnerNamespace{
        void print(){
            std::cout<<"Hello from MyInnerNamespace\n";
        }

        void checkContainingNamespace(){
            containingNamespace();
        }
    }

    void print(){
        std::cout<<"Hello from MyNestedNamespace\n";
    }
}



int main(){
    //Examples of accessing different namespaces.
    MyNamespace1::printHelloWorld();
    MyNestedNamespace::print();
    MyNestedNamespace::MyInnerNamespace::print();

    /*  checkContainingNamespace will call containingNamespace(). Since there is no containingNamespace() in MyInnerNamespace MyNestedNamespace will be checked
        and a matching identifier will be found. */
    MyNestedNamespace::MyInnerNamespace::checkContainingNamespace();
   
    //Example of namespace alias. Outputs the same output as the previous statement.
    namespace myNamespaceAlias=MyNestedNamespace::MyInnerNamespace;
    myNamespaceAlias::checkContainingNamespace();

    return 0;
}
