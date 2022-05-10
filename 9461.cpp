// 파도반 수열 https://www.acmicpc.net/problem/9461

#include <iostream>
#include <vector>
using namespace std;

vector<long long> v(101);

int main(){
    int T, N, max=0;
    vector<int> input;

    cin>>T;
    for(int i=0; i<T; i++){
        cin>>N;
        input.push_back(N);
        if(N>max) max=N;
    }

    v[1]=1;
    v[2]=1;
    v[3]=1;
    v[4]=2;
    v[5]=2;
    for(int i=6; i<max+1; i++){
        v[i]=v[i-5]+v[i-1];
        //cout<<i<<" "<<v[i]<<"\n";
    }

    //cout<<"\n\n"<<max<<"\n\n";

    for(int i=0; i<T; i++){
        cout<<v[input[i]]<<"\n";
    }
}