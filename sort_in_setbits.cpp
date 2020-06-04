#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
/*
Given an integer array arr. 
You have to sort the integers in the array in ascending order by the number of 
1's in their binary representation and in case of two or more integers have the
same number of 1's you have to sort them in ascending order.

Return the sorted array.
*/
typedef struct mystruct{
    int value;
    int setbits;
}mystruct;

void merge(mystruct* arr,int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    mystruct left[n1],right[n2];
    for(i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(j=0;j<n2;j++){
        right[j]=arr[m+1+j];
    }
    i=0;j=0;k=l;
    while(i<n1 && j<n2){
        if(left[i].setbits<right[j].setbits){
            arr[k]=left[i];
            i++;k++;
        }
        else if(left[i].setbits>right[j].setbits){
            arr[k]=right[j];
            j++;k++;
        }
        else{
            if(left[i].value>right[j].value){
                arr[k]=right[j];
                j++;k++;
                
            }
            else{
                arr[k]=left[i];
                i++;k++;
                
            }
        }
    }
    while(i<n1){
        arr[k]=left[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;k++;
    }
}

void mergesort(mystruct* arr,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;

        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
int main(){
    int n;
    cin>>n;
    mystruct arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].value;
        arr[i].setbits=__builtin_popcount(arr[i].value);
    }
    mergesort(arr,0,n-1);

    cout<<"i think sorting was complete\n";
    for(int i=0;i<n;i++) cout<<arr[i].value<<"  ";
    cout<<endl;
    for(int i=0;i<n;i++) cout<<arr[i].setbits<<"  ";
    cout<<endl;
    return 0;
}
/*
Method - modify mergesort
*/