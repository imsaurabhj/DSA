#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
//merging overlapping interval
//O(nlogn)
int max(int a, int b)
{
    return a>b ? a:b;
}

bool mycomp(pair<int,int> p1, pair<int,int> p2)
{
    if(p1.first<=p2.first)
        return true;
    else if(p1.f>p2.f)
        return false;
}
void merge_intervals(vector<pair<int,int>> v,int n)
{
    sort(v.begin(),v.end(),mycomp);
/*    	for(int i=0;i<n;i++)
	{
	    cout<<v[i].first<<" "<<v[i].second<<endl;
	}
*/
int l=v[0].first, h=v[0].second;
    for(int i=0;i<n-1;i++)
    {
        if(v[i].second>=v[i+1].first)
        {
            h=max(v[i].second,v[i+1].second);
        }
        if(v[i].second<v[i+1].first)
        {
            cout<<l<<" "<<h<<endl;
            l=v[i+1].first; h=v[i+1].second;
        }
        
    }
    cout<<l<<" "<<h<<endl;
}
int main() {
	vector<pair<int,int>> v1 ={make_pair(1,3),make_pair(2,4),make_pair(5,7),make_pair(6,8),make_pair(11,15)};
	merge_intervals(v1,5);
	return 0;
}
