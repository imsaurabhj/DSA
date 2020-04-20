#include <iostream>
using namespace std;
//print matrix in snake pattern
int main() {
	int arr[4][3]={1,2,3,4,5,6,7,8,9,10,11,12};
	bool lr=true;
	for(int i=0;i<4;i++)
	{
	    if(lr){
	        for(int j=0;j<3;j++){
	            cout<<arr[i][j]<<" ";
	        }
	        lr=false;
	    }
	    else
	    {
	        for(int j=2;j>=0;j--)
	        {
	            cout<<arr[i][j]<<" ";
	        }
	        lr=true;
	    }
	}
	return 0;
}
