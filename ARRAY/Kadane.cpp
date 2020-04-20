#include <iostream>
using namespace std;
//maximum subarray problem
// recursively
int max(int a, int b)
{
    return a>b ? a : b;
}
int maxsum(int arr[], int end)
{
    int maxsum=arr[0];
    int cursum=arr[0];
    for(int i=1;i<n;i++)
    {
    	cursum=max(arr[i], cursum+arr[i]);
    	maxsum=max(maxsum,cursum);
    }
    return maxsum;
}

int main() {
	
	int arr[]={2,3,-8,7,-1,2,3};
    int n= sizeof(arr)/sizeof(int);
    cout<<maxsum(arr,n-1)<<endl;
	// your code goes here
	return 0;
}
