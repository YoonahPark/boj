// 예산 https://www.acmicpc.net/problem/2512

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, res;
vector<int> requests;
long long M;

bool isBiggerThanM(int limit){
    long long res=0;
    for(int i=0; i<requests.size(); i++){
        if(requests[i]>limit){
            res += limit;
        }
        else{
            res += requests[i];
        }

        if(res>M){
            return 1;
        }
    }
    return 0;
}

int sol(int begin, int end){
    if(begin==end) return begin;
    int mid = ceil((double)(begin+end)/2);
    if(isBiggerThanM(mid)){
        return sol(begin, mid-1);
    }
    else{
        return sol(mid, end);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    int maxNum=0;

    cin>>N;
    for(int i=0;i<N; i++){
        cin>>n;
        requests.push_back(n);
        if(n>maxNum) maxNum=n;
    }
    cin>>M;

    cout<<sol(0, maxNum);
}