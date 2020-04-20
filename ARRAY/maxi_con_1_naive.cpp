#include <iostream>
using namespace std;
//maximum consecutive 1's in an array;
//naive solution
int maxi(int a, int b)
{
    return a>b ? a:b;
}
int consecutive_ones(int arr[],int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {   
        int count=0;
        int j=i;
        while(arr[j]==1)
        {
            count++;
            j++;
        }
        max=maxi(count,max);
    }
    return max;
}
int main() {
	// your code goes here
	int arr[]={1,1,1,1,0,0,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<consecutive_ones(arr,n)<<endl;
	return 0;
}
