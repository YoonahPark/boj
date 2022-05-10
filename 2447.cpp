// 별 찍기 - 10 https://www.acmicpc.net/problem/2447

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void f(vector<string> v, int N){
    if(N==1){
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v.size(); j++){
                cout<<v[i][j];
            }
            cout<<"\n";
        }
    }

    else{
        for(int i=0; i<v.size(); i++){
            if(i%N/(N/3)==1){
                for(int j=0; j<v.size(); j++){
                    if(j%N/(N/3)==1){
                        if(v[i][j]=='*') v[i][j]=' ';
                    }
                }
            }
        }
        f(v, N/3);
    }
}

int main(){
    int N;
    cin>>N;

    string s(N, '*');
    vector<string> v(N, s);

    f(v, N);
}