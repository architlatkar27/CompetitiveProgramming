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

ll countInversions(int* arr,int l,int m,int r){
    int n1 = m-l+1;
    int n2 = r-m;
    int inv = 0;
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i] = arr[i];
    }
    for(int j=0;j<n2;j++){
        right[j] = arr[m+1+j];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;k++;
        }
        else if(left[i] > right[j]){
            arr[k] = right[j];
            inv+=n1-i;
        }
    }
    
}
ll divide(int* arr,ll l,ll r){
    if(l<r){
        int m = l + (r-l)/2;

        int r1 = divide(arr,m+1,r);
        int r2 = divide(arr,l,m);
        int r3 = countInversions(arr,l,m,r);
        return r3;
    }
    return 0;
}
void solve(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll res = countInversions(arr);
}

int main(){
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}