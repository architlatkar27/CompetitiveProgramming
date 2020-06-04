#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bitset>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int t=0;t<T;t++){
        int n;
        cin>>n;
        bitset<1000> path;
        for(int i=0;i<2*n-2;i++){
            char c;
            cin>>c;
            if(c=='S') path[i]=1;
        }
        path=path.flip();
        cout<<"Case #"<<t+1<<": ";
        for(int i=0;i<2*n-2;i++){
            if(path[i]==1) cout<<"S";
            else cout<<"E";
        }
        cout<<endl;
    }
    return 0;
}