// 쉬운 계단 수 https://www.acmicpc.net/problem/10844

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long N;
    cin>>N;

    vector<vector<long long>> v(N+1, vector<long long>(10));

    for(int j=1; j<10; j++){
        v[1][j] = 1;   
    }

    for(long long i=2; i<N+1; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                v[i][0] = v[i-1][1]%1000000000;
            }
            else if(j==9){
                v[i][9] = v[i-1][8]%1000000000;
            }
            else{
                v[i][j] = (v[i-1][j-1]+v[i-1][j+1])%1000000000;
            }
        }
    }

    long long res=0;
    for(int j=0; j<10; j++){
        res += v[N][j];
    }
    cout<<res%1000000000;
}