#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;
bool checkPermutation(string s1,string s2){
    bitset<26> hash1,hash2;
    //if(s1.length()!=s2.length()) return false;
    for(int i=0;i<s1.length() || i<s2.length();i++){
        int d1=(int)(s1[i]-'a');
        int d2=(int)(s2[i]-'a');
        if(hash1[d1]==0) hash1[d1]=1;
        if(hash2[d2]==0) hash2[d2]=1;
    }
    cout<<hash1<<endl;
    cout<<hash2<<endl;
    if(hash1==hash2) return true;
    return false;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    cout<<checkPermutation(s1,s2)<<endl;
    return 0;
}