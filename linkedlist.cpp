#include <iostream>

class Node{
    public:
    //Constructors
    Node():val{0} {}
    Node(int val):val{val} {}
    Node(int val, Node *next):val{val}, next(next) {}

    //Destructor
    ~Node();
    
    //Public member Functions
    int getVal();
    
    //Public member variables
    Node *next=nullptr;
    
    private:
    //Private member variables
    int val;
};

//Destructor
Node::~Node(){
    std::cout << "Destructor called\n";
}

// Returns value of val member variable.
int Node::getVal(){
    return val;
}

int main(){
    //Use default Node constructor.
    Node node1=Node();

    //Use first overloaded constructor.
    Node node2=Node{6};
    
    //Use second overloaded constructor.
    Node *node5=new Node{2};
    Node *node4=new Node({3},node5);
    Node *node3Head=new Node({7},node4);

    //Output node values.
    std::cout << "The value of Node3 is " << node3Head->getVal() << "\n";
    std::cout << "The value of Node4 is " << node4->getVal() << "\n";
    std::cout << "The value of Node7 is " << node5->getVal() << "\n";

    std::cout << "Now traverse and print the linked list values:.\n";

    Node *currentNode=node3Head;
    while(currentNode!=nullptr){
        std::cout << currentNode->getVal() << "\n";
        currentNode=currentNode->next;
    }

    //Node 3head, 4, and 5 would deallocate on their own after main goes out of scope but better practice to delete instead.
    delete node3Head;
    delete node4;
    delete node5;

    return 0;
}