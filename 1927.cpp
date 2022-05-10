// 최소 힙 https://www.acmicpc.net/problem/1927

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

long long N, x;
vector<long long> res;
vector<long long> pq;

bool empty(){
    return pq.size()==0;
}

long long top(){
    return pq[0];
}

void pop(){
    if(empty()){
        return;
    }

    int sz = pq.size(), temp;
    pq[0] = pq[sz-1];
    pq.pop_back();
    
    sz=0;
    while(sz*2+2<pq.size()){
        if(pq[sz] > pq[sz*2+1] || pq[sz] > pq[sz*2+2]){
            if(pq[sz*2+1] > pq[sz*2+2]){
                temp = pq[sz];
                pq[sz] = pq[sz*2+2];
                pq[sz*2+2] = temp;
                sz = sz*2+2;
            }
            else{
                temp = pq[sz];
                pq[sz] = pq[sz*2+1];
                pq[sz*2+1] = temp;
                sz = sz*2+1;
            }
        }
        else{
            break;
        }
    }
    if(sz*2+2==pq.size()){
        if(pq[sz] > pq[sz*2+1]){
            temp = pq[sz];
            pq[sz] = pq[sz*2+1];
            pq[sz*2+1] = temp;
        }
    }
}

void push(long long x){
    int sz = pq.size(), temp;

    pq.push_back(x);
    while(sz>0){
        if(pq[sz]<pq[(sz+1)/2-1]){
            temp = pq[sz];
            pq[sz] = pq[(sz+1)/2-1];
            pq[(sz+1)/2-1] = temp;
            sz = (sz+1)/2-1;
        }

        else{
            break;
        }
    }
}

void printpq(){
    for(int i=0; i<pq.size(); i++){
        cout<<pq[i]<<" ";
    }
    cout<<"\n";
}


void oper0(){
    if(empty()) res.push_back(0);
    else{
        res.push_back(top());
        pop();
    }
}

void addX(long long x){
    push(x);
}

void oper(){
    if(x==0) oper0();
    else addX(x);
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>x;
        oper();
    }

    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<"\n";
    }
    
}
