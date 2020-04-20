#include <iostream>
using namespace std;
//Lomuto partition
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
    cout<<"v";
}
using namespace std;
int lomuto(int arr[], int l, int h, int p)
{
    swap(arr[p],arr[h]);
    int pivot=arr[h];
    int i=-1;
    for(int j=l;j<=h;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    return i;
}

int main() {
	int arr[]={6,2,1,8,6,9,10};
	int n=sizeof(arr)/sizeof(int);
	cout<<lomuto(arr,0,n-1,0)<<endl;
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}
	return 0;
}
