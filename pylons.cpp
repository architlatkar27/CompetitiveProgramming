#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bitset>
#include<set>
#include<list>
using namespace std;

typedef struct mystruct{
     int x;
     int y;
 }mystruct;
int R,C;
bitset<100> grid[100];

bitset<100> visited;
void dfs(int index){
    int x,y;
    x=index/R +1;
    y=index%C +1;
    cout<<x<<" "<<y<<endl;
    visited[index]=true;
    for(int i=0;i<C;i++){
        if(grid[index][i]==0 && visited[i]==false){
            dfs(i);
        }
    }

}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){

        
        cin>>R>>C;
        if(R<=2 && C<=2){
            cout<<"Case #:"<<t<<" IMPOSSIBLE\n";
            continue;
        }
        long int min=INT64_MAX,count=0;
        long index;
        long int i,j;
        for(i=0;i<R*C;i++){
            for(j=0;j<C*R;j++){
                int xi,yi,xj,yj;
                xi=i/R;
                yi=i%C;
                xj=j/R;
                yj=j%C;   

                if((xi!=xj && yi!=yj) || !(xj==xi+1 && yj==yi+1) || !(xj==xi-1 && yj==yi-1)){
                    
                }
            }
            count=grid[i].count();
            count=C-count;
            if(count<min){
                min=count;
                index=i;
            }    
        }
        cout<<"bitset\n";
        for(int i=0;i<R*C;i++){
            for(int j=0;j<R*C;j++){
                cout<<grid[i][j];
            }
            cout<<endl;
        }
        cout<<"start dfs\n";
        dfs(index);

    }
    return 0;
}