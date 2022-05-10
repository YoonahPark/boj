// 암호 만들기 https://www.acmicpc.net/problem/1759

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C, cnt;
char ch;
vector<char> chars, cipher;

bool is_valid(){
    int m=0;
    for(int i=0; i<L; i++){
        switch(cipher[i]){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            ++m;
        }
    }
    return m>=1 && L-m>=2;
}

void sol(int ind, int n){
    cipher[ind] = chars[n];
    if(ind==L-1 && is_valid()){

        for(int i=0; i<L; i++){
            cout<<cipher[i];
        }
        cout<<"\n";
    }

    else{
        for(int i=n+1; i<C; i++){
            if(chars[n]<chars[i]){
                sol(ind+1, i);
            }
        }
    }
}

int main(){
    cin>>L>>C;
    cipher.resize(L);

    for(int i=0; i<C; i++){
        cin>>ch;
        chars.push_back(ch);
    }

    sort(chars.begin(), chars.end());

    for(int i=0; i<C; i++){
        sol(0, i);
    }
}