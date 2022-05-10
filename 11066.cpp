// 파일 합치기 https://www.acmicpc.net/problem/11066

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long T, K, file_size;
vector<int> arr, res;

void sol(){

    arr.clear();
    cin>>K;
    for(int i=0; i<K; i++){
        cin>>file_size;
        arr.push_back(file_size);
    }

    vector<vector<long long>> dp(K, vector<long long>(K, 0)), cost(K, vector<long long>(K, 0));

    for(int i=0; i<K; i++){
        cost[i][i] = arr[i];
    }

    for(int d=1; d<K; d++){
        for(int i=0; i<K-d; i++){

            cost[i][i+d] = cost[i][i]+cost[i+1][i+d];

            for(int x=0; x<d; x++){

                if(dp[i][i+d]==0){
                    dp[i][i+d] = cost[i][i+d] + dp[i][i+x] + dp[i+x+1][i+d];
                }
                else{
                    dp[i][i+d] = min(dp[i][i+d], cost[i][i+d] + dp[i][i+x] + dp[i+x+1][i+d]);
                }
            }
        }
    }

    res.push_back(dp[0][K-1]);

}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>T;
    for(int i=0; i<T; i++){
        sol();
    }

    for(int i=0; i<T; i++){
        cout<<res[i]<<"\n";
    }
}