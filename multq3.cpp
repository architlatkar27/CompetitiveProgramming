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
    int val;
    int div;
};
int main(){
    int N,Q;
    cin>>N>>Q;
    int size=2*N-1;
    mystruct arr[size+1];
    int start = size+1-N;
    for(int i=start;i<=size;i++){
        arr[i].val=0;
        arr[i].div=1;
    }
    for(int i=0;i<start;i++){
        arr[i].val=
    }
    return 0;
}