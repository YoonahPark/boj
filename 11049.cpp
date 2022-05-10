// 행렬 곱셈 순서 https://www.acmicpc.net/problem/11049

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long N, r, c;
vector<int> arr_size(2);
vector<vector<int>> sizes;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr_size[0]>>arr_size[1];
        sizes.push_back(arr_size);
    }

    vector<vector<long long>> dp(N, vector<long long>(N, pow(2, 31)-1));

    for(int i=0; i<N; i++){
        dp[i][i] = 0;
    }

    for(int i=0; i<N-1; i++){
        dp[i][i+1] = sizes[i][0]*sizes[i][1]*sizes[i+1][1];
    }

    for(int d=2; d<N; d++){
        for(int i=0; i<N-d; i++){
            for(int x=0; x<d; x++){
                dp[i][i+d] = min(dp[i][i+d], dp[i][i+x] + dp[i+x+1][i+d] + sizes[i][0]*sizes[i+x][1]*sizes[i+d][1]);
            }
        }
    }

    cout<<dp[0][N-1];

}