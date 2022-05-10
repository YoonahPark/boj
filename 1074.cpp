// Z https://www.acmicpc.net/problem/1074

#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
long n, res=0;

void sol(long size, long i, long j){
    int I, J;
    if(size>1){
        size/=2;
        I = (r-i)/size;
        J = (c-j)/size;
        res += size*size*(2*I+J);
        i += size*I;
        j += size*J;
        sol(size, i, j);
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>r>>c;
    n = pow(2, N);
    sol(n, 0, 0);
    cout<<res;
}