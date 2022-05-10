// 부분수열의 합 https://www.acmicpc.net/problem/1182

#include <iostream>
#include <vector>
using namespace std;

int count(vector<int> v, int i, int S){
    if(i+1==v.size()){
        if(v[i]==S) return 1;
        else return 0;
    }
    int sum = 0, j=i;
    for(; j<v.size()-1; j++){
        if(v[j]==S) sum++;
        sum += count(v, j+1, S-v[j]);
    }
    if(v[j]==S) sum++;
    return sum;
}

int main(){
    int N, S, n, sum, cnt=0;
    cin>>N>>S;
    vector<int> v(N);
    
    for(int i=0; i<N; i++){
        cin>>n;
        v[i]=n;
    }
    cout<<count(v, 0, S);
}