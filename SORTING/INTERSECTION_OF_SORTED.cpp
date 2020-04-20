#include <iostream>
using namespace std;
//intersection of two sorted array
void intersect(int a[], int b[], int n, int m)
{
    int i=0,j=0;
    if(a[i]==b[i]){
        cout<<a[i]<<" ";
        i++; j++;
    }
    while(i<n && j<m)
    {
        if(a[i]==b[j] && a[i]!=a[i-1]){
            cout<<a[i]<<" ";
            i++; j++;
        }
        else if(a[i]<b[j])
            i++;
        else
            j++;
    
    }
}

int main() {
	int a[]={3,5,10,10,10,15,15,20};
	int b[]={3,5,10,10,15,30};
	int n=sizeof(a)/sizeof(int);
	int m=sizeof(b)/sizeof(int);
	intersect(a,b,n,m);
	return 0;
}
