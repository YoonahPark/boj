// 이항 계수 2 https://www.acmicpc.net/problem/11051

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(1010, vector<int>(10001));

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;

    for(int i=1; i<N+1; i++){
        for(int j=0; j<K+1; j++){
            if(i==j) v[i][j]=1;
            else if(j==0) v[i][j]=1;
            else{
                v[i][j]=(v[i-1][j-1]+v[i-1][j])%10007;
            }
        }
    }
    cout<<v[N][K];
}