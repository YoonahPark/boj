// 가장 긴 증가하는 부분 수열 https://www.acmicpc.net/problem/11055

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<long> v(N), desc(N, 1), asc(N, 1);

    for(int i=0; i<N; i++){
        cin>>v[i];
    }

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[j]>v[i]){
                asc[j] = max(asc[j], asc[i]+1);
            }
        }
    }

    for(int i=N-1; i>0; i--){
        for(int j=i-1; j>=0; j--){
            if(v[j]>v[i]){
                desc[j] = max(desc[j], desc[i]+1);
            }
        }
    }

    int max_length=0;
    for(int i=0; i<N; i++){
        if(asc[i]+desc[i]>max_length){
            max_length = asc[i]+desc[i];
        }
    }
    cout<<max_length-1;
}