#include<bits/stdc++.h>
using namespace std;
//using simple recursion
int CountSubsetSum(int arr[], int n, int sum)
{
    if(n==0)
        return sum==0 ? 1 : 0;
    return CountSubsetSum(arr,n-1,sum)+CountSubsetSum(arr,n-1,sum-arr[n-1]);
}
int main()
{
    int arr[]={10,20,15,10};
    int n=sizeof(arr)/sizeof(int);
    int sum=20;
    cout<<CountSubsetSum(arr,n,sum)<<endl;;
}
