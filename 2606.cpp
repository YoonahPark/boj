// DFS와 BFS https://www.acmicpc.net/problem/1260

#include <iostream>
#include <vector>
using namespace std;

int N, M, res, a, b;
vector<bool> visited;
vector<vector<bool>> graph;

void dfs(int v){
    visited[v] = 1;
    ++res;
    for(int i=1; i<=N; i++){
        if(graph[v][i]==1 && visited[i]==0){
            dfs(i);
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M;
    visited.resize(N+1, 0);
    visited.resize(N+1, 0);
    graph.resize(N+1, vector<bool>(N+1, 0));

    for(int i=0; i<M; i++){
        cin>>a>>b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    dfs(1);
    cout<<res-1;
}