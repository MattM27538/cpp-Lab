#include <iostream>

class BaseExceptionClass{
    public:
        BaseExceptionClass()=default;

        virtual void printErrorMessage() const{
            std::cout << errMessage;
        }

        private:
            const char* errMessage{"Called BaseExceptionClass error message.\n"};
    };
    
class DerivedExceptionClass : public BaseExceptionClass{
    public:
        DerivedExceptionClass()=default;

        void printErrorMessage() const override{
            std::cout << errMessage;
        }

    private:
        const char* errMessage{"Called DerivedExceptionClass error message.\n"};
};

int divide(int numerator, int denominator){
    if(denominator == 0){
        throw DerivedExceptionClass{};
    }

    return numerator/denominator;
}

int main(){
    try{
        try{
            divide(5, 0);
        }
        catch(BaseExceptionClass& exception){
            exception.printErrorMessage();
            /*Rule: When rethrowing the same exception, use the throw keyword by itself otherwise
              you will make an exception object which is a copy of the original which can lead to slicing.
              e.g. throw exception; This would cause slicing as only the base would be copied. Then
              the second catch would print the BaseExceptionClass version of print().
            */
            throw;
        }
    }
    catch(BaseExceptionClass& exception){
        exception.printErrorMessage();
    }

    return 0;
}