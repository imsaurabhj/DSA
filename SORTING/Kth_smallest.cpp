#include <iostream>
using namespace std;
//Kth small element
void kth_smallest(int arr[], int l,int h, int k)
{
    int i=l-1;
    int peak=arr[h];
    for(int j=l;j<=h;j++)
    {
        if(arr[j]<=peak)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    if(i==k-1)
    return;
    else if(i<k-1)
    kth_smallest(arr,i+1,h,k);
    else
    kth_smallest(arr,l,i-1,k);
    

}
int main() {
	int arr[]={30,20,5,10,8};
	int n= sizeof(arr)/sizeof(int);
	int k=n;
	kth_smallest(arr,0,n-1,k);
	cout<<arr[k-1]<<endl;
	return 0;
}
