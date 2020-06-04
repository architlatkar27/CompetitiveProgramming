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
    int r,c,n;
    cin>>r>>c>>n;
    char grid0[r][c],grid1[r][c];
    char grid2[r][c],grid3[r][c];
    //set initial grid and the grid for 1st and 2nd second
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid0[i][j];
            grid1[i][j]=grid0[i][j];
            grid2[i][j]='O';
        }
    }
    char grid5[r][c];
    //setup grid for 3rd second and 5th second
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            //check if the grid is a bomb in grid0, if yes blow it and it's neighbours
            if(grid1[i][j]=='O'){
                grid3[i][j]='.';
               if(i+1<r) grid3[i+1][j]='.';
               if(i-1>=0) grid3[i-1][j]='.';
               if(j+1<c) grid3[i][j+1]='.';
               if(j-1>=0) grid3[i][j-1]='.';
            }
            else{
                grid3[i][j]='O';
            }
            if(grid2[i][j]=='O'){
                grid5[i][j]='.';
               if(i+1<r) grid5[i+1][j]='.';
               if(i-1>=0) grid5[i-1][j]='.';
               if(j+1<c) grid5[i][j+1]='.';
               if(j-1>=0) grid5[i][j-1]='.';
            }
            else{
                grid5[i][j]='O';
            }
        }
    }

    if(n%2==0){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<grid2[i][j];
            }
            cout<<endl;
        }
    }
    else if((n-3)%4==0){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<grid3[i][j];
            }
            cout<<endl;
        }
    }
    else{
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<grid5[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}