// 피보나치 수 6 https://www.acmicpc.net/problem/11444

#include <iostream>
#include <vector>
using namespace std;

int N=2;
long long n, Q=1000000007;
vector<vector<long long>> initial={{0, 1}, {0, 1}}, A={{0, 1}, {1, 1}}, res;


vector<vector<long long>> multiply(vector<vector<long long>> A, vector<vector<long long>> B){

    vector<vector<long long>> C(N, vector<long long>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                C[i][j] += ((A[i][k]%Q)*(B[k][j]%Q))%Q;
            }
            C[i][j] = C[i][j]%Q;
        }
    }
    return C;
}

vector<vector<long long>> power(vector<vector<long long>> A, long long B){
    vector<vector<long long>> res(N, vector<long long>(N)), n = A;

    for(int i=0; i<N; i++){
        res[i][i]=1;
    }

    if(B==0) return res;

    vector<int> v;

    while(B>0){
        v.push_back(B%2);
        B /= 2;
    }

    for(int i=0; i<v.size(); i++){
        if(v[i]){
            res = multiply(res, n);
        }
        n = multiply(n, n);
    }

    return res;
}


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>n;

    res = multiply(initial, power(A, n));
    cout<<res[0][0];
}