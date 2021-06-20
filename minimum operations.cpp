/*

Created on : 2021-04-19 15:31:50
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

void solve(){

}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int answer = 1;
    for(int i=1; i<n; i++){
        if(arr[i] != arr[i-1]){
            answer++;
        }
    }
    cout<<answer;
    return 0;
}