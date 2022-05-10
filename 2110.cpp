// 공유기 설치 https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, x, d, C;
vector<int> v, D;
long long M;

bool isValid(long long mid){
    long long sum = 0, cnt=0;

    for(long long i=0; i<N-1; i++){
        if(sum>=mid){
            ++cnt;
            if(cnt>=C-1) break;
            sum = D[i];
        }
        else{
            sum += D[i];
        }
    }

    if(sum>=mid) ++cnt;

    if(cnt>=C-1) return 1;
    else return 0;
}

int sol(long long begin, long long end){
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
    long long maxX=0;

    cin>>N>>C;
    for(int i=0; i<N; i++){
        cin>>x;
        v.push_back(x);
        if(x>maxX) maxX = x;
    }

    sort(v.begin(), v.end());

    for(int i=1; i<N; i++){
        D.push_back(v[i]-v[i-1]);
    }

    cout<<sol(1, maxX);
}