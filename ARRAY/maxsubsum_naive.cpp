#include <iostream>
using namespace std;
//MAXIMUM SUBARRAY SUM
//NAIVE SOLUTION
//O(n^2)

int maxi(int a, int b)
{
    return a>b ? a:b;
}

int maxsum(int arr[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {   
        int temp=0;
        for(int j=i;j<n;j++)
        {
            temp+=arr[j];
            max=maxi(max,temp);
        }
    }
    return max;
}
int main() {
    int arr[]={2,3,-8,7,-1,2,3};
    int n= sizeof(arr)/sizeof(int);
    cout<<maxsum(arr,n)<<endl;
	// your code goes here
	return 0;
}
