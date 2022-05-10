// 미로 탐색 https://www.acmicpc.net/problem/2178

#include <iostream>
#include <vector>
using namespace std;

int N, M, x, res;
string s;
vector<vector<bool>> maze;

void bfs(vector<vector<int>> v_vector){
    vector<int> v;
    int i, j;
    vector<vector<int>> new_v_vector;

    ++res;

    for(int v_index = 0; v_index<v_vector.size(); v_index++){
        v = v_vector[v_index];
        i = v[0];
        j = v[1];

        if(i==N-1 && j==M-1){
            new_v_vector.clear();
            break;
        }

        if(i>0){
            if(maze[i-1][j]==1){
                maze[i-1][j] = 0;
                new_v_vector.push_back({i-1, j});
            }
        }
        if(i<N-1){
            if(maze[i+1][j]==1){
                maze[i+1][j] = 0;
                new_v_vector.push_back({i+1, j});
            }
        }
        if(j>0){
            if(maze[i][j-1]==1){
                maze[i][j-1] = 0;
                new_v_vector.push_back({i, j-1});
            }
        }
        if(j<M-1){
            if(maze[i][j+1]==1){
                maze[i][j+1] = 0;
                new_v_vector.push_back({i, j+1});
            }
        }
    }

    if(!new_v_vector.empty()) bfs(new_v_vector);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    maze.resize(N, vector<bool>(M, 0));

    for(int i=0; i<N; i++){
        cin>>s;
        for(int j=0; j<M; j++){
            if(s[j]=='1') maze[i][j]=1;
        }
    }

    bfs({{0, 0}});

    cout<<res;
}