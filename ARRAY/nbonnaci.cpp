#include <iostream>
using namespace std;
//N-bonacci numbers;
//window sliding technique
void n_bonacci(int n, int m)
{
    int arr[m];
    int curr_sum=1;
    int i=0,j=n-1;
    for(int k=0;k<m;k++)
    {
        if(k<n-1)
        {
            arr[k]=0;
            cout<<arr[k]<<" ";
        }
        if(k==n-1 || k==n)
        {
            arr[k]=1;
            cout<<arr[k]<<" ";
        }
        if(k>n)
        {
            curr_sum+=(-arr[i++]+arr[++j]);
            arr[k]=curr_sum;
            cout<<arr[k]<<" ";
        }
    }
}

int main() {
    n_bonacci(4,10);
	return 0;
}
