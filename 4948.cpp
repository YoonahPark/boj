// 베르트랑 공준 https://www.acmicpc.net/problem/4948

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int count_prime(int M, int N){
    int n, cnt=0;
    vector<int> v(N-M+1);
    
    for(int i=0; i<N-M+1; i++){
        v[i]=i+M;
    }

    for(int i=2; i<=N/2; i++){
        n=i*2;
        while(n<=N){
            if(n>=M){
                v[n-M]=0;
            }
            n+=i;
        }
    }
    if(M==1) v[0]=0;

    for(int i=0; i<N-M+1; i++){
        if(v[i]!=0){
            cnt++;
        }
    } 
    return cnt;
}

int main(){
    int n;
    vector<int> v;

    cin>>n;
    while(n!=0){
        v.push_back(count_prime(n+1, 2*n));
        cin>>n;
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<"\n";
    }
}