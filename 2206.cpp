// 벽 부수고 이동하기 https://www.acmicpc.net/problem/2206

#include <iostream>
#include <vector>
using namespace std;

int N, M, x, min_res=1000001, res;
string s;
vector<vector<int>> originalMap, map, upper_map, lower_map;

void bfs(vector<vector<int>> v_vector){
    vector<int> v;
    int i, j, x;
    vector<vector<int>> new_v_vector;

    for(int v_index = 0; v_index<v_vector.size(); v_index++){
        v = v_vector[v_index];
        i = v[0];
        j = v[1];
        x = map[i][j]+1;

        if(i>0){
            if(map[i-1][j]==0){
                map[i-1][j] = x;
                new_v_vector.push_back({i-1, j});
            }
        }
        if(i<N-1){
            if(map[i+1][j]==0){
                map[i+1][j] = x;
                new_v_vector.push_back({i+1, j});
            }
        }
        if(j>0){
            if(map[i][j-1]==0){
                map[i][j-1] = x;
                new_v_vector.push_back({i, j-1});
            }
        }
        if(j<M-1){
            if(map[i][j+1]==0){
                map[i][j+1] = x;
                new_v_vector.push_back({i, j+1});
            }
        }
    }

    if(!new_v_vector.empty()) bfs(new_v_vector);
}

int find_min_res(int i, int j){

    int upper_min=1000001, lower_min=1000001;

    if(i>0){
        if(originalMap[i-1][j]==0 && upper_map[i-1][j]>0 && upper_map[i-1][j]<upper_min){
            upper_min = upper_map[i-1][j];
        }
    }
    if(i<N-1){
        if(originalMap[i+1][j]==0 && upper_map[i+1][j]>0 && upper_map[i+1][j]<upper_min){
            upper_min = upper_map[i+1][j];
        }
    }
    if(j>0){
        if(originalMap[i][j-1]==0 && upper_map[i][j-1]>0 && upper_map[i][j-1]<upper_min){
            upper_min = upper_map[i][j-1];
        }
    }
    if(j<M-1){
        if(originalMap[i][j+1]==0 && upper_map[i][j+1]>0 && upper_map[i][j+1]<upper_min){
            upper_min = upper_map[i][j+1];
        }
    }

    if(i>0){
        if(originalMap[i-1][j]==0 && lower_map[i-1][j]>0 && lower_map[i-1][j]<lower_min){
            lower_min = lower_map[i-1][j];
        }
    }
    if(i<N-1){
        if(originalMap[i+1][j]==0 && lower_map[i+1][j]>0 && lower_map[i+1][j]<lower_min){
            lower_min = lower_map[i+1][j];
        }
    }
    if(j>0){
        if(originalMap[i][j-1]==0 && lower_map[i][j-1]>0 && lower_map[i][j-1]<lower_min){
            lower_min = lower_map[i][j-1];
        }
    }
    if(j<M-1){
        if(originalMap[i][j+1]==0 && lower_map[i][j+1]>0 && lower_map[i][j+1]<lower_min){
            lower_min = lower_map[i][j+1];
        }
    }

    return upper_min+lower_min+1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    originalMap.resize(N, vector<int>(M, 0));

    for(int i=0; i<N; i++){
        cin>>s;
        for(int j=0; j<M; j++){
            if(s[j]=='1') originalMap[i][j]=1;
        }
    }

    map = originalMap;
    map[0][0] = 1;
    bfs({{0, 0}});
    upper_map = map;

    map = originalMap;
    map[N-1][M-1] = 1;
    bfs({{N-1, M-1}});
    lower_map = map;


    if(upper_map[N-1][M-1]>0){
        min_res = upper_map[N-1][M-1];
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){

            if(originalMap[i][j]==1){
                res = find_min_res(i, j);
                min_res = min(min_res, res);
            }

        }
    }

    if(min_res>=1000001) min_res = -1;
    cout<<min_res;
}