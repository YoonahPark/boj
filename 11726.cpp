// 2×n 타일링 https://www.acmicpc.net/problem/11726

#include <iostream>
#include <vector>
using namespace std;

vector<long> v(1001);

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;

    v[1]=1;
    v[2]=2;

    for(int i=3; i<n+1; i++){
        v[i]=(v[i-1]+v[i-2])%10007;
    }

    cout<<v[n];
}