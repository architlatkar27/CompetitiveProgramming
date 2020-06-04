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
    vector<pair<int,int>> intervals;
    int n,q;
    cin>>n>>q;
    int start,finish;
    int* count;
    count=(int*)calloc(sizeof(int),n+1);
    // cout<<"count array\n";
    // for(int i=0;i<n+1;i++){
    //     cout<<count[i]<<" ";
    // }
    //cout<<endl;
    for(int i=0;i<q;i++){
        cin>>start>>finish;
        pair<int,int> ip(start,finish);
        for(int j=start;j<=finish;j++){
            count[j]++;
        }
        intervals.push_back(ip);
    }
    cout<<"count array\n";
    for(int i=0;i<n+1;i++){
        cout<<count[i]<<" ";
    }
    cout<<endl;
    sort(intervals.begin(),intervals.end());
    int max_painted=0;
    int* ones;
    ones=(int*)calloc(sizeof(int),n+1);
    for(int i=0;i<q;i++){
        int nonzeroes=0;
        for(int j=intervals[i].first;j<=intervals[i].second;++j){ 
            count[j]--;
            if(count[j]>0) nonzeroes++;
            if(count[j]==1) ones[j]+=1;
        }
        for(int j=2;j<=n;j++){
            ones[i]+=ones[i-1];
        }
        for(int j=i+1;j<q;j++){
            int lostones = ones[intervals[j].second]-(intervals[j].first? ones[intervals[j].first-1]:0);
            max_painted=max(max_painted,nonzeroes-lostones);
        }
        for(int j=intervals[i].first;j<=intervals[i].second;++j) count[j]++;
    }
    cout<<max_painted<<endl;
    return 0;
}