#include <bits/stdc++.h>
using namespace std;
//longest substring having distinct character
//O(n)
int sub_distinct(string str)
{
    int i=0,j=0,k,n=str.size(),res=0;;
    unordered_set<int> s;
    while(j<n)
    {
        if(s.find(str[j])==s.end())
        {
            s.insert(str[j]);
            k=s.size();
            res=max(res,k);
            j++;
        }
        else
        {
            if(str[i]==str[j]){
                s.erase(str[i]);
                i++;
            }
            else
                i++;
        }
    }
    return res;
}
int main() {
	cout<<sub_distinct("abcdabca")<<endl;
	return 0;
}
