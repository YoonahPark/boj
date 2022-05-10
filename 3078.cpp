// 좋은 친구 https://www.acmicpc.net/problem/3078

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int nameLength;
long long N, K, res;
string studentName;
deque<int> students;
vector<int> window(21);


int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin>>N>>K;
    
    for(int i=0; i<N; i++){
        cin>>studentName;
        nameLength = studentName.size();

        res += window[nameLength];

        if(students.size()==K){
            --window[students.front()];
            students.pop_front();
        }

        students.push_back(nameLength);
        ++window[nameLength];
    }

    cout<<res;
}