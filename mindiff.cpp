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

int minimumAbsoluteDifference(vector<int> arr){
    int mindif = INFINITY;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-1;i++){
        if(abs(arr[i]-arr[i+1])<mindif){
            mindif = arr[i];
        }
    }
    return mindif;

}

// int main(){
//     int n;
//     cin>>n;
//     vector<int> arr;
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     return 0;
// }