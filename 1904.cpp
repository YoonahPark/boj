// 01타일 https://www.acmicpc.net/problem/1904

#include <iostream>
#include <vector>
using namespace std;

vector<long> v(1000001);

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    v[1]=1;
    v[2]=2;

    for(int i=3; i<n+1; i++){
        v[i]=(v[i-1]+v[i-2])%15746;
    }

    cout<<v[n];
}