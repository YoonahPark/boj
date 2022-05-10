// 쿼드트리 https://www.acmicpc.net/problem/1992

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int g_size;
vector<string> image;
string s, res;

int make_string(int size, int I, int J){
    int n=image[I][J];
    for(int i=I; i<I+size; i++){
        for(int j=J; j<J+size; j++){
            if(image[i][j]!=n){
                size /= 2;
                res+="(";
                make_string(size, I, J);
                make_string(size, I, J+size);
                make_string(size, I+size, J);
                make_string(size, I+size, J+size);
                res+=")";
                return 0;
            }
        }
    }
    res+=n;
    return 0;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>g_size;
    string s;

    for(int i=0; i<g_size; i++){
        cin>>s;
        image.push_back(s);
    }

    make_string(g_size, 0, 0);
    cout<<res;
}