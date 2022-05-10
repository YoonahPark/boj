#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s, res="";
char c;
stack<char> st;

int main(){

    cin>>s;

    for(int i=0; i<s.size(); i++){

        c=s[i];

        if(c=='('){
            st.push(c);
        }

        else if(c==')'){
            while(st.top()!='('){
                res += st.top();
                st.pop();
            }
            st.pop();
        }

        else if(c=='+' || c=='-'){
            if(!st.empty()){
                while(st.top()=='+' || st.top()=='-' || st.top()=='*' || st.top()=='/'){
                    res += st.top();
                    st.pop();
                    if(st.empty()) break;
                }
            }
            st.push(c);
        }

        else if(c=='/' || c=='*' ){
            if(!st.empty()){
                while(st.top()=='/' || st.top()=='*'){
                    res += st.top();
                    st.pop();
                    if(st.empty()) break;
                }
            }
            st.push(c);
        }

        else{
            res += c;
        }

    }

    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    
    cout<<res;
}