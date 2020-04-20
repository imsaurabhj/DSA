#include <iostream>
//MAXIMUM DIFFERENCE of arr[j]-arr[i], j>i
//O(n^2)
//naive solution

int maxdiff(int arr[], int n)
{
    int temp=0;
    int max=arr[1]-arr[0];
    for(int i=0; i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            temp=arr[j]-arr[i];
            if(temp>max)
            {
                max=temp;
            }
        }
    }
    return max;
}
int main() {
    int arr[]={7,9,5,10,6,3,2};
    int n=sizeof(arr)/sizeof(int);
    cout<<maxdiff(arr,n)<<" ";
	return 0;
}
