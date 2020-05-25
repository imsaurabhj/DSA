#include<bits/stdc++.h>
using namespace std;
//Generate all subsets of size K

void fillsubsetsK(vector<int> arr, vector<vector<int>> &subsets, int K, vector<int> &ans, int index=0)
{
    if(ans.size()==K)
    {
        subsets.push_back(ans);
        return;
    }
    if(ans.size()>K || index==arr.size() )
        return;
    //cout<<ans.size()<<endl;
    fillsubsetsK(arr,subsets,K,ans,index+1);
    ans.push_back(arr[index]);
    fillsubsetsK(arr,subsets,K,ans,index+1);
    ans.pop_back();

}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7}; 
    int K=8;
    vector<vector<int>> subsets;
    vector<int> ans;
    if(K>arr.size())
        cout<<"No possible subsets"<<endl;
    else{
        fillsubsetsK(arr,subsets,K,ans);
        for(auto v:subsets)
        {
            for(auto x:v)
                cout<<x<<" ";
            cout<<endl;
        }
    }
    return 0;
}