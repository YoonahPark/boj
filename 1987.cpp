// 알파벳 https://www.acmicpc.net/problem/1987

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, res, cnt;
string s;
vector<string> board;
vector<char> route;

bool exists(char ch){
    for(int x=0; x<route.size(); x++){
            if(route[x]==ch) return 1;
    }
    return 0;
}

void sol(int i, int j, int cnt){
    if(cnt>res) res = cnt;
    route.push_back(board[i][j]);

    if(i>0){
        if(!exists(board[i-1][j])) sol(i-1, j, cnt+1);
    }
    if(i<R-1){
        if(!exists(board[i+1][j])) sol(i+1, j, cnt+1);
    }
    if(j>0){
        if(!exists(board[i][j-1])) sol(i, j-1, cnt+1);
    }
    if(j<C-1){
        if(!exists(board[i][j+1])) sol(i, j+1, cnt+1);
    }

    route.pop_back();
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>R>>C;

    for(int i=0; i<R; i++){
        cin>>s;
        board.push_back(s);
    }

    sol(0, 0, 1);

    cout<<res;
}