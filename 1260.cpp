// DFS와 BFS https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
using namespace std;

int N, M, V, a, b;
vector<bool> visited_dfs, visited_bfs;
vector<vector<bool>> graph;

void dfs(int v){
    cout<<v<<" ";
    visited_dfs[v] = 1;
    for(int i=1; i<=N; i++){
        if(graph[v][i]==1 && visited_dfs[i]==0){
            dfs(i);
        }
    }
}

void bfs(vector<int> v_vector){
    int v;
    vector<int> new_v_vector;

    for(int v_index = 0; v_index<v_vector.size(); v_index++){
        v = v_vector[v_index];

        for(int i=1; i<=N; i++){
            if(graph[v][i]==1 && visited_bfs[i]==0){
                cout<<i<<" ";
                visited_bfs[i] = 1;
                new_v_vector.push_back(i);
            }
        }
    }

    if(!new_v_vector.empty()) bfs(new_v_vector);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M>>V;
    visited_dfs.resize(N+1, 0);
    visited_bfs.resize(N+1, 0);
    graph.resize(N+1, vector<bool>(N+1, 0));

    for(int i=0; i<M; i++){
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(V);

    cout<<"\n";

    cout<<V<<" ";
    visited_bfs[V] = 1;
    bfs({V});
}