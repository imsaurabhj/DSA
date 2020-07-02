#include<bits/stdc++.h>
using namespace std;
//minimum number of jumps required to reach the end of array

int minjumps(int jump[], int n, int dp[],int index=0)
{
    if(index==n-1)
        return 0;
    if(index>=n)
        return INT_MAX;
    
    int res=INT_MAX;
    if(dp[index]==-1)
    {
        for(int i=1;i<=jump[index];i++)
        {
            int temp=minjumps(jump,n,dp,index+i);
            if(temp!=INT_MAX)
                res=min(res,1+temp);
        }
        dp[index]=res;
    }
    return dp[index];
}

int main()
{
    int jumps[]={1,0,0};
    int n=sizeof(jumps)/sizeof(int);
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    cout<<minjumps(jumps,n,dp)<<endl;    
    cout<<endl;
    return 0;
}