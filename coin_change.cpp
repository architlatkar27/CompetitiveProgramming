#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

/*
given denominations of coins and target amount N what is minimum possible number
of coins used
*/

int main(){
    int target;
    cout<<"target  ";
    cin>>target;
    int n;
    cout<<"size  ";
    cin>>n;
    int coins[n];
    cout<<"coins?\n";
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    int dp[target+1]={0};
    dp[0]=0;
    for(int i=1;i<target+1;i++){
        for(int j=0;j<n;j++){
            if(i-coins[j]>=0)
                if(i==coins[j]) dp[i]=1;
                else if(dp[i]==0) dp[i]=1+dp[i-coins[j]]; 
                else dp[i]=(dp[i]>dp[i-coins[j]])? dp[i-coins[j]]+1:dp[i];
        }
    }
    cout<<"minimum #coins = "<<dp[target]<<endl;
    return 0;
}
/*
Method:
#coins for 0 = 0
when you have to find #coins for i-
1. if i belongs to the same denomination , then it needs only 1 coin
2. if i has not been approached yet , its value would be 0 hence assign it as
1+dp[i-coins[j]] --> you need 1 more coin than minimum number coins for i-coins[j]
3. else check minimum of current value of dp and 1+dp[i-coins[j]]
*/