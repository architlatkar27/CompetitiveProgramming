#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findx(int n){
    int g=3;
    int t=3;
    while(t<n){
        g+=4;
        t=t+g;
    }
    t-=g;
    int offset=n-t;
    int size=g;
    int x;
    int middle=(size+1)/2;
    if(offset<=middle) x=offset;
    else x=2*middle-offset;
    return x;
}
int findy(int n){
    int g=1;
    int t=1;
    while(t<n){
        g+=4;
        t=t+g;
    }
    t-=g;
    int offset=n-t;
    int size=g;
    int y;
    int middle=(size+1)/2;
    if(offset<=middle) y=offset;
    else y=2*middle-offset;
    return y;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>>n;
        int x=findx(n);
        int y=findy(n);
        cout<<"("<<x<<","<<y<<")\n";
    } 
    return 0;
}
