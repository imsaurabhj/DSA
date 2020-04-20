#include <iostream>
using namespace std;
// maximum subarray of k consecutive elements
//using sliding window technique
//O(n) solution
int max(int a, int b)
{
    return a>b ? a:b;
}

int maxsubarr_k(int arr[], int n, int k)
{
    int sum=0,maxsum;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    maxsum=sum;
        int i=0, j=k;
    while(j<n)
    {
        sum=sum-arr[i]+arr[j];
        maxsum=max(maxsum,sum);
        i++;
        j++;
    }
    return maxsum;
}

int main() {
	int arr[]={3,-4,5,6,-8,7};
	int n=sizeof(arr)/sizeof(n);
	cout<<maxsubarr_k(arr,n,4)<<endl;
	return 0;
}
