// 이친수 https://www.acmicpc.net/problem/2193

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<vector<long long>> v(n, vector<long long>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            cin>>v[i][j];
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(j==0){
                v[i][j] += v[i-1][j];
            }
            else if(j==i){
                v[i][j] += v[i-1][j-1];
            }
            else{
                v[i][j] += max(v[i-1][j-1], v[i-1][j]);
            }
        }
    }

    long long max=0;
    for(int i=0; i<n; i++){
        if(v[n-1][i]>max) max=v[n-1][i];
    }

    cout<<max;
}