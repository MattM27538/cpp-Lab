#include <iostream>
#include <algorithm>

struct MyStruct{
    int structInt1{};
    int structInt2{};
    bool structBool{true};

    //Member functions can be constexpr.
    constexpr int greaterInt() const{
        return std::max(structInt1,structInt2);
    }
};

class MyClass{
    public:
        //constructors must be constexpr if you want to create constexpr classes.
        constexpr MyClass():classInt1{},classInt2{}
        {}

        constexpr int getclassInt1() const{
            return classInt1;
        }
        
    private:
        int classInt1{0};
        int classInt2{2};
};

int main(){
    //aggregates can be constexpr.
    constexpr MyStruct myStruct1{0,2};
    constexpr int greaterInt{myStruct1.greaterInt()};

    std::cout<<"greater Int member in myStruct1 = "<<greaterInt<<"\n";

    MyClass myClass1{};

    std::cout<< "myClass1.classInt1 = "<<myClass1.getclassInt1()<<"\n";
    return 0;
}