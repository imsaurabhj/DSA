#include <iostream>
using namespace std;
//Merge function for merge sort
void merge(int arr[], int l, int m,int r)
{
    int len=r-l+1;
    int c[len];
    int i=l,j=m+1;
    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j])
            c[i++];
        else
            c[j++];
    }
    while(i<=m)
        c[i++];
    while(j<=r)
        c[i++];
    for(int i=0;i<len;i++)
    {
        arr[i+l]=c[i];
    }
}


int main() {
	int arr[]={1,2,3,10,3,5,7,9};
	merge(arr,0,3,7);
	for(int i=0;i<7;i++){
	    cout<<arr[i]<<" ";
	}
	return 0;
}
