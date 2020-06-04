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

vector<int> stones(int n,int a,int b){
    set<int> final_values;
    
    for(int i=1;i<=n;i++){
        int val=a*(n-i)+(i-1)*b;
        final_values.insert(val);
    }
    vector<int> result(final_values.begin(),final_values.end());
    sort(result.begin(),result.end());
    return result;
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n,a,b;
        cin>>n>>a>>b;
        stones(n,a,b);
    }
    return 0;
}