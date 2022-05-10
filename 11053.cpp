#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v(N);
    vector<int> length(N, 1);

    for(int i=0; i<N; i++){
        cin>>v[i];
    }

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[j]>v[i]){
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
    cout<<max_length;
}