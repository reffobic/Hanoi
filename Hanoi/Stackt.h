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
    int top, MaxSize; // Index to the top of the tower and maximum size of the stack
    int *theStack; // Pointer to the dynamic array representing the stack
    
public:
    Stackt (int nelements){
        MaxSize = nelements; // Set the maximum size of the stack
        theStack = new int[MaxSize]; // Dynamically allocate memory for the stack
        top = -1; // Initialize top to -1 (empty stack)
    }; // Constructor
    
    ~Stackt(){
        delete[] theStack; // Destructor to free allocated memory when the object is destroyed
    }; // Destructor
    
    void Push (int); //pushes a value in the stack
    int pop (); //removes the top value of the stack
    void display(int disk, char source, char target); //function to display the steps
};

void Stackt :: Push(int num){
    top++; // Increment top to prepare for the push
    theStack [top] = num; // Assign the value to the top of the stack
}

int Stackt :: pop(){
    int popped = theStack[top]; // Get the value at the top of the stack
    top--; // Decrement top to remove the top element
    return popped; // Return the value that was popped
}

void Stackt :: display(int disk, char source, char target){
    cout << "Moved disk " << disk << " from " << source << " to " << target << endl; // Display the movement of a disk from source to target
}

#endif /* Stackt_h */
