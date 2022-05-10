// 피보나치 함수 https://www.acmicpc.net/problem/1003

#include <iostream>
#include <vector>
using namespace std;

int T;
vector<int> input, fibo(42);
int N;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int max=40;
    cin>>T;

    for(int i=0; i<T; i++){
        cin>>N;
        input.push_back(N);
        if(N>max) max=N;
    }

    fibo[0]=1;
    fibo[1]=0;
    fibo[2]=1;
    for(int i=3; i<max+2; i++){
        fibo[i] = fibo[i-1]+fibo[i-2];
    }

    for(int i=0; i<input.size(); i++){
        cout<<fibo[input[i]]<<" ";
        cout<<fibo[input[i]+1]<<"\n";
    }
}