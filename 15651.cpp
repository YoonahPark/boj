// N과 M(3) https://www.acmicpc.net/problem/15651

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> seq;

void bt(int ind){
    for(int i=1; i<=N; i++){

        seq[ind] = i;

        if(ind==M-1){
            for(int j=0; j<M; j++){
                cout<<seq[j]<<" ";
            }
            cout<<"\n";
        }
        else bt(ind+1);
        
    }
}



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    seq.resize(M);

    bt(0);
}