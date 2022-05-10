#include <iostream>
#include <vector>
using namespace std;

int T, l, x, y, X, Y, cnt;
vector<vector<bool>> visited;
vector<int> res;

void bfs(vector<vector<int>> v_vector){
    vector<int> v;
    vector<vector<int>> new_v_vector;
    int old_x, old_y, new_x, new_y;

    ++cnt;

    for(int v_index = 0; v_index<v_vector.size(); v_index++){
        v = v_vector[v_index];
        old_x = v[0];
        old_y = v[1];

        if(old_x==X && old_y==Y){
            new_v_vector.clear();
            break;
        }

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x+2;
        new_y = old_y+1;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x+2;
        new_y = old_y-1;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x-2;
        new_y = old_y+1;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x-2;
        new_y = old_y-1;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x+1;
        new_y = old_y+2;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x+1;
        new_y = old_y-2;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x-1;
        new_y = old_y+2;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }

        new_x = old_x-1;
        new_y = old_y-2;

        if(new_x>=0 && new_x<l && new_y>=0 && new_y<l){
            if(visited[new_x][new_y]==0){
                visited[new_x][new_y]=1;
                new_v_vector.push_back({new_x, new_y});
            }
        }
        
    }
    if(!new_v_vector.empty()) bfs(new_v_vector);
}

void execute(){
    cin>>l>>x>>y>>X>>Y;
    visited.clear();
    visited.resize(l, vector<bool>(l, 0));
    visited[x][y]=1;
    cnt=-1;
    bfs({{x, y}});
    res.push_back(cnt);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>T;
    for(int i=0; i<T; i++){
        execute();
    }

    for(int i=0; i<T; i++){
        cout<<res[i]<<"\n";
    }
}