// 이분 그래프 https://www.acmicpc.net/problem/1707

#include <iostream>
#include <vector>
using namespace std;

int K, V, E, u, v, no_flag;
vector<bool> res;
vector<vector<bool>> graph;
vector<int> visited;

void dfs(int v){
    for(int i=0; i<V; i++){
        if(graph[v][i]==1){

            if(visited[i]==visited[v]){
                no_flag = 1;
                break;
            }
            else if(visited[i]==0){
                visited[i] = -visited[v];
                dfs(i);
            }
        }
    }
}


bool sol(){
    cin>>V>>E;
    vector<int> a(V, 0);
    vector<vector<bool>> g(V, vector<bool>(V, 0));
    visited.resize(V);
    graph.resize(V, vector<bool>(V));
    visited = a;
    graph = g;
    no_flag = 0;
    

    for(int i=0; i<E; i++){
        cin>>u>>v;
        --u;
        --v;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    for(int i=0; i<V; i++){
        if(visited[i]==0){
            visited[i]=1;
            dfs(i);
        }
        if(no_flag==1) break;
    }

    for(int i=0; i<V; i++){
        if(visited[i]==0) no_flag = 1;
    }

    if(no_flag==1) return 0;
    else return 1;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>K;
    for(int i=0; i<K; i++){
        res.push_back(sol());
    }

    for(int i=0; i<K; i++){
        if(res[i]) cout<<"YES\n";
        else cout<<"NO\n";
    }
    
}