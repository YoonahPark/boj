// 동전 1 https://www.acmicpc.net/problem/2293

#include <iostream>
#include <vector>
using namespace std;

int n, k, value;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n>>k;
    vector<int> values(n);
    vector<long long> res(k+1);

    for(int i=0; i<n; i++){
        cin>>values[i];
    }

    res[0]=1;

    for(int i=0; i<n; i++){
        value = values[i];
        for(int j=0; j+value<=k; j++){
            res[j+value] += res[j];
        }
    }

    cout<<res[k];


}