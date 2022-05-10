#include <iostream>
#include <vector>
using namespace std;

vector<int> res;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int n, first_ring, ring, g;
    cin>>n;
    cin>>first_ring;

    for(int i=0; i<n-1; i++){
        cin>>ring;
        g = gcd(max(first_ring, ring), min(first_ring, ring));
        res.push_back(first_ring/g);
        res.push_back(ring/g);
    }

    for(int i=0; i<n-1; i++){
        cout<<res[2*i]<<"/"<<res[2*i+1]<<"\n";
    }
}