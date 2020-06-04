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
string result(vector<tuple<int,int,int>> activities,int n){
    
    sort(activities.begin(),activities.end());
    char op[n+1];
    op[n]='\0';
    tuple<int,int,int> cam;//describe current activity of c and j
    tuple<int,int,int> jam(0,0,0);
    cam=activities[0];
    op[get<2>(cam)]='C';
    for(int i=1;i<activities.size();i++){
        if(get<1>(cam)<=get<0>(activities[i])){
            op[get<2>(activities[i])]='C';
            cam=activities[i];
        }
        else if(get<1>(jam)<=get<0>(activities[i])){
            op[get<2>(activities[i])]='J';
            jam=activities[i];
        }
        else{
            return "IMPOSSIBlE";
            break;
        }
    }
    string res(op);
    return res;
}
int main(){
    int T;
    cin>>T;
    for(int t=1;t<=T;t++){
        int n;
        cin>>n;
        vector<tuple<int,int,int>> activities;
        for(int i=0;i<n;i++){
            tuple<int,int,int> x;
            int a,b,c;
            cin>>a>>b;
            x=make_tuple(a,b,i);
            activities.push_back(x);
        }
        cout<<"Case #"<<t<<": "<<result(activities,n)<<endl;
    }
    return 0;
}