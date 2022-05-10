// 하노이 탑 이동 순서 https://www.acmicpc.net/problem/11729

#include <iostream>
#include <cmath>
using namespace std;

int hanoi_cnt(int N){
    if(N==1) return 1;
    else return 1+2*hanoi_cnt(N-1);
}

void hanoi(int N, int a, int b){
    if(N==1){
        cout<<a<<" "<<b<<"\n";
    }
    else{
        hanoi(N-1, a, 6-a-b);
        cout<<a<<" "<<b<<"\n";
        hanoi(N-1, 6-a-b, b);
    }
}

int main(){
    int N;
    cin>>N;
    cout<<hanoi_cnt(N)<<"\n";
    hanoi(N, 1, 3);
}