// 신나는 함수 실행 https://www.acmicpc.net/problem/9184

#include <iostream>
#include <vector>
using namespace std;

int a, b, c;
vector<long long> res;

void sol(){
    
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);

    if(a<=0 || b<=0 || c<=0){
        a=0;
        b=0;
        c=0;
    }

    if(a>20 || b>20 || c>20){
        a=20;
        b=20;
        c=20;
    }

    long long arr[a+1][b+1][c+1];

    for(int i=0; i<=a; i++){
        for(int j=0; j<=b; j++){
            for(int k=0; k<=c; k++){

                if(i<=0 || j<=0 || k<=0){
                    arr[i][j][k]=1;
                }

            }
        }
    }

    for(int i=1; i<=a; i++){
        for(int j=1; j<=b; j++){
            for(int k=1; k<=c; k++){

                if(i<j && j<k){
                    arr[i][j][k] = arr[i][j][k-1] + arr[i][j-1][k-1] - arr[i][j-1][k];
                }
                else{
                    arr[i][j][k] = arr[i-1][j][k] + arr[i-1][j-1][k] + arr[i-1][j][k-1] - arr[i-1][j-1][k-1];
                }

            }
        }
    }

    res.push_back(arr[a][b][c]);

}

int main(){

    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    while(1){
        cin>>a>>b>>c;
        if(a==-1 && b==-1 && c==-1){
            break;
        }
        sol();
    }

    for(int i=0; i<res.size()/4; i++){
        cout<<"w(";
        cout<<res[i*4]<<", ";
        cout<<res[i*4+1]<<", ";
        cout<<res[i*4+2]<<") = ";
        cout<<res[i*4+3]<<"\n";
    }
}