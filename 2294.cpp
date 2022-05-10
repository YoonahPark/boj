// 동전 2 https://www.acmicpc.net/problem/2294

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n, k, val, res;
    cin>>n>>k;
    vector<int> coins(n), cnt(k+1, -1);

    for(int i=0; i<n; i++){
        cin>>val;
        coins[i]=val;
        cnt[val]=1;
    }

    for(int j=1; j<k+1; j++){
        if(cnt[j]==-1) continue;
        for(int i=0; i<n; i++){
            if(j+coins[i]>=k+1) continue;
            if(cnt[j+coins[i]]<0){
                cnt[j+coins[i]] = cnt[j]+1;
            }
            else if(cnt[j+coins[i]] > cnt[j]+1){
                cnt[j+coins[i]] = cnt[j]+1;
            }
        }
    }
    cout<<cnt[k];
}