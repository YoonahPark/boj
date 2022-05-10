#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> v;
int N, L, H, maxH=0;
long long res;
stack<vector<int>> st;

int main(){

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>L>>H;
        v.push_back({L, H});
    }

    sort(v.begin(), v.end());

    for(int i=1; i<N; i++){
        if(v[i][1]>v[maxH][1]){
            maxH=i;
        }
    }

    res=v[maxH][1];

    int i=0;
    while(i<maxH){
        if(st.empty()){
            st.push(v[i]);
        }
        else if(v[i][1]>st.top()[1]){
            st.push(v[i]);
        }
        ++i;
    }

    int prev=v[i][0];
    while(!st.empty()){
        res += (long long)((prev-st.top()[0])*st.top()[1]);
        prev = st.top()[0];
        st.pop();
    }

    i=v.size()-1;
    while(i>maxH){
        if(st.empty()){
            st.push(v[i]);
        }
        else if(v[i][1]>st.top()[1]){
            st.push(v[i]);
        }
        --i;
    }

    prev=v[i][0];
    while(!st.empty()){
        res += (long long)((st.top()[0]-prev)*st.top()[1]);
        prev = st.top()[0];
        st.pop();
    }
    
    cout<<res;
}