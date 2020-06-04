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
//honestly you could use a pair here!!
//pair<char,bool>
typedef struct point{
    char depth;
    bool iscavity;
}point;
int main(){
    int d;
    cin>>d;
    point grid[d][d];
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            cin>>grid[i][j].depth;
            if(i==0 || j==0 || i==d-1 ||j==d-1){
                grid[i][j].iscavity=false;
            }
            else{
                grid[i][j].iscavity=true;
            }
        }
    }
    cout<<"input taken... starting the algorithm\n";
    for(int i=1;i<d-1;i++){
        for(int j=1;j<d-1;j++){
            if(grid[i][j].iscavity==false) continue;
            if(grid[i][j].depth>grid[i+1][j].depth && grid[i][j].depth>grid[i-1][j].depth && grid[i][j].depth>grid[i][j-1].depth && grid[i][j].depth>grid[i][j+1].depth){
                grid[i][j].depth='X';
                grid[i][j].iscavity=true;
                grid[i+1][j].iscavity=false;
                grid[i][j+1].iscavity=false;
            }
        }
    }
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            cout<<grid[i][j].depth;
        }
        cout<<endl;
    }
    return 0;
}