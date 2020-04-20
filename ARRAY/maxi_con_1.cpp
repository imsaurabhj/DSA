#include <iostream>
using namespace std;
//maximum consecutive 1's in an array;
//efficient solution

int maxi(int a, int b)
{
    return a>b ? a:b;
}
int consecutive_ones(int arr[], int n)
{
    int max=0;
    int i=0,j=0;
    while(j<=n)
    {
        if(arr[j]==1)
            j++;
        else
        {
            int temp = j-i;
            max=maxi(max,temp);
            j++;
            i=j;
        }
    }
    return max;
}

int main() {
	int arr[]={0,0,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<consecutive_ones(arr,n)<<endl;
	return 0;
}
