// 연산자 끼워넣기 https://www.acmicpc.net/problem/14888

#include <iostream>
#include <vector>
using namespace std;

int N, n;
vector<int> A, op, used, seq;
long long maxNum = -1000000000, minNum = 1000000000;

int cal(){
    int res = A[0];
    for(int i=1; i<A.size(); i++){
        switch(seq[i-1]){
            case 0: res += A[i]; break;
            case 1: res -= A[i]; break;
            case 2: res *= A[i]; break;
            case 3: res /= A[i]; break;
        }
    }
    return res;
}

void bt(int ind){
    int res;
    for(int i=0; i<op.size(); i++){

        if(used[i]==0){

            seq[ind] = op[i];
            used[i] = 1;

            if(ind==op.size()-1){
                res = cal();
                if(res>maxNum) maxNum = res;
                if(res<minNum) minNum = res;
            }
            else bt(ind+1);

            used[i] = 0;
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>n;
        A.push_back(n);
    }

    for(int i=0; i<4; i++){
        cin>>n;
        for(int j=0; j<n; j++){
            op.push_back(i);
        }
    }

    used.resize(op.size(), 0);
    seq.resize(op.size());
    bt(0);

    cout<<maxNum<<"\n"<<minNum;
}