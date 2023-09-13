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

void Towers (int N, Stackt& A , Stackt& B , Stackt& C, int & moves) {
    
    if (N == 1) {
        
        int disk = A.pop();
        C.Push(disk);
        moves++;
        
        cout << endl;
        A.display("Source");
        B.display("Aux");
        C.display("Target");
        cout << endl;
    }
    else{
        Towers(N-1, A, C, B, moves);
        
        int disk = A.pop();
        C.Push(disk);
        moves++;
        
        cout << endl;
        A.display("Source");
        B.display("Aux");
        C.display("Target");
        cout << endl;
        
        Towers(N-1, B, A, C, moves);
    }
}

int main(){
    int num;
    
    cout << "------------------ Tower of Hanoi ------------------"<< endl;
    cout << "There are 3 towers, lets move the number of disks you want to tower C" <<endl;
    cout << "Please enter the number of disks: ";
    cin >> num;
    
    Stackt Source(num);
    Stackt Aux(num);
    Stackt Target(num);
    
    for (int i = 1; i<=num; i++){
        Source.Push(i);  //to insert the number of disks in the source tower
    }
    
    cout << endl;
    Source.display("Source");
    Aux.display("Aux");
    Target.display("Target");
    cout << endl;
    
    Towers(num, Source, Aux, Target, moves);
    cout << "Total moves: " << moves << endl << endl;
    return 0;
}
