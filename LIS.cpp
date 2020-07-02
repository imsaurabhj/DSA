#include<bits/stdc++.h>
using namespace std;

int LIS(int arr[], int n, int index, int last)
{
    if(index==n)
        return 0;
    int res1=0,res2=0;
    res1=LIS(arr,n,index+1,last);
    if(arr[index]>last)
        res2=1+LIS(arr,n,index+1,arr[index]);
    return max(res1,res2);
}
int main()
{
    int arr[]={30,20,5};
    int n=3;
    cout<<LIS(arr,n,0,INT_MIN)<<endl;
    
    return 0;
}