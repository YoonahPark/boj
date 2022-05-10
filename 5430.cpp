// 덱 https://www.acmicpc.net/problem/10866

#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int T, n;
deque<string> deq, emptyDeque;
string p, x, item, res;
int startFromBack=1;
char c, f;
vector<string> ans;

void addNums(){
    cin>>p>>n>>x;
    item = "";
    for(int i=1; i<x.size(); i++){
        c=x[i];
        if(c>='0' && c<='9'){
            item += to_string(c-48);
        }
        else if(n>0){
            deq.push_front(item);
            item = "";
        }
    }
}

void R(){
    startFromBack = 1 - startFromBack;
}

void D(){
    if(deq.empty()){
        res = "error";
    }
    else if(startFromBack){
        deq.pop_back();
    }
    else{
        deq.pop_front();
    }

}

void getResult(){

    startFromBack = 1;

    for(int i=0; i<p.size(); i++){
        f = p[i];
        if(f=='R'){
            R();
        }
        else{
            D();
            if(res=="error") break;
        }
    }
}

void createResultString(){
    res = "[";

    if(startFromBack){
        while(!deq.empty()){
            res += deq.back();
            deq.pop_back();
            if(deq.empty()) break;
            res += ",";
        }
    }
    else{
        while(!deq.empty()){
            res += deq.front();
            deq.pop_front();
            if(deq.empty()) break;
            res += ",";
        }
    }
    res += "]";
}

void execute(){

    deq = emptyDeque;
    addNums();
    getResult();
    if(res!="error"){
        createResultString();
    }
    ans.push_back(res);
    res = "";
}

int main(){
    cin>>T;
    for(int i=0; i<T; i++){
        execute();
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
}