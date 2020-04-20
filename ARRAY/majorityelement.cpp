#include <iostream>
using namespace std;
// majority element in an array i.e which appears more than n/2 times

int majorityelement(int arr[], int n)
{
    int count=0;
    for(int i=0;i<n;i++)
    {
        count=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
                count++;
        }
        if(count>n/2)
            return i;
    }
    return -1;
}

int main() {
	int arr[]={2,3,4,1,1,1,1,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<majorityelement(arr,n)<<endl;
	return 0;
}
