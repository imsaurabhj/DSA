#include <iostream>
using namespace std;
//hoare's partition
void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
    cout<<"v";
}
int hoare(int arr[], int l, int h)
{
    int i=l-1,j=h+1;
    int peak=arr[l];
    while(true)
    {   do{ i++;}while(arr[i]<peak);
        do{j--; }while(arr[j]>peak);
        if(i>=j) return j;
        swap(arr[i],arr[j]);
    }
}
int main() {
	
int arr[]={5,4,3,2,1};
	int n=sizeof(arr)/sizeof(int);
	cout<<hoare(arr,0,n-1)<<endl;
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}
	return 0;
}
