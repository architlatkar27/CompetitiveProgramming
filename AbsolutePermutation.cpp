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
    while(T--){
        int n,k;
        cin>>n>>k;
        if(k==0){
            for(int i=1;i<=n;i++) cout<<i<<" ";
            cout<<endl;
            continue;
        }
        if(n%(2*k)!=0){
            cout<<-1<<endl;
            continue;
        }
        int temp=k;
        for(int i=1;i<=n;i++){
            cout<<i+temp<<" ";
            if(i%k==0) temp*=-1;
        }
        cout<<endl;
    }
    return 0;
}