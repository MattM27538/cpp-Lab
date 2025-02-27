#include <iostream>
#include <bitset>

int main(){
    std::bitset<5> myBitSet{10};
    
    std::cout<<"myBitSet ="<<myBitSet<<"\n";

    //Left shift bitwise operator shifts bits over two spaces. This does not affect original bitset.
    //Note that if you’re using operator<< for both output and left shift, parenthesization is required to use for left-shifting:
    std::cout<<"myBitSet shifted left twice ="<<(myBitSet<<2)<<"\n";

    // The original bitset is not modified.
    std::cout<<"myBitSet ="<<myBitSet<<"\n";

    //Right shift bitwise operator shifts bits over two spaces. This does not affect original bitset.
    std::cout<<"myBitSet shifted right twice ="<<(myBitSet>>2)<<"\n";

    //NOTE: Bit-shifting in C++ is endian-agnostic. Left-shift is always towards the most significant bit, and right-shift towards the least significant bit.

    //Bitwise NOT operator
    std::bitset<5> myBitSetNotted{~myBitSet};

    std::cout<<"myBitSetNotted = "<<myBitSetNotted<<"\n";

    //Bitwise OR operator
    std::cout<<"bitwise OR example = "<<(std::bitset<4>{ 0b0111 }|std::bitset<4>{ 0b0011 }|std::bitset<4>{ 0b0001 })<<'\n';

    //Bitwise AND operator
    std::cout<<"bitwise AND example = "<<(std::bitset<4>{ 0b0111 }&std::bitset<4>{ 0b0011 }&std::bitset<4>{ 0b0001 })<<'\n';

    //Bitwise XOR operator
    std::cout<<"bitwise XOR example = "<<(std::bitset<4>{ 0b0111 }^std::bitset<4>{ 0b0011 }^std::bitset<4>{ 0b0001 })<<'\n';


    //Bitwise assignment operator
    std::bitset<5> myBitSetAssignmentTest={myBitSet>>1};

    std::cout<<"myBitSetAssignmentTest = "<<myBitSetAssignmentTest<<"\n";

    return 0;
}