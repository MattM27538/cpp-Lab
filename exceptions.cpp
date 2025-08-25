#include <iostream>
#include <cmath>

/*What catch blocks typically do
  1. Catch blocks may print an error (either to the console, or a log file) and then allow the
     function to proceed.
  2. Catch blocks may return a value or error code back to the caller.
  3. A catch block may throw another exception. Because the catch block is outside of the 
     try block, the newly thrown exception in this case is not handled by the preceding try 
     block -- it’s handled by the next enclosing try block.
  4. A catch block in main() may be used to catch fatal errors and terminate the program in a 
     clean way.
*/

int main(){
    std::cout << "Enter a number and I will return the square root of it: ";
    double x{};
    
    std::cin >> x;

    /*We use the try keyword to define a block of statements (called a try block). The try block acts
      as an observer, looking for any exceptions that are thrown by any of the statements within the 
      try block.

      A try block must have at least one catch block immediately following it, but may have multiple 
      catch blocks listed in sequence.
    */
    try{
        if(x < 0.0){
            /*A throw statement is used to signal that an exception or error case has 
              occurred. To use a throw statement, simply use the throw keyword, 
              followed by a value of any data type you wish to use to signal that an
              error has occurred. Typically, this value will be an error code, a 
              description of the problem, or a custom exception class.
            */
            throw "Error: Can not take square root of negative number.";
        }

        std::cout << "The square root of " << x << " is " << std::sqrt(x) << "\n";
    }

    /*The catch keyword is used to define a block of code (called a catch block) that handles 
      exceptions for a single data type.Once an exception has been caught by the try block and
      routed to a matching catch block for handling, the exception is considered handled. 
      After the matching catch block executes, execution then resumes as normal, starting 
      with the first statement after the last catch block.
    */

    catch(const char* errorMessage){
        std::cerr << errorMessage << "\n";
    }

    /*Just like with functions, if the parameter is not going to be used in the catch block, 
      the variable name can be omitted. This can help prevent compiler warnings about unused 
      variables.
      NOTE: No type conversion is done for exceptions except casts from a derived class to one of
      its parent classes will be performed. 
    */

    catch (int){

    }
}