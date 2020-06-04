#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    int pages=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        float x = arr[i]/(float)k;
        pages+=ceil(x);
    }
    //cout<<pages<<endl;
    int count=0,j=0;
    int prev_page;
    count++;
    pair<int,int> range;
    range.first=1;
    range.second=k;
    prev_page=k;
    for(int i=2;i<=pages;i++){
        range.first=prev_page+1;
        range.second=range.first+k-1;
        if(i<=range.second && i>=range.first) count++;
    }
    return 0;
}