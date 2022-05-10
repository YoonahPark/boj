// 팰린드롬? https://www.acmicpc.net/problem/10942

#include <iostream>
#include <vector>
using namespace std;

long N, n, M, S, E;
vector<long> arr;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>n;
        arr.push_back(n);
    }

    vector<vector<long>> dp(N, vector<long>(N, 0));

    int s, e;

    for(int i=0; i<N; i++){
        dp[i][i] = 1;
    }

    for(int i=0; i<N-1; i++){
        if(arr[i]==arr[i+1]) dp[i][i+1] = 1;
    }

    for(int i=2; i<N; i++){
        for(int j=0; j<N-i; j++){
            s = j;
            e = i+j;
            if(dp[s+1][e-1]==1 && arr[s]==arr[e]) dp[s][e]=1;
        }
    }

    cin>>M;
    for(int i=0; i<M; i++){
        cin>>S>>E;
        --S;
        --E;
        cout<<dp[S][E]<<"\n";
    }
}