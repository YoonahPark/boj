// 제곱수의 합 https://www.acmicpc.net/problem/1699

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long> v(100001, -1);

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long N, n, new_num;
    cin>>N;
    n = sqrt(N);

    for(int i=1; i<n+1; i++){
        v[i*i]=1;
    }

    for(int i=2; i<N+1; i++){
        for(int j=1; j<i/2+1; j++){
            new_num = v[j]+v[i-j];
            if(v[i]==-1){
                v[i]=new_num;
            }
            else if(new_num<v[i]){
                v[i]=new_num;
            }
        }
    }
    cout<<v[N];
}