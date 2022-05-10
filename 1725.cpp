#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long long N, n, temp, res=0, i=1;
vector<long long> H;
stack<long long> st;

int main(){
    cin>>N;
    st.push(0);
    H.push_back(0);

    for(; i<N+1; i++){
        cin>>n;
        H.push_back(n);
        if(n>=H[st.top()]){
            st.push(i);
        }
        else{
            while(n<H[st.top()]){
                temp = H[st.top()];
                st.pop();

                if(st.empty()) break;

                res = max(res, temp*(i-st.top()-1));
            }
            st.push(i);
        }
    }

    while(1){
        temp = H[st.top()];
        st.pop();

        if(st.empty()) break;

        res = max(res, temp*(i-st.top()-1));
    }

    cout<<res;
}