#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int mergeCount(int* A,int* B,int* C,int sb,int sc){
    int i=0,j=0,k=0;
    int res=0;
    while(i<sb&&j<sc){
        if(B[i]>C[j]){
            res+=B[i];
            i++;k++;
        }
        else{
            
            k++;j++;
        }
    }
    for(;i<sb;i++) res+=B[i];
    for(;j<sc;j++){ A[k++]=C[j]; 
       
    }
    return res;
}

int sortCount(int* A,int n){
    if(n==1) return 0;
    int m=n/2;
    int B[m];
    int C[n-m];
    int k=0;
    for(int i=0;i<m;i++) B[i]=A[k++];
    for(int i=0;i<n-m;i++) C[i]=A[k++];
    int r1=sortCount(B,m);
    int r2=sortCount(C,n-m);
    int r3=mergeCount(A,B,C,m,n-m);
    return r1+r2+r3;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int res=sortCount(arr,n);
        cout<<res<<endl;
    }   
    return 0;
}
