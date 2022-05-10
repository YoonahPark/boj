// RGB거리 https://www.acmicpc.net/problem/1149

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    vector<int> v(3);
    vector<vector<int>> cost;

    for(int i=0; i<N; i++){
        cin>>v[0]>>v[1]>>v[2];
        cost.push_back(v);
    }

    for(int i=1; i<N; i++){
        cost[i][0] += min(cost[i-1][1], cost[i-1][2]);
        cost[i][1] += min(cost[i-1][0], cost[i-1][2]);
        cost[i][2] += min(cost[i-1][0], cost[i-1][1]);
    }

    int res;
    res = min(cost[N-1][0], cost[N-1][1]);
    res = min(cost[N-1][2], res);
    cout<<res;
}