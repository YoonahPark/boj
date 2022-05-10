// 소수 구하기 https://www.acmicpc.net/problem/1929

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool prime_checker(int n){
    if(n==1) return 0;
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    int T, n;
    cin>>T;
    vector<int> v1(T), v2(T);

    for(int i=0; i<T; i++){
        cin>>n;
        for(int j=n/2; j>1; j--){
            if(prime_checker(j) && prime_checker(n-j)){
                v1[i]=j;
                v2[i]=n-j;
                break;
            }
        }
    }
    for(int i=0; i<T; i++){
        cout<<v1[i]<<" "<<v2[i]<<"\n";
    }
}