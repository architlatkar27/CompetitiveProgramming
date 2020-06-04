#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    long long int k=pow(10,9)+7;
    long long int l=s.length();
    long long int sum=0;
    long long int num=0;
    for(int i=0;i<l;i++){
        num=0;
        for(int j=i;j<l;j++){
            num=num*10%k+(int)(s[j])%k-(int)('0')%k;
            sum+=num;
        }
    }
    sum=sum%k;
    cout<<sum<<endl;
    // cout<<s[0]<<"  "<<(int)(s[0])<<endl;
    return 0;
}