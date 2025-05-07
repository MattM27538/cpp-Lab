#include <iostream>
#include <string_view>

//Unscoped enum for example.
namespace HairTraits{
    enum HairColor{
        black,
        brown,
        red,
        blonde,
    };
}

constexpr std::string_view getHairColor(HairTraits::HairColor hairColor){
    switch(hairColor){
        case HairTraits::black: return "black";
        case HairTraits::brown: return "brown";
        case HairTraits::red: return "red";
        case HairTraits::blonde: return "blonde";
        default: return "invalid input"; 
    }
}

//Example of overloaded << operator.
// std::ostream is the type of std::cout, std::cerr, etc...
// The return type and parameter type are references (to prevent copies from being made)
std::ostream& operator<<(std::ostream& out, HairTraits::HairColor hairColor){
    return out<<getHairColor(hairColor);
}

int main(){
    HairTraits::HairColor myHairColor{HairTraits::black};

    std::cout<<"myHairColor = "<<myHairColor<<"\n";

    return 0;
}

