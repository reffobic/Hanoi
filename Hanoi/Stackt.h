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
    void display(string); //function to display the steps
};

void Stackt :: Push(int num){
        top ++;
        theStack [top] = num;
}

int Stackt :: pop(){
    int popped = theStack[top];
    top--;
    return popped;
}

void Stackt :: display(string name){
    cout << name << " --> ";
    for (int i = 0; i<=top; i++){
        cout << theStack[i] << "  ";
    }
    cout << endl;
}

#endif /* Stackt_h */
