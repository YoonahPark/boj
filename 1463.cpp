// 1로 만들기 https://www.acmicpc.net/problem/1463

#include <iostream>
#include <vector>
using namespace std;

int make_1(int n){
    int a, res;
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 1;
    res = min(make_1(n/3) + n%3 + 1, make_1(n/2) + n%2 + 1);
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    
    cout<<make_1(N);
}