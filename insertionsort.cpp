#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i]; //storing the latest unsorted number
        j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        } //locating position towards the right of unsorted number(sorted part) to see where it fits
        arr[j + 1] = key; //putting the unsorted number in the correct position in the sorted part
    }
    for (i = 0; i < n; i++){cout<<arr[i]<< " ";}
    cout<<"\n";
 
    return 0;
}
