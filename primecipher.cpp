#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bitset>
#include<set>
using namespace std;

long int factorize(int n1){
    long int i=3;
    while(true){
        if(n1%i==0) return i;
        i+=2;
    }
    
}
int main(){
    long int T;
    cin>>T;
    for(long int t=1;t<=T;t++){
        long int N;
        cin>>N;
        long int L;
        cin>>L;
        long int arr[L];
        for(long int i=0;i<L;i++){
            cin>>arr[i];
        }
        long int first,second;
        first = factorize(arr[0]);
        second = arr[0]/first;
        //long int temp;
        int primes[L+1];
        set<long int> temp;
        temp.insert(first);
        temp.insert(second);
        if(arr[1]%second==0){
            primes[0]=first;
            primes[1]=second;
        }
        else{
            primes[0]=second;
            primes[1]=first;
        }
        long int min=(first>second)? second:first;
        for(int i=2;i<L;i++){
            primes[i]=arr[i-1]/primes[i-1];
            temp.insert(primes[i]);
        }
        primes[L]=arr[L-1]/primes[L-1];
        temp.insert(primes[L]);
        vector<int> alphabet(temp.begin(),temp.end());
        char message[L+1];
        sort(alphabet.begin(),alphabet.end());
        for(int i=0;i<26;i++){
            for(int j=0;j<L+1;j++){
                if(alphabet[i]==primes[j]) message[j]=(char)(i+65);
            }
        }
        for(int i=0;i<L+1;i++) cout<<message[i];
        cout<<endl;

    }
    return 0;
}