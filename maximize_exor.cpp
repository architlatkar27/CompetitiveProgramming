#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int maximize_xor(int l,int r){
    return (1 << int(log2(l ^ r) + 1)) - 1;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int queries;
    cin>>queries;
    for(int q=0;q<queries;q++){
        int x,l,r;
        cin>>x>>l>>r;
        int max;
        if(x<l){
             max=maximize_xor(x,l);
        }
        else if(x>l && x<r){
            cout<<"l x r\n";
            int max1=maximize_xor(l,x);
            int max2=maximize_xor(x,r);
            max= (max1>max2)? max1:max2;
        }
        else {
            max=maximize_xor(r,x);
        }
        cout<<"towrds res\n";
        int result=max;
        cout<<result<<endl;
    }
    return 0;
}
