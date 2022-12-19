#include <iostream>
#include "ex01-library.h"

using namespace std;

// Task 1(a).  Implement this function
Square **createChessboard(unsigned int n) {
    // Replace the following with your code
    Square **c = new Square*[n];
    for (unsigned int i = 0; i < n; i++) {
        c[i] = new Square[n];
        for (unsigned int j = 0; j < n; j++) {
            c[i][j] = {none, nobody};
        }
    }
    return c;
}

// Task 1(b).  Implement this function
void displayChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i<n; i++) {
        for (unsigned int j= 0; j<n; j++) {
            switch (c[i][j].piece)
            {
            case bishop:
                if (c[i][j].team == black){
                    cout << "B ";
                }
                else{
                    cout << "b ";
                }
                break;

            case rook:
                if (c[i][j].team == black){
                    cout << "R ";
                }
                else{
                    cout << "r ";
                }
                break;
            
            default:
                cout << "_ ";
                break;
            }
        }
        cout << endl;
    }
}

bool validMove(int piece, int r1, int c1, int r2, int c2){
    switch (piece)
    {
    case bishop:
        if((r1-c1)==(r2-c2)){
            return true;
        }
        else if((r1+c1)==(r2+c2)){
            return true;
        }
        else{
            return false;
        }
        break;
    
    case rook:
        if((r1==r2)||(c1==c2)){
            return true;
        }
        else{
            return false;
        }
        break;
    
    default:
        return false;
        break;
    }

}

// Task 1(c).  Implement this function
bool move(Square **c, unsigned int n,
          int r1, int c1, int r2, int c2) {
    // Replace the following with your code

    if(c[r1][c1].piece!=none){

        if(!(r1==r2 && c1==c2)){

            if(c[r1][c1].team!=c[r2][c2].team){

                if (validMove(c[r1][c1].piece, r1, c1, r2, c2)){
                    c[r2][c2].piece = c[r1][c1].piece;
                    c[r2][c2].team = c[r1][c1].team;
                    c[r1][c1].piece = none;
                    c[r1][c1].team = nobody;
                    return true;
                }
            }

        }
    }
    return false;
}

// Task 1(d).  Implement this function
bool threatened(Square **c, unsigned int n,
                int row, int col) {
    // Replace the following with your code

    for (unsigned int i = 0; i<n; i++) {
        for (unsigned int j= 0; j<n; j++) {
            if(c[i][j].piece!=none){
                if(c[i][j].team!=c[row][col].team){
                    if (validMove(c[i][j].piece, i, j, row, col)){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

// Do not modify
void deleteChessboard(Square **c, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        delete[] c[i];
    }
    delete[] c;
}
