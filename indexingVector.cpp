#include <iostream>
#include <vector>
#include <typeinfo>

int main(){
    std::vector<int> myVector(5);
    std::vector<int> myVector2{0,1,2,3,4};
    
    //Indexing the underlying C-style array
    for(auto index{std::ssize(myVector)-1};index>=0;--index){
        std::cout<<"myVector index "<<index<<"= "<<myVector.data()[index]<<"\n";
    }
    
    for(auto index{std::ssize(myVector2)-1};index>=0;--index){
        std::cout<<"myVector2 index "<<index<<"= "<<myVector2.data()[index]<<"\n";
    }

    //Iterating forward
    for(std::size_t i{0};i<myVector.size();++i){
        std::cout<<"type of i size_t= "<<typeid(i).name()<<"\n";
    }
    
    //Alternative way to iterate forward
    for(decltype(std::ssize(myVector)) i{0};i<std::ssize(myVector);++i){
        std::cout<<"type of i decltype(std::ssize(myVector)) = "<<typeid(i).name()<<"\n";
    }

    auto mySSize{std::ssize(myVector)};
    
    std::cout<<"type of mySSize = "<<typeid(mySSize).name()<<"\n";

    
    std::cout<<"myVector.data() = "<<myVector.data()<<"\n";

    return 0;
}