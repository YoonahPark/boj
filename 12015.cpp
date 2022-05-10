// 가장 긴 증가하는 부분 수열 2 https://www.acmicpc.net/problem/12015

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long N, n, K;
vector<long> A, res;

bool isBiggerThanK(int mid){
    return res[mid]>=K;
}

int bs(int begin, int end){
    if(begin==end) return begin;
    int mid = (begin+end)/2;
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
    for(int i=0; i<N; i++){
        cin>>n;
        A.push_back(n);
    }

    res.push_back(A[0]);
    for(int i=1; i<N; i++){
        K = A[i];
        if(K>res[res.size()-1]) res.push_back(K);
        else res[bs(0, res.size()-1)] = K;
    }

    cout<<res.size();

}