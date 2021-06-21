/*

Created on : 2021-06-20 23:11:15
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
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
You can assume that the messages are decodable. For example, '001' is not allowed.
*/

int solve(string s){
    int answer;
    int s1 = stoi(s);
    if(s1 < 10){
        return 1;
    }
    if(s1 < 27){
        return 2;
    }
    answer += solve(s.substr(1));
    if(stoi(s.substr(0,2)) <= 26) answer += solve(s.substr(2));
    return answer;
}

int main(){
    string input;
    cin>>input;
    int answer = solve(input);
    cout<<answer<<endl;
    return 0;
}