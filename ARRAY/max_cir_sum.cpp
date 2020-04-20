#include <iostream>
using namespace std;
//Maximum circular subarray sum
// naive solution
int max(int a, int b)
{
    return a>b ? a:b;
}
int maxcirsubsum(int arr[], int n)
{
    int res=arr[0],j;
    for(int i=0;i<n;i++)
    {
        int temp=0;
        j=i;
        while(j-i<=n-1)
        {
            temp+=arr[j%n];
            res=max(temp,res);
            j++;
        }
    }
    return res;
    
}
int main() {
	int arr[]={10,5,-5,10};
	int n=sizeof(arr)/sizeof(int);
	cout<<maxcirsubsum(arr,n)<<endl;
	return 0;
}
