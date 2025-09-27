#include <iostream>

class Singleton{
    public:
        static Singleton& createSingletonInstance(){
            static Singleton singletonInstance;
            return singletonInstance;
        }

        // Delete copy/move constructors and copy/move assignment operators to prevent copying.
        Singleton(const Singleton&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        Singleton& operator=(Singleton&&) = delete;

    private:
        Singleton(){
            std::cout << "Note this message only prints
            once because local static variables(singletonInstance) are only instantiated once.\n";
        };
};

int main(){
    constexpr Singleton& singleton {Singleton::createSingletonInstance()};
    
    Singleton& singleton2 {Singleton::createSingletonInstance()};
}