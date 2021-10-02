//program to sort an array of integers using bubble sort method
#include<bits/stdc++.h>
using namespace std;
//function to swap adjacent elements
void swapele(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
//function to sort the array
void bubblesort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        //pass wise sorting
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                {swapele(&arr[j],&arr[j+1]);}
        }
    }
    cout<<"Sorted array: \n";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
}
//driver code
int main(){
    int n;
    cout<<"Enter number of elements in array: "<<endl; //size of array
    cin>>n;
    cout<<"Enter array elements: \n";
    int arr[n];
    for(int i=0;i<n;i++){   //takes array input
        cin>>arr[i];
    }
    bubblesort(arr,n); //sorted array   
    return 0;
}
