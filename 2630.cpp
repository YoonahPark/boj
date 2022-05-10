// 색종이 https://www.acmicpc.net/problem/2630

#include <iostream>
#include <vector>
using namespace std;

vector<vector <int>> paper;
int cnt_1, cnt_0;

int count_paper(int size, int I, int J){
    int n=paper[I][J];
    for(int i=I; i<I+size; i++){
        for(int j=J; j<J+size; j++){
            if(paper[i][j]!=n){
                size /= 2;
                count_paper(size, I, J);
                count_paper(size, I, J+size);
                count_paper(size, I+size, J);
                count_paper(size, I+size, J+size);
                return 0;
            }
        }
    }
    switch(n){
        case 1: ++cnt_1; break;
        case 0: ++cnt_0; break;
    }
    return 0;
}

int main(){
    int N, n;
    cin>>N;
    vector<int> line(N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>line[j];
        }
        paper.push_back(line);
    }

    count_paper(N, 0, 0);

    cout<<cnt_0<<"\n";
    cout<<cnt_1<<"\n";
}