#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cout<<"n   k"<<endl;
    cin>>n>>k;
    int a1[n+1],a2[n+1];
    int flag1=0,flag2=0;
    for(int i=1;i<=n;i++){
        a1[i]=k+i;a2[i]=i-k;
        if(a1[i]>n) flag1=1;
        if(a2[i]<1) flag2=1;
    }
    
    return 0;
}