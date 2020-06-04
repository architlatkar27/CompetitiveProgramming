/*
given 2*n maze with a set of queries so that q=(a,b) blocks the cell at (a,b)
determine if there is a path between (0,0) and (2,n)
*/
#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int main(){
    int n;
    cout<<"enter #columns ";
    cin>>n;
    bitset<100> grid[2];
    int q;
    cout<<"how many queries? ";
    cin>>q;
    //pair<int,int> query;
    string result="yes";
    for(int t=0;t<q;t++){
        
        cout<<"enter coordinates of toggle ";
        int x,y;
        cin>>x>>y;
        grid[x][y]=!grid[x][y];
        bitset<100> take_or;
        take_or=grid[1]|grid[0];
        for(int i=0;i<n-1;i++){
            if(take_or[i]&&take_or[i+1]){
                if(grid[1][i]&&grid[0][i+1] ||  grid[0][i]&&grid[1][i+1]) result="no";
                else result="yes";
            }
        }
        cout<<"result -- "<<result<<endl;
    }
    cout<<"\nend of program\n";
    return 0;
}
/*
Method :
create a 2 row bitset in which 1 represents blocked cell
take query and toggle value of corresponding cell
take a bitwise or between the 2 rows . store result as bitset
go through the result bitset if 2 1s follow each other , there might be a block
if there is atleast 1 one in corresponding columns in different rows
alternatively there might be a single 1 which maybe due to 2 1s in the same column
*/