#include<bits/stdc++.h>
using namespace std;
//To find if there is any subset whose sum of all elements is equal to given sum using BACKTRACKING

bool findSubsetSum(vector<int> arr, vector<int> &ele, int sum, int index=0)
{
    if(sum==0)
        return true;
    
    if(index==arr.size())              //if we reach the dead end of array
        return false;

    if(findSubsetSum(arr,ele,sum,index+1))     //we dont choose the element present at given index
        return true;
    
    int temp=sum-arr[index];
    ele.push_back(arr[index]);

    if(temp>=0)                                  //we choose this element for positive sum since all numbers are positive we'll never reach any solution in this 
    {                                             //recursion tree. hence we pop out the element . We also pop out if we dont reach any solution from here
        if(findSubsetSum(arr,ele,temp,index+1))
            return true;
    }
    ele.pop_back();
    return false;
}
int main()
{
    vector<int> arr={5,10,12,14,15,19};
    int sum=30;
    vector<int> ele;
    if(findSubsetSum(arr,ele,sum))
    {
        cout<<"YES"<<endl;
        for(int i=0;i<ele.size();i++)
            cout<<ele[i]<<" ";
        cout<<endl;
    }
    else
        cout<<"NO"<<endl;

    return 0;
}