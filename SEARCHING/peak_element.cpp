#include <iostream>
using namespace std;
//SEARCH FOR THE PEAK ELEMENT IN AN ARRAY

int findpeak(int arr[], int n)
{
    int l=0, h=n-1;
    while(l<=h)
    {
        int mid=l+(h-l)/2;
        if(mid==0)
        {
            if(arr[0]>=arr[1])
                return mid;
        }
        if(mid==n-1)
        {
            if(arr[n-1]>=arr[n-2])
                return mid;
        }
        if(arr[mid]>=arr[mid-1] && arr[mid]>=arr[mid+1])
            return mid;
        if(arr[mid-1]>=arr[mid])
            h=mid-1;
        else if(arr[mid+1]>=arr[mid])
            l=mid+1;
    }
    
}

int main() {
	int arr[]={7,2,5,4,3,6,7};
    int n=sizeof(arr)/sizeof(int);
    cout<<findpeak(arr,n)<<endl;
	return 0;
}
