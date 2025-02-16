#include <iostream>
#include <bitset>

int main(){
    int x={36};

    // Initialize bitset of size 8 bits and value 36.
    std::bitset<8> foo (x);
    
    std::cout << x << " in binary is " << foo << std::endl;
    
    // Count method returns number of 1's in the set
    std::cout << "bitcount is " << foo.count() << std::endl;
    
    //Reset bitset
    foo.reset();
    
    std::cout << "THe bitset is now " << foo << std::endl;
    
    return 0;
}