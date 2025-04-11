#include <iostream>
#include <typeinfo>
#include <vector>
#include <utility>

int main(){
    //"using" is a keyword that creates an alias for an existing data type.
    using Miles=int;
    Miles myMiles={25};

    //Note how printing the type of miles outputs int(i);
    std::cout<<"The type of miles is "<<typeid(myMiles).name()<<"\n";

    //Type alias identifiers follow the same scoping rules as variable identifiers
    {
        using MyFirstInitial=char;
        MyFirstInitial myFirstInitial={'M'};
        std::cout<<"MyFirstInitial = "<<myFirstInitial<<"\n";
    }
    // This would cause an compile error because MyFirstInitial is now out of scope.
    // std::cout<<"MyFirstInitial = "<<myFirstInitial<<"\n";

    /*A typedef is an older way of creating an alias for a type(Typedefs are still in C++ 
    * for backwards compatibility reasons but should otherwise be generally be avoided). 
    */
    typedef short MyShortTypeDef;
    MyShortTypeDef age={3};

    std::cout<<"The type of age = "<<typeid(age).name()<<"\n";

    //Aliases are great for making complex types easier to read.
    using VectorPairCharInt=std::vector<std::pair<char,int>>;
    
    std::pair myPair=std::make_pair<char,int>('a',1);
    std::pair myPair2=std::make_pair<char,int>('b',2);

    VectorPairCharInt myVectorOfPairs={myPair,myPair2};

    std::cout<<"The elements of myVectorOfPairs are ";
    for(const std::pair<char,int> &mypair:myVectorOfPairs){
        std::cout<<"<"<<mypair.first<<" , "<<mypair.second<<">"<<" ";
    }

    return 0;
}