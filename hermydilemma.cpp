#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n;
    cin>>n;
    int k;
    cin>>k;
    int c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }  
    if(n<k){
        cout<<-1<<endl;
        cout<<"NO";
    }
    sort(c,c+n);
    int req=0;
    for(int i=0;i<k;i++){
        req+=(n-i);
    }
    cout<<req<<endl;
    int x,h;
    cin>>x>>h;
    if(x*h>=req) cout<<"YES";
    else cout<<"NO";
    return 0;
}
