#include<bits/stdc++.h>
using namespace std;
int countchange(int arr[], int n, int sum)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    int res=countchange(arr,n-1,sum);
    if(sum>=arr[n-1])
        res+=countchange(arr,n,sum-arr[n-1]);
    return res;
}
int main()
{
    int arr[]={1,3,2};
    int n=3;
    int sum=4;
    int dp[4];
    memset(dp,-1,sizeof(dp));
    cout<<countchange(arr,n,sum)<<endl;
}