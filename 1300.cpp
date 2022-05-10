// K번째 수 https://www.acmicpc.net/problem/1300

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long N, k, res;

long long isBiggerThanK(long long mid){
    long long cnt=0, temp;
    for(int i=1; i<=N; i++){
        temp = ceil((double)mid/(double)i)-1;
        
        if(temp<N) cnt+=temp;
        else cnt+=N;

        if(cnt>k-1) return 1;
    }

    return cnt>k-1;
}

long long sol(long long begin, long long end){
    if(begin==end) return begin;

    long long mid = ceil((double)(begin+end)/2);
    
    if(isBiggerThanK(mid)){
        return sol(begin, mid-1);
    }
    else{ 
        return sol(mid, end);
    }
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>k;

    if(N<=sqrt(1000000000)){
        cout<<sol(1, N*N);
    }
    else{
        cout<<sol(1, 1000000000);
    }
}