/*

Created on : 2021-06-21 22:20:47
@author    : archit nitin latkar

*/

#include<iostream>
#include<bits/stdc++.h>

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/*
Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.
For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.
Follow-up: Can you do this in O(N) time and constant space?
*/
vector<int> dp;

int max(int a, int b){
    return (a>b)? a: b;
}

int solve(vector<int>& input){
    int n = input.size();
    for(int i=2; i<n; i++){
        dp[i] = max(input[i]+dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> input(n);
    dp.resize(n);
    for(int i=0; i<n; i++){
        cin>>input[i];
    }
    dp[0] = input[0];
    if(n>1){
        dp[1] = max(dp[0], input[1]);
    }
    cout<<solve(input)<<endl;
    return 0;
}