//
//  Stackt.h
//  Hanoi
//
//  Created by Mohamed El-Refai on 08/09/2023.
//

#ifndef Stackt_h
#define Stackt_h

#include <iostream>
using namespace std;

class Stackt
{
private:
    int top, MaxSize; //index to the top of the tower
    int *theStack; //Stack
    
public:
    Stackt (int nelements){
        MaxSize = nelements;
        theStack = new int[MaxSize];
        top = -1;
    }; // Constructor
    
    ~Stackt(){
        delete[] theStack;
    }; // Destructor
    
    void Push (int); //pushes a value in the stack
    int pop (); //removes the top value of the stack
    int stackTop() const;
    void display(int disk, char source, char target); //function to display the steps
};

int Stackt :: stackTop() const
{
    int v;
    v = theStack[top];
    return v;
}

void Stackt :: Push(int num){
    theStack [++top] = num;
}


int Stackt :: pop(){
    int popped = theStack[top--];
//    top--;
    return popped;
}


void Stackt :: display(int disk, char source, char target){
    cout << "Moved disk " << disk << " from " << source << " to " << target << endl;
}

#endif /* Stackt_h */
