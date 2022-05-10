// 스티커 https://www.acmicpc.net/problem/9465

#include <iostream>
#include <vector>
using namespace std;

vector<int> ans, v(100000);
vector<vector<int>> sticker(2, v);
vector<vector<int>> result(2, v);

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int T, N, n, res;
    cin>>T;

    for(int t=0; t<T; t++){
        cin>>N;
        for(int i=0; i<2; i++){
            for(int j=0; j<N; j++){
                cin>>sticker[i][j];
            }
        }

        for(int j=0; j<N; j++){
            for(int i=0; i<2; i++){
                res=sticker[i][j];
                if(j==0){
                    result[i][j]=res;
                }
                else if(j==1){
                    res += sticker[1-i][1-j];
                    result[i][j]=res;
                }
                else{
                    res += max(result[1-i][j-1], result[1-i][j-2]);
                    result[i][j]=res;
                }
            }
        }
        res = max(result[0][N-1], result[1][N-1]);
        ans.push_back(res);
    }

    for(int t=0; t<T; t++){
        cout<<ans[t]<<"\n";
    }
}