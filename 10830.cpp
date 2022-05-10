// 곱셈 https://www.acmicpc.net/problem/1629

#include <iostream>
#include <vector>
using namespace std;

int N;
long long B;
vector<vector<int>> A;

vector<vector<int>> multiply(vector<vector<int>> A, vector<vector<int>> B){

    vector<vector<int>> C(N, vector<int>(N, 0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                C[i][j] += (A[i][k]*B[k][j])%1000;
            }
            C[i][j] = C[i][j]%1000;
        }
    }
    return C;
}

vector<vector<int>> power(vector<vector<int>> A, long long B){
    vector<vector<int>> res(N, vector<int>(N)), n = A;

    for(int i=0; i<N; i++){
        res[i][i]=1;
    }

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

    cin>>N>>B;

    vector<int> A_row(N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>A_row[j];
        }
        A.push_back(A_row);
    }

    vector<vector<int>> res;
    res = power(A, B);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }
}