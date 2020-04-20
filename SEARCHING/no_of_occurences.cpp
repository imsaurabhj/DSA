#include <iostream>
// count number of occurences of given element
// using binary search method
// solution in O(logn)
// IDEA: is to find the index of left_most element and index of right most element and subtract them;
using namespace std;
int left_most_index(int arr[], int l, int h, int x)
{
    if(l>h)
        return -1;
    int mid=l+(h-l)/2;
    if(arr[mid]==x && (mid==0 || arr[mid-1]!=x))
        return mid;
    if(arr[mid]==x && arr[mid-1]==x)
        return left_most_index(arr,l,mid-1,x);
    else if(x<arr[mid])
        return left_most_index(arr,l,mid-1,x);
    if(x>arr[mid])
        return left_most_index(arr,mid+1,h,x);
}
int right_most_index(int arr[], int l, int h, int x)
{
    if(l>h)
        return -1;
    int mid =l+(h-l)/2;
    if(arr[mid]==x && (mid==0 || arr[mid+1]!=x) )
        return mid;
    if(arr[mid]==x && arr[mid+1]==x)
        return right_most_index(arr,mid+1,h,x);
    if(x<arr[mid])
        return right_most_index(arr,l,mid-1,x);
    if(x>arr[mid])
        return right_most_index(arr,mid+1,h,x);
}
int count_occurence(int arr[],int n, int x)
{
    return -left_most_index(arr,0,n-1,x)+right_most_index(arr,0,n-1,x) + 1;
}
int main() 
{  	int arr[]={2,2,2,2,3,3,3,4,5};
    int n= sizeof(arr)/sizeof(int);
    cout<<count_occurence(arr,n,5)<<endl;
	return 0;
}
