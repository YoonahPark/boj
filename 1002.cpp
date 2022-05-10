#include <iostream>
#include <vector>
using namespace std;

int square(int n){
    return n*n;
}
int main(){
    int T, x1, y1, r1, x2, y2, r2;
    int D, R1, R2;
    cin>>T;
    vector<int> v(T);
    
    for(int i=0; i<T; i++){
        cin>>x1>>y1>>r1>>x2>>y2>>r2;
        D = square(x1-x2)+square(y1-y2);
        R1 = square(r1-r2);
        R2 = square(r1+r2);

        if(D==0){
            if(R1!=0) v[i]=0;
            else v[i]=-1;
        }

        else{
            if(D>R2) v[i]=0;
            else if(D==R2) v[i]=1;
            else if(D>R1) v[i]=2;
            else if(D==R1) v[i]=1;
            else v[i]=0;
        }
    }
    for(int i=0; i<T; i++){
        cout<<v[i]<<"\n";
    }
}