// 이친수 https://www.acmicpc.net/problem/2193

#include <iostream>
#include <vector>
using namespace std;

int N;
vector<long> v(91, 1);

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=2; i<N-1; i++){
        for(int d=i+2; d<N+1; d++){
            v[d]+=v[i];
        }
    }

    if(N<3) cout<<1;
    else cout<<v[N]+v[N-1];
}