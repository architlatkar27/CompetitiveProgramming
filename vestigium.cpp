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
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int N;
        cin>>N;
        int k,r,c;
        int mat[N][N];
        vector<int> rows_vals[105],col_vals[105];
        
        for(int i=0;i<N;i++){
            
            for(int j=0;j<N;j++){
                cin>>mat[i][j];
                if(i==j) k+=mat[i][j];
                rows_vals[i].push_back(mat[i][j]);
                col_vals[j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            set<int> rdistinct(rows_vals[i].begin(),rows_vals[i].end());
            if(rdistinct.size()!=rows_vals[i].size()) r++;
            set<int> cdistinct(col_vals[i].begin(),col_vals[i].end());
            if(cdistinct.size!=col_vals[i].size()) c++;
            
        }
        cout<<"Case #"<<t<<": "<<k<<" "<<r<<" "<<c<<endl;
    }
    return 0;
}