// N과 M(4) https://www.acmicpc.net/problem/15652

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> seq;

void bt(int n, int ind){
    for(int i=n; i<=N; i++){

        seq[ind] = i;

        if(ind==M-1){
            for(int j=0; j<M; j++){
                cout<<seq[j]<<" ";
            }
            cout<<"\n";
        }
        else bt(i, ind+1);
    }
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    seq.resize(M);
    bt(1, 0);
}