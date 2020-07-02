#include<bits/stdc++.h>
using namespace std;
int countchange(int arr[], int n, int sum,vector<vector<int>> &dp)
{
    if(sum==0)
        return 1;
    if(n==0)
        return 0;
    int res=0;

    if(dp[n-1][sum]==-1)
       dp[n-1][sum]=countchange(arr,n-1,sum,dp);
    dp[n][sum]=dp[n-1][sum];    
    if(sum>=arr[n-1])
    {
        if(dp[n][sum-arr[n-1]]==-1)
            dp[n][sum-arr[n-1]]=countchange(arr,n,sum-arr[n-1],dp);
        dp[n][sum]+=dp[n][sum-arr[n-1]];
    }
    return dp[n][sum];

}
int main()
{
    int arr[]={1,3,2};
    int n=3;
    int sum=4;
    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
    cout<<countchange(arr,n,sum,dp)<<endl;
}