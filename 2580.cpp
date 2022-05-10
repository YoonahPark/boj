// 스도쿠 https://www.acmicpc.net/problem/2580

#include <iostream>
#include <vector>
using namespace std;

int success;
vector<vector<int>> sudoku(9, vector<int>(9, 0)), zeroCells;

void bt(long long n){
    int I = zeroCells[n][0], J = zeroCells[n][1];

    vector<int> filled(10, 0);

    for(int x=0; x<9; x++){
        filled[sudoku[x][J]] = 1;
        filled[sudoku[I][x]] = 1;
    }

    for(int i=(I/3)*3; i<(I/3)*3+3; i++){
        for(int j=(J/3)*3; j<(J/3)*3+3; j++){
            filled[sudoku[i][j]] = 1;
        }
    }

    for(int x=1; x<10; x++){
        if(filled[x]==0){
            if(n==zeroCells.size()-1){
                sudoku[I][J] = x;
                success = 1;

                for(int i=0; i<9; i++){
                    for(int j=0; j<9; j++){
                        cout<<sudoku[i][j]<<" ";
                    }
                    cout<<"\n";
                }
                break;
            }
            else{
                sudoku[I][J] = x;
                bt(n+1);
                sudoku[I][J] = 0;
            }
        }
        if(success==1) break;
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0) zeroCells.push_back({i, j});
        }
    }
    
    bt(0);
}