/*

Created on : 2021-06-20 23:40:00
@author    : archit nitin latkar

*/

#include<iostream>
#include<bits/stdc++.h>

#define INF INT_MAX
#define LOW INT_MIN

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

/*
An XOR linked list is a more memory efficient doubly linked list. Instead of each node holding next and prev fields, it holds a field named both, which is an XOR of the next node and the previous node. Implement an XOR linked list; it has an add(element) which adds the element to the end, and a get(index) which returns the node at index.
*/
typedef struct xorlist* listptr;
typedef struct xorlist{
    int val;
    listptr both;
}xorlist;

listptr head = NULL;
listptr xornodes(listptr x1, listptr x2){
    return (listptr)((uintptr_t)(x1) ^ (uintptr_t)(x2));
}
void addElement(int val){
    listptr x = (listptr)malloc(sizeof(xorlist));
    x->val = val;
    x->both = NULL;

    if(head == NULL){
        head = x;
    }else{
        listptr y = head;
        listptr prev = NULL;
        listptr next = xornodes(NULL, y->both);
        while(next!=NULL){
            prev = y;
            y = next;
            next = xornodes(prev, y->both);
        }
        y->both = xornodes(prev, x);
        x->both = xornodes(y, NULL);
    }
    cout<<"Success\n";
}

int get(int index){
    //cout<<"Debugging get function\n";
    int i=0;
    if(head == NULL){
        //cout<<"There is no element in the list ";
        return -1;
    } 
    listptr x = head;
    listptr prev = NULL;
    listptr next = xornodes(NULL, x->both);
    //cout<<"entering while loop\n";
    while(next != NULL && i != index){
        //cout<<"At value: "<<x->val<<endl;
        prev = x;
        x = next;
        next = xornodes(x->both, prev);
        i++;
    }
    return x->val;
}

// void solve(){

// }

int main(){
    cout<<"Xor doubly linked list implementation\n";
    cout<<"1. Add elemement 2. Get element by index 3. Exit\n";
    while(true){
        cout<<"Which operation would you perform?\n";
        int op;
        cin>>op;
        switch(op){
            case 1: cout<<"Enter value you want to insert: ";
                    int val;
                    cin>>val;
                    addElement(val);
                    break;
            case 2: cout<<"Enter index: ";
                    int index;
                    cin>>index;
                    cout<<"Element at index "<<index<<" is "<<get(index)<<endl;
                    break;
            default: exit(0);
        }
    }
    return 0;
}