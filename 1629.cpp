// 곱셈 https://www.acmicpc.net/problem/1629

#include <iostream>
#include <vector>
using namespace std;

long res=1, a, b, c;
vector<int> v;

void divide(long b){
    while(b>0){
        v.push_back(b%2);
        b /= 2;
    }
}

long multiply(long b){
    if(b==0) return a%c;
    long n = a%c;

    for(int i=0; i<v.size(); i++){
        //cout<<i<<" "<<v[i]<<" "<<res<<" "<<n<<"\n";
        if(v[i]){
            res = (res*n)%c;
        }
        n = (n*n)%c;
    }
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>a>>b>>c;
    divide(b);

    cout<<multiply(b);
}