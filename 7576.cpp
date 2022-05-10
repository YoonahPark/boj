// 토마토 https://www.acmicpc.net/problem/7576

#include <iostream>
#include <vector>
using namespace std;

int N, M, x, cnt;
vector<vector<int>> arr, v_vector;

bool is_enable(){
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==0){
                return 0;
            }
        }
    }
    return 1;
}

void bfs(vector<vector<int>> v_vector){
    vector<int> v;
    int i, j;
    vector<vector<int>> new_v_vector;

    ++cnt;

    for(int v_index = 0; v_index<v_vector.size(); v_index++){
        v = v_vector[v_index];
        i = v[0];
        j = v[1];

        if(i>0){
            if(arr[i-1][j]==0){
                arr[i-1][j] = 1;
                new_v_vector.push_back({i-1, j});
            }
        }
        if(i<N-1){
            if(arr[i+1][j]==0){
                arr[i+1][j] = 1;
                new_v_vector.push_back({i+1, j});
            }
        }
        if(j>0){
            if(arr[i][j-1]==0){
                arr[i][j-1] = 1;
                new_v_vector.push_back({i, j-1});
            }
        }
        if(j<M-1){
            if(arr[i][j+1]==0){
                arr[i][j+1] = 1;
                new_v_vector.push_back({i, j+1});
            }
        }
    }

    if(!new_v_vector.empty()) bfs(new_v_vector);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>M>>N;
    arr.resize(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j]==1){
                v_vector.push_back({i, j});
            }
        }
    }

    bfs(v_vector);

    if(is_enable()) cout<<cnt-1;
    else cout<<-1;

}