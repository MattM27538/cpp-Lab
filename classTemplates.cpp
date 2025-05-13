#include <iostream>

template<typename T>
struct Point{
    T xCoordinate{0};
    T yCoordinate{0};
};

template<typename T, typename U>
struct Pair{
    T first{0};
    U second{0};
};

//Functions can work with class Template parameters.
template<typename T>
constexpr void printCoordinates(Point<T> point){
    // assert(point.xCoordinate>point.yCoordinate);
    std::cout<<"x-coordinate = "<<point.xCoordinate<<"\ny-coordinate = "<<point.yCoordinate<<"\n";
}

//Functions can work with class Template parameters with multiple types.
template<typename T,typename U>
constexpr auto maxPairMember(Pair<T,U> pair){
    return pair.first>pair.second?pair.first:pair.second;
}

int main(){
    //Prior to c++20 you must explicitly declare the typename T at declaration "<int>".
    constexpr Point<int> myPoint1{2,3};
    
    [[maybe_unused]] Point<float> myPoint2{6,3};

    constexpr Pair<int,double> myPair{3,4.5};

    //c++20 and forward you can use type deduction
    //Ex:Point myPoint1{2,3};

    printCoordinates(myPoint1);

    std::cout<<"Max element of pair is: "<<maxPairMember(myPair)<<"\n";
    return 0;
}

