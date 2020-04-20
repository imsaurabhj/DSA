#include <iostream>
using namespace std;
//subarray having sum equal to given value
//O(n) solution
bool sub_arr_sum(int arr[], int n, int target)  // target is required sum
{
    int sum=arr[0];
    int i=0,j=0;
    while(j<n)
    {
        if(sum<target)
            sum+=arr[++j];
        else if(sum>target)
            sum-=arr[i++];
        else if(sum==target)
           { return true;}
    }
    return false;
}
int main() {
	int arr[]={1,4,0,0,3,2,5};
	int n=sizeof(arr)/sizeof(int);
	cout<<sub_arr_sum(arr,n,7)<<endl; 
	return 0;
}
