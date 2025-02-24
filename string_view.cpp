#include <iostream>
#include<string>

void print_string_view(std::string_view str){
    //parameter str is initialized from strView. This allows access “Hello, world!”
    //through str, again without making a copy of the string.
    std::cout<<"Initial string_view = "<<str<<"\n";
}

int main(){
    // Initialize string_view. String_view provides read-only access to an existing string
    // (a C-style string, a std::string, or another std::string_view) without making a copy.
    std::string_view strView={"Hello World!"};

    print_string_view(strView);
    
    //Note you can reassign string_view. If the original "Hello World!" was a string var reassignment would not affect that var.
    strView="hello";

    std::cout<<"new string_view = "<< strView<<"\n";

    //String_view can we initialized from std::string
    const std::string strToStrView={"assign string to string_view test successful"};
    std::string_view strView2={strToStrView};
    std::cout<<"strView2 = "<<strToStrView<<"\n";
    
    //String_view can we initialized from std::string_view
    const std::string_view strViewToStrView={"assign string_view to string_view test successful"};
    std::string_view strView3={strViewToStrView};
    std::cout<<"strView3 = "<<strView3<<"\n";

    //Unlike string string_view can we used as a constexpr
    constexpr std::string_view strView4={"constexpr string_view test successful"};
    //No compile error.

    std::cout<<strView4<<"\n";

    return 0;
}