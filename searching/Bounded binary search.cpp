#include <iostream>
using namespace std;
int found(int a[],int t, int l, int u)
{
    int mid;
    while(l<=u)
    {
       mid=(l+u)/2;
       if(t>a[mid])
       l=mid+1;
       else if(t<a[mid])
       u=mid-1;
       else
       {
          return mid;
       }
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Enter number of elements in array\n";
    cin>>n;
    int a[n];
    cout<<"Enter elements of array in ascending order \n";
    for(int i=0;i<n;i++)
    cin>>a[i];
    int t,l,u;
    cout<<"Enter element to search\n";
    cin>>t;
    cout<<"Enter indices to search between\n";
    cin>>l>>u;
    int pos=found(a,t,l,u);
    if(pos!=-1)
    cout<<t<<" found at index:"<<pos;
    else
    cout<<t<<" not found in range";
return 0;
}
