#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
/*
given m types of coins find the #combinations to make n 
*/
int main(){
    int n,m;
    cin>>n>>m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin>>arr[i];
    }
    int dp[n+1]={0};
    //memset(dp,0,n+1);
    dp[0]=1;
    for(int i=0;i<m;i++){
        for(int j=arr[i];j<=n;j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
/*
Method:
initialize dp[] to 0 , #combinations for 0 coins is one
to make amount j , add #combinations of j-coin[i] 
*/