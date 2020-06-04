#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int main(){
    bitset<30> x[100];
    int n;
    cout<<"enter number of people ";
    cin>>n;
    cout<<"enter schedule for each person "<<endl;
    int days;
    for(int i=0;i<n;i++){
        cout<<"schedule of person "<<i<<endl;
        cout<<"how many days?"<<endl;
        cin>>days;
        int d;
        for(int j=0;j<days;j++){
            cout<<"enter next day ";
            cin>>d;
            x[i][d]=1;
        }
    }
    int max_int=-1;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int intersec=(x[i]&x[j]).count();
            if(intersec>max_int) max_int=intersec;
        }
    }
    cout<<"best intersection "<<max_int<<endl;
    return 0;
}