// 스타트와 링크 https://www.acmicpc.net/problem/14889

#include <iostream>
#include <vector>
using namespace std;

int N, n, ans=-1;
vector<int> team, start, link, temp;
vector<vector<int>> stat;

void setTeam(){
    start.clear();
    link.clear();
    for(int i=0; i<N; i++){
        if(team[i]==1) start.push_back(i);
        else link.push_back(i);
    }
}

int cal(){
    int startStat=0, linkStat=0;

    for(int i=0; i<N/2-1; i++){
        for(int j=i; j<N/2; j++){
            startStat += stat[start[i]][start[j]];
            startStat += stat[start[j]][start[i]];
            linkStat += stat[link[i]][link[j]];
            linkStat += stat[link[j]][link[i]];
        }
    }

    return abs(startStat-linkStat);
}

void bt(int n, int ind){
    int res;

    for(int i=n; i<N-ind+1; i++){
        team[i] = 1;

        if(ind==1){
            setTeam();
            res = cal();
            if(ans==-1) ans = res;
            else if(res<ans) ans = res;
        }
        else bt(i+1, ind-1);

        team[i] = 0;
    }
}

int main(){

    cin>>N;
    stat.resize(N, vector<int>(N, 0));
    team.resize(N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>stat[i][j];
        }
    }

    bt(0, N/2);

    cout<<ans;
}