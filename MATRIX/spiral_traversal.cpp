#include <iostream>
using namespace std;
//Spiral Traversal of matrix;
const int R=5;
const int C=5;
void creatematrix(int mat[R][C])
{   int k=1;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            mat[i][j]=k++;
}
void print(int mat[R][C])
{
    for(int i=0;i<R;i++)
    {    
        for(int j=0;j<C;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;       
    }
    cout<<endl;
}
void printboundary(int mat[R][C],int r, int c,int s, int e)
{
    if(r==1)
    {
        for(int i=s;i<c-e;i++)
        {
            cout<<mat[s][i]<<" ";
        }
    }
    else if(c==1)
    {
        for(int j=s;j<r-e;j++)
        {
            cout<<mat[j][s]<<" ";
        }
    }
    else
    {
        for(int i=s;i<=C-2+e;i++)
            cout<<mat[s][i]<<" ";
        for(int i=s;i<=R-2+e;i++)
            cout<<mat[i][C-1+e]<<" ";
        for(int i=C-1+e;i>=1+s;i--)
            cout<<mat[R-1+e][i]<<" ";
        for(int i=R-1+e;i>=1+s;i--)
            cout<<mat[i][s]<<" ";
    }
}
void spiraltraversal(int mat[R][C])
{
    int row=R,col=C;
    int start=0,end=0;
    while(row>0 && col>0)
    {
        printboundary(mat,row,col,start,end);
        row=row-2;
        col=col-2;
        start++;
        end--;
    }
}
int main() {
	int mat[R][C];
	creatematrix(mat);
	print(mat);
	spiraltraversal(mat);
	return 0;
}
