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
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int numbers[n];
    int* remCount;
    remCount=(int*)calloc(sizeof(int),k);
    for(int i=0;i<n;i++){
        cin>>numbers[i];
        remCount[numbers[i]%k]++;
    }
    int maxlength=0;
    for(int i=1;i<=k/2;i++){
        if(i==k-i){
            maxlength++;
            continue;
        };
        int v =max(remCount[i],remCount[k-i]);
        maxlength+=v;
    }
    if(remCount[0]!=0) maxlength++;
    cout<<maxlength;
    return 0;
}