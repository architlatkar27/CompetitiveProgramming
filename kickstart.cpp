#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bitset>
#include<set>
#include<list>
#include<unordered_map>
#include<iterator>
#include<string.h>

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;

ll solve(){
    ll n;
    cin>>n;
    ll arr[n];
    ll *dp;
    dp = (ll*)calloc(n+1,sizeof(ll));
    ll count=0;
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    dp[0]=0;
    for(ll i=1;i<n+1;i++){
        dp[i] = dp[i-1]+arr[i-1];
    }
    // cout<<"dp array\n";
    // for(int i=0;i<n+1;i++){
    //     cout<<dp[i]<<" ";
    // }
    //cout<<endl;
    for(ll i=0;i<n-1;i++){
        for(ll j=i+1;j<n;j++){
            ll check = dp[j]-dp[i];
            double sr = sqrt(check);
            if(sr-floor(sr) == 0){
                count++;
            }
        }
    }
    return count;
}

int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        ll res = solve();
        cout<<"Case #"<<i<<": "<<res<<endl;
    }
    return 0;
}