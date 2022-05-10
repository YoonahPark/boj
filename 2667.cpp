// 단지 번호 붙이기 https://www.acmicpc.net/problem/2667

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int find(vector<string>* pv, int i, int j, int cnt){
    char g = (char)(cnt+49);
    int size = (*pv).size(), n=1;
    if(i>0){
        if((*pv)[i-1][j]=='1'){
            (*pv)[i-1][j]=g;
            n+=find(pv, i-1, j, cnt);
        }
    }
    if(i<size-1){
        if((*pv)[i+1][j]=='1'){
            (*pv)[i+1][j]=g;
            n+=find(pv, i+1, j, cnt);
        }
    }
    if(j>0){
        if((*pv)[i][j-1]=='1'){
            (*pv)[i][j-1]=g;
            n+=find(pv, i, j-1, cnt);
        }
    }
    if(j<size-1){
        if((*pv)[i][j+1]=='1'){
            (*pv)[i][j+1]=g;
            n+=find(pv, i, j+1, cnt);
        }
    }
    return n;
}

int main(){
    int N, cnt=0;
    cin>>N;
    string s;
    vector<string> v(N);
    vector<int> nums;

    for(int i=0; i<N; i++){
        cin>>s;
        v[i]=s;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(v[i][j]=='1'){
                cnt++;
                v[i][j]=(char)(cnt+49);
                nums.push_back(find(&v, i, j, cnt));
            }
        }
    }

    cout<<cnt<<"\n";

    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++){
        cout<<nums[i]<<"\n";
    }
}