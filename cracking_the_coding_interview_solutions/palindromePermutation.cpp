#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;
bool foo(string s){
    int x=0;
    for(int i=0;i<s.length();i++){
        x=x^(int)s[i];
    }
    cout<<x<<endl;
    if(x==0) return true;
    else{
        for(int i=0;i<s.length();i++){
            if((char)x==s[i]) return true;
        }
    }
    return false;
}
int main(){
    string s;
    cin>>s;
    cout<<foo(s)<<endl;
    return 0;
}