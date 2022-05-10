// 숨바꼭질 https://www.acmicpc.net/problem/1697

#include <iostream>
#include <vector>
using namespace std;

int N, K, x, res=-1;
vector<bool> visited(200000);

void bfs(vector<int> v_vector){
    int v;
    vector<int> new_v_vector;

    ++res;

    for(int v_index = 0; v_index<v_vector.size(); v_index++){
        v = v_vector[v_index];

        if(v==K){
            new_v_vector.clear();
            break;
        }

        if(v<K){
            if(visited[v*2]==0){
                new_v_vector.push_back(v*2);
                visited[v*2]=1;
            }
            if(visited[v+1]==0){
                new_v_vector.push_back(v+1);
                visited[v+1]=1;
            }
        }

        if(v>0){
            if(visited[v-1]==0){
                new_v_vector.push_back(v-1);
                visited[v-1]=1;
            }
        }
        
    }

    if(!new_v_vector.empty()) bfs(new_v_vector);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>K;

    bfs({N});

    cout<<res;
}