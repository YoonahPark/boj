#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, K, n, cnt=0;
    vector<int> v;
    cin>>N>>K;

    for(int i=0; i<N; i++){
        cin>>n;
        v.push_back(n);
    }
    
    int i=v.size()-1;
    
    while(K!=0){
        cnt += K/v[i];
        K = K%v[i];
        i--;
        
    }

    cout<<cnt;
}
