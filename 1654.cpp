// 랜선 자르기 https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long K, N;
vector<long long> lines;

bool isBiggerThanN(long long maxLength){

    long long res=0;

    for(int i=0; i<lines.size(); i++){
        res += lines[i]/maxLength;

        if(res>=N){
            return 1;
        }
    }
    return 0;
}

long long sol(long long begin, long long end){
    if(begin==end) return begin;
    long long mid = ceil((double)(begin+end)/2);
    if(isBiggerThanN(mid)){
        return sol(mid, end);
    }
    else{
        return sol(begin, mid-1);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    long long n;
    long long maxNum=0;

    cin>>K>>N;
    for(int i=0 ; i<K ; i++){
        cin>>n;
        lines.push_back(n);
        if(n>maxNum) maxNum=n;
    }

    cout<<sol(1, maxNum);
}