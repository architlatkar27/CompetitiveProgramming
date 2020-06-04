#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

/*
given a grid of numbers and a smaller grid, check if the smaller grid exists 
within the larger
*/

int main(){
    int t;
    cin>>t;
    while(t--){
        int R,C;
        cin>>R>>C;
        int G[R][C];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin>>G[i][j];
            }
        }
        int r,c;
        cin>>r>>c;
        int P[r][c];
        for(int i=0;i<r;i++)
            for(int j=0;j<c;j++)
                cin>>P[i][j];
        
    }
    return 0;
}