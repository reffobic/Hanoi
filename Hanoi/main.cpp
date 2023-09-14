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
void Towers (int N, Stackt<int> & A , Stackt<int> & B , Stackt<int> & C, int & moves, char SourceTag, char TargetTag, char AuxTag) {
    
    if (N == 1) { // If there's only one disk, move it directly from source to target

        cout << "---------------" << endl;
        int disk = A.pop(); // Pop a disk from the source stack
        C.Push(disk); // Push the disk to the target stack
        C.displayMove(disk, SourceTag, TargetTag); // Display the move

        A.displayStack(A.getName());
        B.displayStack(B.getName());
        C.displayStack(C.getName());

        moves++; // Increment the move counter

    }
    else{ // If there are more than one disk, use recursion

        Towers(N-1, A, C, B, moves, SourceTag, AuxTag, TargetTag); // Move N-1 disks from source to auxiliary via target

        cout << "---------------" << endl;
        int disk = A.pop(); // Move the remaining disk from source to target
        C.Push(disk); // Push the disk to the target stack
        C.displayMove(disk, SourceTag, TargetTag); // Display the move

        A.displayStack(A.getName());
        B.displayStack(B.getName());
        C.displayStack(C.getName());

        moves++; // Increment the move counter

        Towers(N-1, B, A, C, moves, AuxTag, TargetTag, SourceTag); // Move N-1 disks from auxiliary to target via source
    }
}

int main(){
    int num;
    
    cout << "------------------ Tower of Hanoi ------------------"<< endl;
    cout << "There are 3 towers, lets move the number of disks you want to tower C" <<endl;
    cout << "Please enter the number of disks: ";
    cin >> num;

    char sourceTag = 'A', auxiliaryTag = 'B', targetTag = 'C';
    
    Stackt <int> Source(num, 'A'); // Create a stack for the source tower
    Stackt <int> Aux(num, 'B'); // Create a stack for the auxiliary tower
    Stackt <int> Target(num, 'C'); // Create a stack for the target tower
    
    for (int i = num; i>=1; i--){
        Source.Push(i);  //to insert the number of disks in the source tower
    } // Initialize the source tower with disks numbered from 1 to num

    cout << "---------------" << endl;
    Source.displayStack(sourceTag);
    Aux.displayStack(auxiliaryTag);
    Target.displayStack(targetTag);

    // Call the Towers function to solve the Tower of Hanoi problem
    Towers(num, Source, Aux, Target, moves, sourceTag, targetTag, auxiliaryTag);
    cout << endl;

    cout << "Total moves: " << moves << endl; // Display the total number of moves
    return 0;
}
