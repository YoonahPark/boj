#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N, M, res=0;
    cin>>N>>M;
    vector<int> K(M);

    for(int i=0; i<M; i++){
        cin>>K[i];
    }

    for(int i=0; i<K.size()-1; i++){
        for(int j=i+1; j<K.size(); j++){
            K[j] -= K[i];
            if(K[j]<=0){
                K[j] += N-i;
            }
        }
    }

    for(int i=0; i<K.size(); i++){
        res += min(N-i-K[i]+1, K[i]-1);
    }
    cout<<res;
}