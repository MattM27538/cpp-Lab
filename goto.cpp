#include <iostream>

/*Goto statements have function scope which means the label is visible 
  throughout the function even before its point of declaration. */

void myFunc(){
    goto skipPoint;
    std::cout<<"If this printed, goto did not work.\n";

skipPoint: //Note: statement labels must be associated with a statement (line 10 ";").
    std::cout<<"Reached skip point\n";
    goto nextPoint;

nextPoint:
    ; //Note you can make an empty statement.
}

void jumpBackExample(){
    int myInt={1};
jumpBackPoint: 
    std::cout<<"Just passed jumpBackPoint. This output should appear twice.\n";

    if(myInt==1){
        ++myInt;
        goto jumpBackPoint;
    }

    //Note: You can’t jump forward over the initialization of any variable that is still in scope at the location being jumped to.
}

void goodUseCase(){
    //Goto statements are generally avoided, though a good exception might be to jump out of a nested for block.
    for(int i=0;i<3;++i){
        for(int j=4;j<6;++j){
            std::cout<<"i = "<<i<<"\n";
            if(i==1){
                goto outOfNestedLoop;
            }
        }
    }
outOfNestedLoop:
    std::cout<<"Exited nested for loop\n";
}

int main(){
    myFunc();

    jumpBackExample();

    goodUseCase();

    return 0;
}