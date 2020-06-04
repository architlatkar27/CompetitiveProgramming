#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
using namespace std;
int main(){
    set <int> scores;
    set <int> alice;
    scores.insert(100);
    scores.insert(100);
    scores.insert(90);
    scores.insert(90);
    scores.insert(80);
    scores.insert(70);
    scores.insert(50);
    scores.insert(40);
    scores.insert(40);
    alice.insert(100);
    alice.insert(30);
    alice.insert(75);
    set <int>::iterator itr;
    for(itr=scores.begin();itr!=scores.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
    for(itr=alice.begin();itr!=alice.end();itr++){
        cout<<*itr<<" ";
    }
    cout<<endl;
    
    
    cout<<"printing subsequent ranks of alice\n";
    for(itr=alice.begin();itr!=alice.end();itr++){
        auto rank=scores.upper_bound(*itr);
        int r=distance(scores.begin(),rank);
        cout<<6-r+1<<"  ";
    }
    return 0;
}
