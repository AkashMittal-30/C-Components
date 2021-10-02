/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>

using namespace std;

int linearSearchBetweenIndex(int arr[],int size_of_array, int start_index, int end_index,int target){
    for(int i=start_index;i<=end_index;i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int target,start_index,end_index;
    int size_of_array;
    cout<<"Enter size of array: ";
    cin>>size_of_array;
    
    int arr[size_of_array];
    cout<<"Enter your aray: ";
    for(int i=0;i<size_of_array;i++){
        cin>>arr[i];
    }
    cout<<"Enter target element: ";
    cin>>target;
    cout<<"Enter start index: ";
    cin>>start_index;
    cout<<"Enter end index: ";
    cin>>end_index;
    cout<<linearSearchBetweenIndex(arr,size_of_array,start_index,end_index,target);

    return 0;
}

