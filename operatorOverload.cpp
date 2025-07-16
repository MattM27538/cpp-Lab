#include <iostream>
#include <string>

class Employee{
    public:
        Employee(std::string firstName, std::string middleName, std::string lastName):
        m_firstName{firstName}, 
        m_middleName{middleName}, 
        m_lastName{lastName}
        {}

        std::string_view getFirstName() const{
            return m_firstName;
        }

        std::string_view getMiddleName() const{
            return m_middleName;
        }

        std::string_view getLastName() const{
            return m_lastName;
        }

    private:
        std::string m_firstName{""};
        std::string m_middleName{""};
        std::string m_lastName{""};
};

//overloaded << operator for class Employee.
std::ostream& operator<<(std::ostream& outStream, Employee employee){
    outStream << employee.getFirstName() << " " << employee.getMiddleName() << " " << employee.getLastName() << " ";

    return outStream;
}

int main(){
    Employee myEmployee{"Mark", "M.", "Mendez"};

    std::cout << myEmployee << "\n";

    return 0;
}