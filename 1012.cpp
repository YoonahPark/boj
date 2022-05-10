#include <iostream>
#include <vector>
using namespace std;

int T, M, N, K, X, Y, cnt;
vector<vector<int>> ground(50, vector<int>(50, 0)), empty_vector;
vector<int> res;

void find(int x, int y){

    ground[x][y]=0;

    if(x!=0){
        if(ground[x-1][y]==1) find(x-1, y);
    }
    if(x!=M-1){
        if(ground[x+1][y]==1) find(x+1, y);
    }
    if(y!=0){
        if(ground[x][y-1]==1) find(x, y-1);
    }
    if(y!=N-1){
        if(ground[x][y+1]==1) find(x, y+1);
    }

}

void count(){
    for(int x=0; x<M; x++){
        for(int y=0; y<N; y++){
            if(ground[x][y]==1){
                find(x, y);
                ++cnt;
            }
        }
    }
}

int sol(){
    ground = empty_vector;
    cin>>M>>N>>K;

    for(int i=0; i<K; i++){
        cin>>X>>Y;
        ground[X][Y]=1;
    }

    cnt=0;
    count();
    return cnt;
}

int main(){
    empty_vector = ground;
    cin>>T;
    for(int i=0; i<T; i++){
        res.push_back(sol());
    }
    for(int i=0; i<T; i++){
        cout<<res[i]<<"\n";
    }

}