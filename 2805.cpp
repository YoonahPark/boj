#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N, M, length, maxLength=0;
vector<long long> lengths;

bool isValid(long long mid){
    long long lengthSum=0;
    for(int i=0; i<N; i++){
        if(lengths[i]>mid){
            lengthSum += lengths[i] - mid;
            if(lengthSum >= M){
                return 1;
            }
        }
    }
    return 0;
}

long long sol(long long begin, long long end){
    if(begin==end) return begin;
    long long mid = ceil((double)(begin+end)/2);
    if(isValid(mid)){
        return sol(mid, end);
    }
    else{
        return sol(begin, mid-1);
    }
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    
    for(int i=0; i<N; i++){
        cin>>length;
        if(length>maxLength) maxLength = length;
        lengths.push_back(length);
    }

    cout<<sol(0, maxLength);
}