#include <iostream>
using namespace std;
// To search the element in sorted and rotated
// in O(logn)

int findElement(int arr[], int l , int h, int x)
{
    if(l>h)
        return -1;
    int mid= l+(h-l)/2;
    if(arr[mid]==x)
        return mid;
    if(x>arr[mid])
    {
        if(arr[h]<x)
            return findElement(arr,l,mid-1,x);
        else
            return findElement(arr,mid+1,h,x);
    }
    if(x<arr[mid])
    {
        if(arr[l]>x)
            return findElement(arr,mid+1,h,x);
        else
            return findElement(arr,l,mid-1,x);
    }
}
int main() 
{
	int arr[]={7,10,20,1,2,3,4,5};
    int n= sizeof(arr)/sizeof(int);
    cout<<findElement(arr,0,n-1,25)<<endl;
	return 0;
}
