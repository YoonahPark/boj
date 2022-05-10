#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v(N);
    vector<int> mass;

    for(int i=0; i<N; i++){
        cin>>v[i];
    }
    mass=v;

    for(int i=0; i<N-1; i++){
        for(int j=i+1; j<N; j++){
            if(v[j]>v[i]){
                mass[j] = max(mass[j], mass[i]+v[j]);
            }
        }
    }

    int max_mass=0;
    for(int i=0; i<N; i++){
        if(mass[i]>max_mass){
            max_mass = mass[i];
        }
    }
    cout<<max_mass;
}