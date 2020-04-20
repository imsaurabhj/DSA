#include <iostream>
using namespace std;
//Median of two sorted array by merging two array
// time: O(n)  space: O(n)

int main() {
	int arr[]={1,2,3,7,13,17};
	int brr[]={4,5,10,12};
	int n1=sizeof(arr)/sizeof(int);
	int n2=sizeof(brr)/sizeof(int);
	int i=0,j=0,k=0;
	int crr[n1+n2];
	while(i<n1 && j<n2)
	{
	    if(arr[i]<=brr[j])
	    {
	        crr[k++]=arr[i++];
	    }
	    if(brr[j]<=arr[i])
	    {
	        crr[k++]=brr[j++];
	    }
	}
	if(i==n1)
	{
	    while(j<n2)
	    {
	        crr[k++]=brr[j++];
	    }
	}
	if(j==n2)
	{
	    while(i<n1)
	    {
	        crr[k++]=arr[i++];
	    }
	}
	for(int m=0;m<n1+n2;m++)
	{
	    cout<<crr[m]<<" ";
	}
	return 0;
}
