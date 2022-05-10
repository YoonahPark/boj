// 가장 긴 증가하는 부분 수열 3 https://www.acmicpc.net/problem/12738

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long N, n, K, bsIndex, length;
vector<long long> A, res, ind, ans;

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

    ind.push_back(0);
    res.push_back(A[0]);
    
    for(long long i=1; i<N; i++){
        K = A[i];
        if(K>res[res.size()-1]){
            ind.push_back(res.size());
            res.push_back(K);
        }
        else{
            bsIndex = bs(0, res.size()-1);
            ind.push_back(bsIndex);
            res[bsIndex] = K;
        }
    }


    cout<<res.size()<<"\n";
    length = res.size()-1;
    
    for(long long i=ind.size()-1; i>=0; i--){
        if(ind[i]==length){
            ans.push_back(A[i]);
            --length;
        }
    }

    for(long long i=ans.size()-1; i>=0; i--){
        cout<<ans[i]<<" ";
    }
}