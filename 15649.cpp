// N과 M(1) https://www.acmicpc.net/problem/15649

#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> seq, nums;

void bt(int ind){
    for(int i=1; i<=N; i++){

        if(nums[i]==0){

            seq[ind] = i;
            nums[i] = 1;

            if(ind==M-1){
                for(int j=0; j<M; j++){
                    cout<<seq[j]<<" ";
                }
                cout<<"\n";
            }
            else bt(ind+1);

            nums[i] = 0;
        }
    }
}



int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    seq.resize(M);
    nums.resize(N+1);

    bt(0);
}