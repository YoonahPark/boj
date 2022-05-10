// LCS https://www.acmicpc.net/problem/1699

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int i, j, same, res;
string s1, s2;

int main(){

    cin>>s1>>s2;
    vector<vector<int>> dp(s1.size(), vector<int>(s2.size(), 0));
    
    same = 0;
    for(; j<s2.size(); j++){
        if(s1[0]==s2[j]) same = 1;
        dp[0][j] = same;
    }

    same = 0;
    for(; i<s1.size(); i++){
        if(s1[i]==s2[0]) same = 1;
        dp[i][0] = same;
    }

    for(i=1; i<s1.size(); i++){
        for(j=1; j<s2.size(); j++){
            dp[i][j] = dp[i-1][j-1];
            if(s1[i]==s2[j]) dp[i][j] += 1;

            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            dp[i][j] = max(dp[i][j], dp[i][j-1]);
        }
    }

    cout<<dp[s1.size()-1][s2.size()-1];
}