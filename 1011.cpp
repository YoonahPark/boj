// Fly me to the Alpha Centauri https://www.acmicpc.net/problem/1011

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main(){
    int T, x, y, distance, mx;
    cin>>T;
    vector<int> v(T);

    for(int i=0; i<T; i++){
        cin>>x>>y;
        distance = y-x;
        mx = floor((double)sqrt(distance));
        v[i] = 2*mx-1;
        v[i] += ceil((double)(distance-mx*mx)/(double)mx);
    }
    for(int i=0; i<T; i++){
        cout<<v[i]<<"\n";
    }
}