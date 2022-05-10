// 스택 수열 https://www.acmicpc.net/problem/1874

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

long n, k, pivot, num=1;
vector<long> v;
stack<long> st;
string s;

int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>k;
        v.push_back(k);
    }

    for(int i=0; i<n; i++){

        pivot = v[i];

        if(pivot==num){
            s += "+-";
            ++num;
        }

        else if(pivot<num){
            if(st.empty()){
                s = "NO";
                break;
            }
            if(pivot!=st.top()){
                s = "NO";
                break;
            }
            else{
                st.pop();
                s += "-";
                continue;
            }
        }

        else{
            while(pivot>num){
                st.push(num);
                s += "+";
                ++num;
            }
            s += "+-";
            ++num;
        }

    }

    if(s=="NO") cout<<s;
    else{
        for(int i=0; i<s.size(); i++){
            cout<<s[i]<<"\n";
        }
    }

}