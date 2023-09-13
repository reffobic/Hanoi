//
//  main.cpp
//  Hanoi
//
//  Created by Mohamed El-Refai on 08/09/2023.
//

#include <iostream>
#include "Stackt.h"

using namespace std;

int moves = 0; // Variable to keep track of the number of moves

// Recursive function to solve the Tower of Hanoi problem
void Towers (int N, Stackt& A , Stackt& B , Stackt& C, int & moves, char SourceTag, char TargetTag, char AuxTag) {
    
    if (N == 1) { // If there's only one disk, move it directly from source to target

        int disk = A.pop(); // Pop a disk from the source stack
        C.display(disk, SourceTag, TargetTag); // Display the move
        C.Push(disk); // Push the disk to the target stack
        moves++; // Increment the move counter

    }
    else{ // If there are more than one disk, use recursion

        Towers(N - 1, A, B, C, moves, SourceTag, AuxTag, TargetTag); // Move N-1 disks from source to auxiliary via target

        int disk = A.pop(); // Move the remaining disk from source to target
        C.display(disk, SourceTag, TargetTag); // Display the move
        C.Push(disk); // Push the disk to the target stack
        moves++; // Increment the move counter

        Towers(N - 1, B, C, A, moves, AuxTag, TargetTag, SourceTag); // Move N-1 disks from auxiliary to target via source
    }
}

int main(){
    int num;
    
    cout << "------------------ Tower of Hanoi ------------------"<< endl;
    cout << "There are 3 towers, lets move the number of disks you want to tower C" <<endl;
    cout << "Please enter the number of disks: ";
    cin >> num;

    char sourceTag = 'A', auxiliaryTag = 'B', targetTag = 'C';
    
    Stackt Source(num); // Create a stack for the source tower
    Stackt Aux(num); // Create a stack for the auxiliary tower
    Stackt Target(num); // Create a stack for the target tower
    
    for (int i = 1; i<=num; i++){
        Source.Push(i);  //to insert the number of disks in the source tower
    } // Initialize the source tower with disks numbered from 1 to num

    cout << endl; // Call the Towers function to solve the Tower of Hanoi problem
    Towers(num, Source, Aux, Target, moves, sourceTag, targetTag, auxiliaryTag);
    cout << endl;

    cout << "Total moves: " << moves << endl; // Display the total number of moves
    return 0;
}
