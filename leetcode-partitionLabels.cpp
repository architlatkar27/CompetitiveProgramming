#include<bits/stdc++.h>
/*
    A string S of lowercase English letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
    
*/
class Solution {
public:
    map<char,char> parent_id;
    int n_components;
    map<char, pair<int,int>> range;
    map<char, int> range_size;
    
    char find(char x){
        char root = x;
        while(root != parent_id[root]) root = parent_id[root];
        while(x != root){
            char parent = parent_id[x];
            parent_id[x] = root;
            x = parent;
        }
        return root;
    }
    void unite(char x, char y){
        char p1 = find(x);
        char p2 = find(y);
        if(p1 == p2) return ;
        else if(range_size[p1] > range_size[p2]){
            parent_id[p2] = p1;
            range[p1].first = (range[p1].first < range[p2].first)? range[p1].first: range[p2].first;
            range[p1].second = (range[p1].second > range[p2].second)? range[p1].second: range[p2].second;
            range_size[p1] = range[p1].second - range[p1].first+1;
        }
        else{
            parent_id[p1] = p2;
            range[p2].first = (range[p2].first < range[p1].first)? range[p2].first: range[p1].first;
            range[p2].second = (range[p2].second > range[p1].second)? range[p2].second: range[p1].second;
            range_size[p2] = range[p2].second - range[p2].first+1;
        }
        cout<<"uniting -- "<<p1<<","<<p2<<endl;
        
        n_components--;
    }
    
    vector<int> partitionLabels(string S) {
        
        for(int i=0;i<S.size();i++){
            if(range.find(S[i]) == range.end()){
                range[S[i]] = make_pair(i,i);
                range_size[S[i]] = 1;
            }
            else{
                range[S[i]].second = i;
                range_size[S[i]] = i-range[S[i]].first+1;
            }
            parent_id[S[i]] = S[i];
        }
        
        n_components = S.size();
        for(auto i = parent_id.begin(); i!=parent_id.end(); i++){
            for(auto j = i; j!=parent_id.end(); j++){
                if(range[i->first].second > range[j->first].first) unite(i->first, j->first);
            }
        }
        vector<int> answer;
        for(auto i:parent_id){
            if(i.first == i.second) answer.push_back(range_size[i.first]);
        }
        return answer;
        
    }
};