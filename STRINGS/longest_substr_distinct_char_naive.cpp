#include <bits/stdc++.h>
using namespace std;
//longest substring having distinct characters
//O(n^2)
int sub_distinct(string str)
{
    int res=0,j;
    int n=str.size(),k;
    for(int start=0;start<n;start++)
    {
        unordered_set<int> s;
        for(j=start;j<n;j++)
        {
            if(s.find(str[j])==s.end())
                s.insert(str[j]);
            else
            {k=s.size(); res=max(res,k); break; }
                
        }
        if(j==n)
        { k=s.size(); res=max(res,k); break;  }
    }
    return res;
}
int main() {
	cout<<sub_distinct("aaaa");
	return 0;
}
