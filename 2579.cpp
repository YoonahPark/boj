// 계단 오르기 https://www.acmicpc.net/problem/2597

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin>>n;
    vector<int> score(n);
    vector<int> max_score(n);

    for(int i=0; i<n; i++){
        cin>>score[i];
    }

    max_score[0]=score[0];
    max_score[1]=score[0]+score[1];
    max_score[2]=max(score[0], score[1])+score[2];

    for(int i=3; i<n; i++){
        max_score[i] = score[i];
        max_score[i] += max(max_score[i-2], max_score[i-3]+score[i-1]);
    }

    cout<<max_score[n-1];
}