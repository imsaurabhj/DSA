#include <iostream>
#include<unordered_map>
using namespace std;
//distinct elements in window of length of k
void count_distinct(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<k;i++)
    {
        m[arr[i]]++;
    }
    int i=0,j=k;
    cout<<m.size()<<" ";
    while(j<n)
    {
        m[arr[i]]--;
        m[arr[j]]++;
        j++;
        if(m[arr[i]]==0)
            m.erase(arr[i]);
        i++;
        cout<<m.size()<<" ";
    }
}
int main() {
	int arr[]={10,20,20,10,30,40,10};
	int n=sizeof(arr)/sizeof(int);
	int k=3;
	count_distinct(arr,n,k);
	return 0;
}
