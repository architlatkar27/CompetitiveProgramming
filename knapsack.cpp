#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
    set<int> arr;
    int n;
    cout<<"how many numbers? ";
    cin>>n;
    cout<<"enter set elements\n";
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        arr.insert(num);
    }
    arr.insert(0);
    bitset<100000> bitarr;
    set<int>::iterator i1,i2;
    bitarr[0]=1;
    
    int tracker=0;
    for(i1=arr.begin();i1!=arr.end();i1++){
        bitarr=bitarr|bitarr<<(*i1);
    }
    
    int target;
    cout<<"enter target ";
    cin>>target;
    if(bitarr[target]==1) cout<<"YES\n";
    else cout<<"NO\n";
    cout<<"set elements\n";
    for(i1=arr.begin();i1!=arr.end();i1++) cout<<*i1<<"  ";
    cout<<endl;
    cout<<"bitset elements\n";
    for(int i=0;i<25;i++) cout<<bitarr[i]<<"  ";
    cout<<endl;
    return 0;

}