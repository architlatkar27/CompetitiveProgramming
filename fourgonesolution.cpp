#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int i=1;i<=T;i++){
        int n;
        cin>>n;
        int temp=n;
        int a=0;
        int b=n;
        int pv=1;
        while(temp){
            int d=temp%10;
            if(d==4){
                a=a+pv;
                b=b-pv;
            }
            pv=pv*10;
            temp/=10;
        }
        cout<<"Case #"<<i<<": "<<a<<" "<<b<<endl;
    }
    return 0;
}