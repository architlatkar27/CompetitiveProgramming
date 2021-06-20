#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
int** dp;
set<int> hcfs;
void init(vector<int>& arr, int n){
    dp = (int**)calloc(n, sizeof(int*));
    for(int i=0; i<n; i++){
        dp[i] = (int*)calloc(n, sizeof(int));
    }
    for(int j=0; j<n; j++){
        dp[j][j] = arr[j];
        hcfs.insert(arr[j]);
        //cout<<dp[j][j]<<endl;
    }
}
int gcd(int a, int b){
    //cout<<"gcd of "<<a<<" and "<<b<<endl;
    int r = a%b;
    while(r != 0){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int solve(vector<int>& arr, int n){
    init(arr, n);
    cout<<"init done\n";
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            dp[i][j] = gcd(dp[i][j-1], arr[j]);
            hcfs.insert(dp[i][j]);
        }
    }
    return hcfs.size();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>> n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int x; cin>> x;
        arr.push_back(x);
    }
    cout<<solve(arr, n)<<endl;
    return 0;
}
