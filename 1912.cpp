#include <iostream>
using namespace std;

int main(){
    int N, n, min=0, max=-2000;
    cin>>N;

    int v[N+1];
    v[0]=0;

    for(int i=1; i<N+1; i++){
        cin>>n;
        v[i]=v[i-1]+n;
    }

    for(int i=1; i<N+1; i++){
        if(v[i]-min>max) max=v[i]-min;
        if(v[i]<min) min=v[i];
    }
    cout<<max;

}