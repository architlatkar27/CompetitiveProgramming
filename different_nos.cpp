#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
int main(){
    bitset<10000> arr;
    cout<<"enter 10 numbers less than 10000\n";
    for(int i=0;i<10;i++){
        int num;
        cin>>num;
        arr[num]=1;
    }
    int different=arr.count();
    cout<<"#distint numbers "<<different<<endl;
    return 0;
}