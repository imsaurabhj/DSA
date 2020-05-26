#include<bits/stdc++.h>
using namespace std;
//using simple recursion

int knapsack01(int value[], int weight[], int W, int n)
{
    if(n==0 || W==0)
        return 0;
    int res1= knapsack01(value,weight,W,n-1);
    int res2=0;
    
    if(W>=weight[n-1])
        res2=value[n-1]+knapsack01(value,weight,W-weight[n-1],n-1);

    return max(res1,res2);
}
int main()
{
    int value[]={60,100,120};
    int weight[]={5,4,6,3};
    int n=sizeof(value)/sizeof(int);
    int W=10;
    cout<<knapsack01(value,weight,W,n)<<endl;
}