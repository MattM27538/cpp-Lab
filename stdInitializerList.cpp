#include <initializer_list>
#include <algorithm>
#include <iostream>

class customIntArray{
    public:
    customIntArray()=default;

    //Constructor that allows customIntArray to be constructed with 
    //with an initializer list.
    customIntArray(std::initializer_list<int> initializerList)
        : m_arrayLength{initializerList.size()},
          m_intArray{new int[m_arrayLength] {}}
        {
            std::copy(initializerList.begin(), initializerList.end(), m_intArray);
        }

    ~customIntArray(){
        delete []m_intArray;
    }
    
    std::size_t getArrayLength() const{
        return m_arrayLength;
    }
    private:
        std::size_t m_arrayLength{};
        int* m_intArray{};
};

int main(){
    customIntArray myCustomIntArray{0,1,2};

    std::cout << "Size of myCustomIntArray = " << myCustomIntArray.getArrayLength() << "\n";

    return 0;
}