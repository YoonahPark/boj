// 수리공 항승 https://www.acmicpc.net/problem/1449

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, L, n, cnt=0, temp;
    vector<int> v;
    cin>>N>>L;

    for(int i=0; i<N; i++){
        cin>>n;
        v.push_back(n);
    }

    for(int i=v.size(); i>1; i--){
        for(int j=1; j<i; j++){
            if(v[j-1]>v[j]){
                temp = v[j];
                v[j] = v[j-1];
                v[j-1] = temp;
            }
        }
    }

    float s=v[0]-0.5;
    for(int i=0; i<v.size(); i++){
        if(s<=v[i]-0.5){
            s=v[i]-0.5;
            ++cnt;
            s+=L;
        }
        else if(s<v[i]+0.5){
            ++cnt;
            s+=L;
        }
    }

    cout<<cnt;
}
