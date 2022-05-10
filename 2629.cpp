// 양팔저울 https://www.acmicpc.net/problem/2629

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, m, N, n, sum;
vector<int> arr;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>M;

    for(int i=0; i<M; i++){
        cin>>m;
        arr.push_back(m);
        sum += m;
    }

    sort(arr.begin(), arr.end());

    vector<int> dp(2*sum+1);
    dp[sum]=1;

    for(int i=M-1; i>=0; i--){
        m = arr[i];
        for(int j=0; j<dp.size(); j++){
            if(dp[j]==1){
                if(j-m>=0){
                    if(dp[j-m]!=1) dp[j-m]=-1;
                }
                if(j+m<=2*sum){
                    if(dp[j+m]!=1) dp[j+m]=-1;
                }
            }
        }
        for(int j=0; j<dp.size(); j++){
            if(dp[j]==-1) dp[j]=1;
        }

    }

    cin>>N;
    for(int i=0; i<N; i++){
        cin>>n;
        if(n>sum) cout<<"N ";
        else{
            if(dp[n+sum]) cout<<"Y ";
            else cout<<"N ";
        }
    }
}