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
        string s;
        cin>>s;
        int i,j;
        int flag1=0;
        int first;
        int n=s.length();
        // cout<<"string length--"<<n<<endl;
        for(i=0;i<s.length()-1;i++){
            if(s[i]<s[i+1]){
                flag1=1;
                first=i;
            }
        }
        
        if(flag1==0){
            cout<<"no answer\n";
            continue;
        }
        int second;
        for(j=first+1;j<s.length();j++){
            if(s[j]>s[first]) second=j;
        }
        // cout<<"first--"<<first<<" second--"<<second<<endl;
        // cout<<"swapping "<<s[first]<<" and "<<s[second]<<endl;
        char temp;
        temp=s[second];
        s[second]=s[first];
        s[first]=temp;
        // cout<<"new string after swapping--"<<s<<endl;
        // cout<<"swapped first and second indices\n";
        string s1=s.substr(0,first+1);
        // cout<<"got first substring--"<<s1<<endl;
        string s2=s.substr(first+1);
        // cout<<"got second substring--"<<s2<<endl;
        reverse(s2.begin(),s2.end());
        // cout<<"reverse of the second--"<<s2<<endl;
        string s3=s1+s2;
        // cout<<"got third substring\n";
        cout<<s3<<endl;
    }
    return 0;
}