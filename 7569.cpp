// 토마토 https://www.acmicpc.net/problem/7569

#include <iostream>
#include <vector>
using namespace std;

int N, M, H, x, cnt;
vector<vector<vector<int>>> arr;
vector<vector<int>> v_vector;

bool is_enable(){
    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(arr[i][j][k]==0){
                    return 0;
                }
            }
        }
    }
    return 1;
}

void bfs(vector<vector<int>> v_vector){
    vector<int> v;
    int i, j, k;
    vector<vector<int>> new_v_vector;

    ++cnt;

    for(int v_index = 0; v_index<v_vector.size(); v_index++){
        v = v_vector[v_index];
        i = v[0];
        j = v[1];
        k = v[2];

        if(i>0){
            if(arr[i-1][j][k]==0){
                arr[i-1][j][k] = 1;
                new_v_vector.push_back({i-1, j, k});
            }
        }
        if(i<H-1){
            if(arr[i+1][j][k]==0){
                arr[i+1][j][k] = 1;
                new_v_vector.push_back({i+1, j, k});
            }
        }
        if(j>0){
            if(arr[i][j-1][k]==0){
                arr[i][j-1][k] = 1;
                new_v_vector.push_back({i, j-1, k});
            }
        }
        if(j<N-1){
            if(arr[i][j+1][k]==0){
                arr[i][j+1][k] = 1;
                new_v_vector.push_back({i, j+1, k});
            }
        }
        if(k>0){
            if(arr[i][j][k-1]==0){
                arr[i][j][k-1] = 1;
                new_v_vector.push_back({i, j, k-1});
            }
        }
        if(k<M-1){
            if(arr[i][j][k+1]==0){
                arr[i][j][k+1] = 1;
                new_v_vector.push_back({i, j, k+1});
            }
        }
    }

    if(!new_v_vector.empty()) bfs(new_v_vector);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>M>>N>>H;
    arr.resize(H, vector<vector<int>>(N, vector<int>(M, 0)));

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                cin>>arr[i][j][k];
            }
        }
    }

    for(int i=0; i<H; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<M; k++){
                if(arr[i][j][k]==1){
                    v_vector.push_back({i, j, k});
                }
            }
        }
    }

    bfs(v_vector);

    if(is_enable()) cout<<cnt-1;
    else cout<<-1;

}