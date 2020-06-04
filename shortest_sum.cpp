#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
/*
given a matrix of integers
find least cost of travelling from 0,0 to m-1,n-1
*/
int minimum(int a,int b){
    return (a<b)? a:b;
}
int main(){
    int m,n;
    cout<<"dimension ? ";
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    
    int dp[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                dp[0][0]=arr[0][0];
            }
            else if(i==0 && j!=0){
                dp[i][j]=dp[i][j-1]+arr[i][j];
            }
            else if(i!=0 && j==0){
                dp[i][j]=dp[i-1][j]+arr[i][j];
            }
            else{
                dp[i][j]=minimum(dp[i-1][j],dp[i][j-1])+arr[i][j];
            }
        }
    }
    cout<<"shortest sum "<<dp[m-1][n-1]<<endl;
    return 0;
}