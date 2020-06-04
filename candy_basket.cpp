#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n]={0};
    for(int i=0;i<m;i++){
        int a,b;
        int k;
        cin>>a>>b>>k;
        for(int i=a;i<=b;i++){
            arr[i]=arr[i]+k;
        }
    }
    //auto it=max_element(arr.begin(),arr.end());
    int max=arr[0];
    for(int i=0;i<n;i++){
        if(max<arr[i]) max=arr[i];
    }
    cout<<max;
    return 0;
}