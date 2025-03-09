#include <iostream>
#include <string>

int uniqueID(){
    /* Non-const static local variables should generally be avoided.\nIf you do use them, 
       ensure the variable never needs to be reset, and isn't used to alter program flow."
    */
   
    //Static local variable is only initialized once, has block scope, but lives the entire life span of the program.
    static int s_itemID={0};
    return s_itemID++; // makes copy of s_itemID, increments the real s_itemID, then returns the value in the copy
}

std::string databaseName(){
    std::cout<<"Grabbed name from database"<<"\n";
    return "Martha Mahon";
}

std::string_view getNameFromDatabase(){
    /*One good use for a const static local variable is when you have a function that needs to use a const value, 
      but creating or initializing the object is expensive (e.g. you need to read the value from a database).*/
    
    /*Ex:
      Initialize string by getting value from database. It is very expensive to copy a string, here you only need to
      copy the string once. Then you can use it anytime you recall the function to perform actions.*/
    static const std::string databaseString={databaseName()}; 


    //Convert string to string_view because string will not be altered and it is much more efficient to use string_view.
    static const std::string_view databaseNameView={databaseString};
    
    return databaseNameView;
}

int main(){
    //Static local variables that have no initializer or a non-constexpr initializer are zero-initialized at program start
    static int myInt;

    std::cout<<"Pre-definition myInt = "<<myInt<<"\n";
    
    myInt={2};
    
    std::cout<<"Post-definition myInt = "<<myInt<<"\n";

    std::cout<<"Item 1 ID = "<<uniqueID()<<"\n";
    std::cout<<"Item 2 ID = "<<uniqueID()<<"\n";
    std::cout<<"Item 3 ID = "<<uniqueID()<<"\n";

    //databaseName() will only be called once.
    getNameFromDatabase();
    getNameFromDatabase();
    
    //Print the value to screen for the last call.
    std::cout<<getNameFromDatabase()<<"\n";
    return 0;
}