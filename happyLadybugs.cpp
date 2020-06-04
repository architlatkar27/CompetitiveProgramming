#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
bool check0(char* str,int n,int* hash){
    bool f1 = (hash[26]==0);
    if(f1==false) return false;
    bool f2 = false;
    if(str[0]!=str[1]) return false;
    if(str[n-1]!=str[n-2]) return false;
    for(int i=1;i<n-1;i++){
        if(str[i]!=str[i-1] && str[i]!=str[i+1])
            return false;
    }
    return true;
}
bool check1(char* str,int n,int* hash){
    bool f1 = hash[26]!=0;
    bool f2 = true;
    for(int i=0;i<26;i++){
        if(hash[i]==1){
            f2=false;
            break;
        }
    }
    return f1&&f2;
}
int main(){
    int g;
    cin>>g;
    while(g--){
        int hash[27]={0};
        int n;
        cin>>n;
        char str[n];
        for(int i=0;i<n;i++){
            cin>>str[i];
            if(str[i]=='_') hash[26]++;
            else hash[str[i]-'A']++;
        }
        //cout<<"hash values\n";
        //for(int i=0;i<27;i++) cout<<hash[i]<<" ";
        cout<<endl;
        if(check0(str,n,hash)){
            //if no underscore and happy string
            cout<<"YES\n";
            
        }
        else if(check1(str,n,hash)){
            //1 or more underscore and no element occurs once
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}