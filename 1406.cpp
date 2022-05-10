#include <iostream>
#include <list>

using namespace std;

int M;
char command, newChar;
string s;
list<char> LL;
list<char>::iterator cursor, temp;

void L(){
    temp = cursor;
    temp++;

    if(temp!=LL.begin()){
        --cursor;
    }
}

void D(){
    ++cursor;
    if(cursor==LL.end()){
        --cursor;
    }
}

void B(){
    temp = cursor;
    temp++;

    if(temp!=LL.begin()){
        temp = cursor;
        cursor--;
        LL.erase(temp);
    }
}

void P(){
    cursor++;
    LL.insert(cursor, newChar);
    cursor--;
}


int main(){
    cin>>s>>M;
    for(int i=0; i<s.size(); i++){
        LL.push_back(s[i]);
    }

    cursor = LL.end();
    cursor--;

    for(int i=0; i<M; i++){
        cin>>command;
        switch(command){
            case 'L': L(); break;
            case 'D': D(); break;
            case 'B': B(); break;
            case 'P': cin>>newChar; P(); break;
        }

        temp = LL.begin();
    }

    temp = LL.begin();
    for(int i=0; i<LL.size(); i++){
        cout<<*temp;
        temp++;
    }
}