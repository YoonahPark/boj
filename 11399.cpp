// ATM https://www.acmicpc.net/problem/11399

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v(N);

    for(int i=0; i<N; i++){
        cin>>v[i];
    }

    int ind, min, sum=0, res=0;

    for(int i=0; i<N; i++){
        ind=0;
        for(int j=0; j<v.size(); j++){
            if(v[j]<v[ind]){
                ind=j;
            }
        }
        sum+=v[ind];
        res+=sum;
        v.erase(v.begin()+ind);
    }

    cout<<res;
}