#include <bits/stdc++.h>
using namespace std;
//find median of two sorted arrays in O(logn)
int max(int a, int b)
{
    return a>=b ? a:b;
}
int min(int a, int b)
{
    return a<=b ? a:b;
}
int median_of_arrays(int arr[], int brr[], int an, int bn)
{
    int mid1,mid2;
    int l=0,h=an;
    while(l<=h)
    {
        mid1=l+(h-l)/2;
        mid2=(an+bn+1)/2 - mid1;
        int min1 = mid1==an ? INT_MAX : arr[mid1];
        int max1 = mid1==0 ? INT_MIN : arr[mid1-1];
        int min2 = mid2==bn ? INT_MAX : brr[mid2];
        int max2 = mid2==0 ? INT_MIN : brr[mid2-1];
        if(min1>=max2 && min2>=max1)
        {
            if((an+bn)%2==0)
            {
                return (max(max1,max2)+min(min1,min2))/2;
            }
            else
            {
                
                return max(max1, max2);
            }
        }
        else if(min1<max2)
        {
            l=mid1+1;
        }
        else
        {
            h=mid1-1;
        }
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2,an,bn;
	    cin>>n1>>n2;
	    int arr[n1],brr[n2];
	    for(int i=0;i<n1;i++)
	    {
	        cin>>arr[i];
	    }
	    for(int i=0;i<n2;i++)
	    {
	        cin>>brr[i];
	    }
	    if(n1>=n2)
	        cout<<median_of_arrays(brr,arr,n2,n1)<<endl;
	    else
	        cout<<median_of_arrays(arr,brr,n1,n2)<<endl;
	}
	return 0;
}
