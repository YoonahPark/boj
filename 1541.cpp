// 잃어버린 괄호 https://www.acmicpc.net/problem/1541

#include <iostream>
#include <vector>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=0, res=0, sum=0, add=1;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='-'){
            sum+=n;
            if(add) res += sum;
            else res -= sum;
            
            sum = 0;
            n = 0;
            add = 0;
        }
        else if(s[i]=='+'){
            sum += n;
            n = 0;
        }
        else{
            n *= 10;
            n += s[i]-48;
        }
        //cout<<res<<" "<<sum<<" "<<n<<" "<<add<<"\n";
    }
    sum += n;
    if(add) res += sum;
    else res -= sum;

    cout<<res;
}