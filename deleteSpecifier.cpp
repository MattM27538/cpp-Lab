/*
*In cases where we have a function that we explicitly do not want to be callable, we 
*can define that function as deleted by using the =delete specifier. If the compiler 
*matches a function call to a deleted function, compilation will be halted with a compile error.
*/
int divideByTwo(char)=delete;

int divideByTwo(int base){
    return base/2;
}

int square(int base){
    return base*base;
}

// This function template will take precedence for arguments of other types
// Since this function template is deleted, calls to it will halt compilation.
template <typename T>
void square(T x)=delete;

int main(){
    constexpr auto base{5};
    square(base);

    // Calling this function would cause an error due to the function being deleted.
    // divideByTwo('a');
   
    // Calling this function would cause an error due to the function template being deleted.
    // square(true);

    return 0;
}