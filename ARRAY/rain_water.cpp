#include <iostream>
using namespace std;
//rain water trapped problem
//efficient solution
//O(n)

int max(int a, int b)
{
    return a>b ? a:b;
}

int min(int a, int b)
{
    return a<b ? a:b;
}

int trapped_water(int arr[],int n)
{
    int res=0;
    int lmax[n],rmax[n];
    lmax[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        lmax[i]=max(arr[i],lmax[i-1]);
    }
    rmax[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rmax[i]=max(arr[i],rmax[i+1]);
    }
    for(int i=1;i<n-1;i++)
    {
        res+=(min(lmax[i],rmax[i])-arr[i]);
    }
    return res;
}
int main() {
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
    cout<<trapped_water(arr,n)<<endl;
	return 0;
}
