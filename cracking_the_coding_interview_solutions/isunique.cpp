#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
/*
given a string check if all characters are unique
*/
using namespace std;
bool isunique(string s){
    int hash[26]={0};
    for(int i=0;i<s.length();i++){
        int d=(int)(s[i]-'a');
        if(hash[d]==1) return false;
        hash[d]+=1;
    }
    return true;
}
int main(){
    string s;
    cin>>s;
    cout<<isunique(s)<<endl;
    return 0;
}