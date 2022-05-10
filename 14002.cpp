#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v(N);
    vector<vector<int>> seqs;
    vector<int> seq;

    for(int i=0; i<N; i++){
        cin>>v[i];
        seqs.push_back({v[i]});
    }

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[j]>v[i]){
                if(seqs[j].size()<seqs[i].size()+1){
                    seq = seqs[i];
                    seq.push_back(v[j]);
                    seqs[j]=seq;
                }
            }
        }
    }

    int max_length=0;
    for(int i=0; i<N; i++){
        if(seqs[i].size()>max_length){
            max_length = seqs[i].size();
        }
    }

    cout<<max_length<<"\n";

    for(int i=0; i<N; i++){
        if(seqs[i].size()==max_length){
            for(int j=0; j<seqs[i].size(); j++){
                cout<<seqs[i][j]<<" ";
            }
            break;
        }
    }
}