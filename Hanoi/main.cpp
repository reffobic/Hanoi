//
//  main.cpp
//  Hanoi
//
//  Created by Mohamed El-Refai on 08/09/2023.
//

#include <iostream>
#include "Stackt.h"

using namespace std;

int moves = 0;


void Towers (int N, Stackt& A , Stackt& B , Stackt& C, int & moves, char SourceTag, char TargetTag, char AuxTag) {
    
    if (N == 1) {

        int disk = A.stackTop();

        C.Push(A.pop());
        moves++;
        C.display(disk, SourceTag, TargetTag);

    }
    else{

        Towers(N - 1, A, B, C, moves, SourceTag, AuxTag, TargetTag);

        int disk = A.stackTop();

        C.Push(A.pop());
        moves++;
        C.display(disk, SourceTag, TargetTag);


        Towers(N - 1, B, C, A, moves, AuxTag, TargetTag, SourceTag);
    }
}

int main(){
    int num;
    
    cout << "------------------ Tower of Hanoi ------------------"<< endl;
    cout << "There are 3 towers, lets move the number of disks you want to tower C" <<endl;
    cout << "Please enter the number of disks: ";
    cin >> num;

    char sourceTag = 'A', auxiliaryTag = 'B', targetTag = 'C';
    
    Stackt Source(num);
    Stackt Aux(num);
    Stackt Target(num);
    
    for (int i = 1; i<=num; i++){
        Source.Push(i);  //to insert the number of disks in the source tower
    }

    cout << endl;
    Towers(num, Source, Aux, Target, moves, sourceTag, targetTag, auxiliaryTag);
    cout << endl;

    cout << "Total moves: " << moves << endl;
    return 0;
}
