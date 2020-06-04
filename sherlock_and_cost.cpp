#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
/*
given array b[] create an array a[] such that for every i , a[i]<=b[i] and
sum(|a[i]-a[i-1]|) is maximum
*/
int maximum(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int b[n],a[n],s1,s2;
        for(int i=0;i<n;i++){
            cin>>b[i];a[i]=0;
        } 
        s1=0;s2=0;
        int maxi=0,max1=0,newmaxi,newmax1;
        for(int i=1;i<n;i++){
            newmaxi=maximum(maxi+abs(b[i]-b[i-1]),max1+abs(b[i]-1));
            newmax1=maximum(maxi+abs(1-b[i-1]),max1);
            maxi=newmaxi;
            max1=newmax1;
        }
        cout<<maximum(maxi,max1)<<endl;
    }
    return 0;
}
/*
Method :
at every step we need to either attach b[i] or 1 to a
maxi is the sum if you appended b[i] while max1 is the sum if you appended 1
initialize maxi and max1 to 0 and begin iteration from i=1
newmaxi is the max sum possible at ith iteration if we append b[i] (same for newmax1)
at this stage we have maxi , max1 from previous iteration and in previous iteration , 
we added b[i-1] to get maxi
once we put b[i] at end of both lists , check cost of adding and add it to respective sums
take maximum
in the end take maximum out of maxi and max1

*/