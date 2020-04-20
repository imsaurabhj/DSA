#include <iostream>
#include<unordered_set>
using namespace std; 
//find subarray with zero sum
//using hashing, prefix sum technique
//negative integers are also allowed
bool subarray_zero_sum(int arr[], int n)
{
    for(int i=1;i<n;i++)
        arr[i]+=arr[i-1];
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        if(s.find(arr[i])!=s.end())
            return true;
        if(arr[i]==0)
            return true;
        else
            s.insert(arr[i]);
    }
    return false;
}

int main() {
	int arr[]={2,-1,-1,-6,-10,15};
	int n=sizeof(arr)/sizeof(int);
	cout<<subarray_zero_sum(arr,n)<<endl;
	return 0;
}
