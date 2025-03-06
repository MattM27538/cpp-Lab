/*  Functions have external linkage by default, and can be seen by other files.
    This function is called from "extern1.cpp". Compile them together to test
    for external linkage. */
int add(int myInt, int myInt2){
    return myInt+myInt2;
}

/*  const global variables can be defined as extern, making them external. Non-const 
    global variables are extern by default.
*/
extern const int g_myInt={2};

/*  constexpr can be used in conjunction with the extern keyword though it is useless as
    you could not forward declare the constexpr in any other translational unit because
    the value would need to be know in that unit at compile time. However, if that value 
    is defined in some other file, the compiler has no visibility on what value was 
    defined in that other file.*/

// extern constexpr int g_myInt2={3};

