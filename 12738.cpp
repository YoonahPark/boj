// 가장 긴 증가하는 부분 수열 3 https://www.acmicpc.net/problem/12738

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long N, n, K;
vector<long long> A, res;

bool isBiggerThanK(long long mid){
    return res[mid]>=K;
}

int bs(long long begin, long long end){
    if(begin==end) return begin;
    long long mid = (begin+end)/2;
    if(isBiggerThanK(mid)){
        return bs(begin, mid);
    }
    else{
        return bs(mid+1, end);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N;
    for(long long i=0; i<N; i++){
        cin>>n;
        A.push_back(n);
    }

    res.push_back(A[0]);
    for(long long i=1; i<N; i++){
        K = A[i];
        if(K>res[res.size()-1]) res.push_back(K);
        else res[bs(0, res.size()-1)] = K;
    }

    cout<<res.size();

}