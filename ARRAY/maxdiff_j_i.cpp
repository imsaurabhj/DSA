#include <iostream>
using namespace std;
//MAXIMUM DIFFERENCE of arr[j]-arr[i], j>i
//O(n) solution
//efficient solution

int maxdifference(int arr[],int n)
{
    int maxdiff=arr[1]-arr[0];
    int min=arr[0];
    for(int j=1;j<n;j++)
    {
        int tempdiff=arr[j]-min;
        
        if(tempdiff>maxdiff)
            maxdiff=tempdiff;
        
        
        if(arr[j]<min)
            min=arr[j];
        
    }
    return maxdiff;
}



int main() {
	
	int arr[]={40,20,15,9,6,5,3,1};
	int n= sizeof(arr)/sizeof(int);
	cout<<maxdifference(arr,n)<<endl;
	return 0;
}
