// 스티커 https://www.acmicpc.net/problem/9465

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(1010, vector<int>(1010));

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=1; i<N+10; i++){
        for(int j=0; j<10; j++){
            if(i==j) v[i][j]=1;
            else if(j==0) v[i][j]=1;
            else{
                v[i][j]=(v[i-1][j-1]+v[i-1][j])%10007;
            }
        }
    }
    cout<<v[N+9][9];
}