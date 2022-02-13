// 박스 채우기 https://www.acmicpc.net/problem/1493

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> cubes;
vector<int> counts;
int enable=1;
int res;

int count_cube(long l, long w, long h){
    if(l*w*h==0) return 0;
    if(!enable) return 0;

    long s;

    for(int i=cubes.size()-1; i>=0; i--){
        s=cubes[i];
        if(counts[i]==0) continue;
        if(s>l || s>w || s>h) continue;
        
        counts[i]--;
        res++;
        count_cube(l-s, s, h);
        count_cube(s, s, h-s);
        count_cube(l, w-s, h);
        return 0;
    }

    enable=0;
    return 0;
}

int main(){
    long l, w, h;
    int N, a, b;
    cin>>l>>w>>h>>N;

    for(int i=0; i<N; i++){
        cin>>a>>b;
        cubes.push_back(pow(2, a));
        counts.push_back(b);
    }

    count_cube(l, w, h);
    if(!enable) res = -1;
    cout<<res;
}