#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int T;
    cin>>T;
    for(int t=0;t<T;t++){ 
        int n,k;
        cout<<"n  k ?\n";
        cin>>n>>k;
        cout<<"arr?\n";
        bitset<1000000> arr;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            if(c=='1') arr[i]=1;
            else arr[i]=0;
        }
        while(k>0){
            for(int i=1;i<n;i++){
                if(arr[i]==0){
                    bool temp;
                    temp=arr[i-1];
                    arr[i-1]=arr[i];
                    arr[i]=temp;
                    k--;
                    break; 
                }
            }
        }
        cout<<"result \n";
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }    
    return 0;
}
