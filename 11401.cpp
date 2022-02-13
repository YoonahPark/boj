// 이항 계수 3 https://www.acmicpc.net/problem/11401

#include <iostream>
#include <vector>
using namespace std;

long long multiply(long long a, long b, long c){
    if(b==0) return a%c;

    long long res = 1;
    long long n = a%c;
    vector<long long> v;

    while(b>0){
        v.push_back(b%2);
        b /= 2;
    }

    for(int i=0; i<v.size(); i++){
        if(v[i]){
            res = (res*n)%c;
        }
        n = (n*n)%c;
    }
    return res;
}

long long factorial(long long num){
    long long res=1;
    for(int i=1; i<num+1; i++){
        res = (res*i)%1000000007;
    }
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long N, R, res, temp;
    cin>>N>>R;

    res = factorial(N);
    //cout<<res<<" ";
    temp = (factorial(R)*factorial(N-R))%1000000007;
    //cout<<temp<<" ";
    res = (res*multiply(temp, 1000000005, 1000000007))%1000000007;
    //cout<<multiply(2, 6, 6)<<" ";
    cout<<res;
}