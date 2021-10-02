#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of elements in array\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array in ascending order \n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int mid,t,found=0;
    cout<<"Enter element to search\n";
    cin>>t;
    int l=0;
    int u=n-1;
    while(l<=u)
    {
       mid=(l+u)/2;
       if(t>a[mid])
       l=mid+1;
       else if(t<a[mid])
       u=mid-1;
       else
       {
          found=1;
          break;
       }
    }
    if(found)
    cout<<t<<" found at index:"<<mid;
    else
    cout<<t<<" not found in array";
return 0;
}
    

