#include <iostream>
#include <string>
#include <string_view>

class Dog{
    public:
    //Nested enum inside of class. Classes can also be nested within other classes.
    //Nested type names must be fully defined before they can be used, so they are usually defined first.
    //Breed is typed as an enum rather than enum class so that the enum values lives in scope "Dog" not "Dog::Breed".
        enum Breed{
            unknown,
            chihuahua,
            corgi,
            terrier,
            mixed
        };

    //You can also use nested typedefs and aliases.
        using nestedInt=int;
        
        Dog()=default;
        
        Dog(Breed breed,std::string name,int age):m_breed{breed},m_name{name},m_age{age}
        {}
        

        std::string_view getBreed() const;
        std::string_view getName() const{return m_name;}
        nestedInt getAge() const{return m_age;}

    private:
        Breed m_breed{};
        std::string m_name{"unknown"};
        int m_age{};

};

std::string_view Dog::getBreed() const{
    switch(m_breed){
        case Dog::unknown :return "unknown";
        break;
        case Dog::chihuahua:return "chihuahua";
        break;
        case Dog::corgi :return "corgi";
        break;
        case Dog::terrier :return "terrier";
        break;
        case Dog::mixed :return "mixed";
        break;
    }

    return "Error: dog breed not found";
}

int main(){
    //Dog default constructor so all values are value initialized.
    Dog defaultDog{};
    std::cout<<"default constructed Dog breed = "<<defaultDog.getBreed()<<"\n";
    std::cout<<"default constructed Dog name = "<<defaultDog.getName()<<"\n";
    std::cout<<"default constructed Dog age = "<<defaultDog.getAge()<<"\n";
    
    //Must use Breed scope resolution operator to access breed because we are out of class scope.
    Dog myDog(Dog::chihuahua,"Dean",5);

    std::cout<<"myDog breed = "<<myDog.getBreed()<<"\n";
    std::cout<<"myDog name = "<<myDog.getName()<<"\n";
    std::cout<<"myDog age = "<<myDog.getAge()<<"\n";

    return 0;
}