// N-Queen https://www.acmicpc.net/problem/9663

#include <iostream>
#include <vector>
using namespace std;

long long N, cnt=0;
vector<bool> cols(14), sums(27), difs(27);

void bt(long long i){
    for(long long j=0; j<N; j++){
        if(cols[j]) continue;
        else if(sums[i+j]) continue;
        else if(difs[i-j+N-1]) continue;
        else{

            if(i==N-1) ++cnt;
            else{

                cols[j] = 1;
                sums[i+j] = 1;
                difs[i-j+N-1] = 1;

                bt(i+1);

                cols[j] = 0;
                sums[i+j] = 0;
                difs[i-j+N-1] = 0;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N;
    bt(0);
    cout<<cnt;
}