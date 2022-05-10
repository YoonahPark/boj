// 전깃줄 https://www.acmicpc.net/problem/2565

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, a, b;
    cin>>N;
    vector<vector<int>> v;
    vector<int> temp(2), length(N, 1);

    for(int i=0; i<N; i++){
        cin>>temp[0]>>temp[1];
        v.push_back(temp);
    }

    sort(v.begin(), v.end());


    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[j][1]>v[i][1]){
                length[j] = max(length[j], length[i]+1);
            }
        }
    }


    int max_length=0;
    for(int i=0; i<N; i++){
        if(length[i]>max_length){
            max_length = length[i];
        }
    }
    cout<<N-max_length;
}