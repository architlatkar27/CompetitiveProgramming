#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"n? ";
    cin>>n;
    bitset<10000> a,b,c;
    cout<<"arr?\n";
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        if(num<0){
            a[i]=0;
        }
        else a[i]=1;
    }
    b[n-1]=1;
    int prev_min=0;
    for(int i=0;i<n;i++){
        if(a[i]!=b[i]) prev_min++; 
    }
    for(int j=n-2;j>0;j--){
        b[j]=1;
        int curr_val=0;
        c=a^b;
        curr_val=c.count();
        if(curr_val<prev_min) prev_min=curr_val;
    }
    // cout<<"test "<<count<<endl;
    cout<<"result "<<prev_min<<endl;
    return 0;
}