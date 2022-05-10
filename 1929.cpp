// 소수 구하기 https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int M, N, n;
    cin>>M>>N;
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
            cout<<v[i]<<"\n";
        }
    } 
}