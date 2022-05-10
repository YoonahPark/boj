// 카드2 https://www.acmicpc.net/problem/2164

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int T;
vector<int> res;

int sol(){
    int N, M, n, d=0, i=0;
    vector<int> docs, sortedDocs;
    cin>>N>>M;

    for(int i=0; i<N; i++){
        cin>>n;
        docs.push_back(n);
    }

    sortedDocs = docs;
    sort(sortedDocs.rbegin(), sortedDocs.rend());

    for(; i<sortedDocs.size(); i++){
        while(1){
            if(sortedDocs[i]==docs[d%N]){
                if(d%N==M) return i+1;
                docs[d%N]=0;
                d++;
                break;
            }
            d++;
        }
    }

}

int main(){
    cin>>T;
    
    for(int i=0; i<T; i++){
        res.push_back(sol());
    }

    for(int i=0; i<T; i++){
        cout<<res[i]<<"\n";
    }
}