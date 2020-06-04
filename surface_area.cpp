#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
    int h,w;
    cout<<"enter h, w"<<endl;
    cin>>h>>w;
    int a[h][w];
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>a[i][j];
    int sa=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]>0) sa+=2;
            if(i==0) sa+=a[i][j];
            if(i==h-1) sa+=a[i][j];
            if(j==0) sa+=a[i][j];
            if(j==w-1) sa+=a[i][j];
            if(i!=0 && a[i][j]>a[i-1][j]) sa+=(a[i][j]-a[i-1][j]);
            if(i!=h-1 && a[i][j]>a[i+1][j]) sa+=(a[i][j]-a[i+1][j]);
            if(j!=0 && a[i][j]>a[i][j-1]) sa+=(a[i][j]-a[i][j-1]);
            if(j!=w-1 && a[i][j]>a[i][j+1]) sa+=(a[i][j]-a[i][j+1]);
        }
    }
    cout<<"surface area "<<sa<<endl;
    return 0;
} 