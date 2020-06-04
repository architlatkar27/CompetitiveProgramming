#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>
#include<list>

using namespace std;

/*
given a binary tree , convert each level into a linked list
*/

vector<list<int>> rows(100);


typedef struct tree *treeptr;
typedef struct tree{
    int value;
    treeptr left;
    treeptr right;
}tree;

treeptr createNode(int d){
    treeptr temp;
    temp=(treeptr)malloc(sizeof(tree));
    temp->value=d;
    temp->left=temp->right=NULL;
    return temp;
}

treeptr makeTree(int beg,int end,int *arr,treeptr root){

    //static int count=0;
    if(beg>end) return NULL;
    int mid=(beg+end)/2;
    root=createNode(arr[mid]);
    //count++;
    root->left=makeTree(beg,mid-1,arr,root->left);
    root->right=makeTree(mid+1,end,arr,root->right);
    
    return root;
}
void makeLists(treeptr root,int level){
    if(root==NULL){ 
        cout<<endl;
        cout<<"encountered NULL , returning\n";
        return;
    }
    cout<<endl;
    cout<<"trying\n";
    rows[level].emplace_back(root->value);
    cout<<"value "<<root->value<<" added to list at level "<<level<<endl;
    cout<<"calling for left\n";
    makeLists(root->left,level+1);
    cout<<"left successfull , calling for right\n";
    makeLists(root->right,level+1);
    cout<<"function call successfull\n";
    
}
int main(){

    int n;
    cout<<"size of array?\n";
    cin>>n;
    int arr[n];
    cout<<"enter array elements\n";
    for(int i=0;i<n;i++) cin>>arr[i];
    
    treeptr root;
    root=makeTree(0,n-1,arr,root);
    cout<<"tree was made successfully\n";
    makeLists(root,0);
    cout<<endl;
    list<int>::iterator i;
    i=rows[0].begin();
    while(i!=rows[0].end()){
        cout<<*i<<"  ";
        i++;
    }
    cout<<endl;
    i=rows[1].begin();
    while(i!=rows[1].end()){
        cout<<*i<<"  ";
        i++;
    }
    cout<<endl;
    i=rows[2].begin();
    while(i!=rows[2].end()){
        cout<<*i<<"  ";
        i++;
    }
    cout<<endl;
    return 0;
}