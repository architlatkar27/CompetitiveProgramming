#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bitset>
#include<set>
#include<list>
#include<unordered_map>
#include<iterator>
#include<string.h>
using namespace std;
int compare(int x,int y){
    int r=(x>y)? 1:(x==y)? 0:-1;
    return r;
}
string result(string input){
    string output;
    int x=input[0]-'0';
    while(x--){
        output="("+output;
    }
    output=output+input[0];
    for(int i=1;i<input.size();i++){
        int x=input[i-1]-'0';
        int y=input[i]-'0';
        string s1,s2;
        switch(compare(x,y)){
            case 0: output=output+input[i];
                    break;
            case 1: s1=string(x,')');s2=string(y,'(');
                    output=output+s1+s2+input[i];
                    break;
            case -1:s1=string(y-x,'(');
                    output=output+s1+input[i];
                    break;
            default: break;

        }
    }
    int last=input[input.size()-1]-'0';
    output=output+string(last,')');
    return output;
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        string s;
        cin>>s;
        cout<<"Case #"<<t<<": "<<result(s)<<endl;
    }
    return 0;
}