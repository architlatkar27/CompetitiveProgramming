/*

Created on : 2021-06-24 21:28:18 
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
Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.
For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".
*/

int solve(string s, int k){
    int answer = -1;
    if(k >= s.size())
        return s.size();

    vector<int> arr(26, 0);
    int num_distinct = 0;
    for(int i=0; i<k; i++){
        arr[s[i]-'a']++;
        if(arr[s[i]-'a'] == 1) num_distinct++;
    }

    int start = 0;
    int end = k-1;
    while(end < s.size()){
        if(num_distinct <= k){
            arr[s[end+1]-'a']++;
            if(arr[s[end+1]-'a'] == 1) num_distinct++;
            end++;
        }
        else{
            int l = end-start;
            if(arr[s[start]-'a'] == 1) num_distinct--;
            arr[s[start]-'a']--;
            start++;
            if(l > answer) answer = l;
        }
    }

    return answer;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<solve(s, k)<<endl;
    return 0;
}