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

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;

void solve(string s){
    reverse(s.begin(),s.end());
    string res="";
    for(int i=0;i<s.size();i++){
        int c;
        if('a'<s[i]){
            c = s[i]-'a'-1;
        }
        else{
            c = s[i]-'A'-1;
        }
        c+=i+2;
        res+=to_string(c);
        //cout<<res<<endl;
    }
    cout<<res<<endl;
}

int main(){
    string s;
    cin>>s;
    solve(s);
    return 0;
}