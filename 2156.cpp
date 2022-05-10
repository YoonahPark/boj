// 포도주 시식 https://www.acmicpc.net/problem/2156

#include <iostream>
#include <vector>
using namespace std;

int findMax(int a, int b, int c){
    int res=a;
    if(b>res) res=b;
    if(c>res) res=c;
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int> amount(n);
    vector<vector<int>> dp(n, vector<int>(3));

    for(int i=0; i<n; i++){
        cin>>amount[i];
    }

    dp[0][0] = 0;
    dp[0][1] = amount[0];
    dp[0][2] = amount[0];

    for(int i=1; i<n; i++){
        dp[i][0] = findMax(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + amount[i];
        dp[i][2] = dp[i-1][1] + amount[i];
    }

    cout<<findMax(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
}