#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
Given an array of numbers you can add either 1,2 or 5 to all numbers except one.
Find out minimum number of such operations are needed to make all numbers equal.
*/

 int main(){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        int arr[n];
        int op[5]={0};
        int min=10000;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(min>arr[i]) min=arr[i];
        }
        int diff;
        for(int i=0;i<n;i++){
            diff=arr[i]-min;
            op[0]+=diff/5;
            diff%=5;
            op[0]+=diff/2;
            diff%=2;
            op[0]+=diff/1;

            diff=arr[i]-min+1;
            op[1]+=diff/5;
            diff%=5;
            op[1]+=diff/2;
            diff%=2;
            op[1]+=diff/1;

            diff=arr[i]-min+2;
            op[2]+=diff/5;
            diff%=5;
            op[2]+=diff/2;
            diff%=2;
            op[2]+=diff/1;

            diff=arr[i]-min+3;
            op[3]+=diff/5;
            diff%=5;
            op[3]+=diff/2;
            diff%=2;
            op[3]+=diff/1;

            diff=arr[i]-min+4;
            op[4]+=diff/5;
            diff%=5;
            op[4]+=diff/2;
            diff%=2;
            op[4]+=diff/1;
        }
        int res=op[0];
        for(int i=1;i<5;i++) if(op[i]<res) res=op[i];
        cout<<res<<endl;
     }
     return 0;
 }
 /*
Method - 
adding 1 to every number except one is as good as decrementing 1 from that number 
which was left out . so the problem becomes decrement 1 or 2 or 5 from any one number 
at each stage

now we would like to bring all numbers to the same as the minimum number in the 
input array . 

Now given a number , we can bring it down to the minimum by subtracting 1,2,5
The minimum #steps required to do this would be to first subtract 5 as much as we can
then subtract 2 as much as we can , then subtract 1 finally.

to do this we take the difference between minimum and arr[i] and first divide by 5
add it to op , the take remainder divide it by 2 add to op , then divide by 1

however , there might be cases where we would get lesser steps by first adding 1 or 2
so repeat this activity for arr[i]+1 and arr[i]+2
 */