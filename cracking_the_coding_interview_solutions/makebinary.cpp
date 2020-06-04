#include<stdio.h>
#include<algorithm>
#include<bits/stdc++.h>
#include<iostream>
#include<vector>

using namespace std;

/*
given a sorted array , make it into a binary tree of least height
*/

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
void preorder(treeptr root){

    if(root==NULL) return ;
    cout<<root->value<<"  ";
    preorder(root->left);
    preorder(root->right);

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
    preorder(root);
    cout<<endl;
    return 0;
}