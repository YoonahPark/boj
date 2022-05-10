// 평범한 배낭 https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin>>N>>K;;
    vector<double> temp(2);
    vector<vector<double>> v;
    vector<vector<double>> dp(N+1, vector<double>(K+1, 0));

    v.push_back(temp);

    for(int i=0; i<N; i++){
        cin>>temp[0]>>temp[1];
        v.push_back(temp);
    }

    for(int i=0; i<N; i++){
        for(int w=0; w<=K; w++){
            dp[i+1][w] = max(dp[i+1][w], dp[i][w]);
            if(w+v[i+1][0]<=K){
                dp[i+1][w+v[i+1][0]] = max(dp[i+1][w+v[i+1][0]], dp[i][w]+v[i+1][1]);
            }
        }
    }

    cout<<dp[N][K];
}