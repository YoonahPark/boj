// 후위 표기식 2 https://www.acmicpc.net/problem/1935

#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main(){

    int N, ind, n;
    vector<int> nums;

    string s;
    char c;

    double firstNum, secondNum;
    stack<double> st;

    cin>>N>>s;

    for(int i=0; i<N; i++){
        cin>>n;
        nums.push_back(n);
    }

    for(int i=0; i<s.size(); i++){
        c = s[i];
        if(c=='+'){
            secondNum = st.top();
            st.pop();
            firstNum = st.top();
            st.pop();
            firstNum += secondNum;
            st.push(firstNum);
        }
        else if(c=='-'){
            secondNum = st.top();
            st.pop();
            firstNum = st.top();
            st.pop();
            firstNum -= secondNum;
            st.push(firstNum);
        }
        else if(c=='*'){
            secondNum = st.top();
            st.pop();
            firstNum = st.top();
            st.pop();
            firstNum *= secondNum;
            st.push(firstNum);
        }
        else if(c=='/'){
            secondNum = st.top();
            st.pop();
            firstNum = st.top();
            st.pop();
            firstNum /= secondNum;
            st.push(firstNum);
        }
        else{
            ind = c-'A';
            st.push(nums[ind]);
        }
    }

    cout<<fixed;
    cout.precision(2);

    cout<<st.top();
}