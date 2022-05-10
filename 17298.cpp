// 오큰수 https://www.acmicpc.net/problem/17298

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long N, n, temp;
stack<long long> A, st, res;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N;

    for(int i=0; i<N; i++){
        cin>>n;
        A.push(n);
    }

    res.push(-1);
    st.push(A.top());
    A.pop();

    while(!A.empty()){

        if(st.empty()){
            res.push(-1);
            st.push(A.top());
            A.pop();
            continue;
        }

        while(st.top()<=A.top()){
            st.pop();

            if(st.empty()) break;
        }

        if(st.empty()){
            res.push(-1);
            st.push(A.top());
            A.pop();
        }
        else{
            res.push(st.top());
            st.push(A.top());
            A.pop();
        }

    }

    while(!res.empty()){
        cout<<res.top()<<" ";
        res.pop();
    }
}