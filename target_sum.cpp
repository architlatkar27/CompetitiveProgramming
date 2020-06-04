#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
/*
given target and an array , find #ways to write n as sum of array elements
repetition allowed
*/

using namespace std;

int main(){
    int target;
    cout<<"enter target value ";
    cin>>target;
    int n;
    cout<<"#elements?";
    cin>>n;
    cout<<"array?\n";
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int count[target+1]={0};
    count[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<n;j++){
            if(i>=arr[j]) count[i]+=count[i-arr[j]];
        }
    }
    cout<<count[target]; 

    
    return 0;
}