#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bitset>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n=floor((log2((t+2)/3)+1));
    cout<<"n "<<n<<endl;
    int an=1+3*pow(2,n-1);
    int offset=t-an;
    cout<<"offset "<<t-an<<endl;

    int sv=3*pow(2,n-1);
    cout<<"sv "<<sv<<endl;
    cout<<sv-offset;
    return 0;

}