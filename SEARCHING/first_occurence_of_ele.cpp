#include <iostream>
// To find the index of first occurence of given element
using namespace std;
int binarySearch(int arr[], int l, int r, int x )
{
    if(l>r)
        return -1;
    int mid=l+(r-l)/2;
    if(arr[mid]==x && (mid==0 || arr[mid-1]!=x))
        return mid;
    if(arr[mid]==x && arr[mid-1]==x)
        return binarySearch(arr,l,mid-1,x);
    else if(x<arr[mid])
        return binarySearch(arr,l,mid-1,x);
    else
        return binarySearch(arr,mid+1,r,x);
}
int main() 
{   int arr[]={2,2,2,2,3,3,3,4,5};
    int n= sizeof(arr)/sizeof(int);
    cout<<binarySearch(arr,0,n-1,2)<<endl;
	return 0;
}
