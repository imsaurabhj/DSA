#include <iostream>
using namespace std;
//Rotate matrix 90 degree clockwise
const int R=4;
const int C=4;
void creatematrix(int mat[R][C])
{   int k=1;
    for(int i=0;i<R;i++)
        for(int j=0;j<C;j++)
            mat[i][j]=k++;
}
void transpose(int mat[R][C])
{
    for(int i=0;i<R;i++)
        for(int j=i+1;j<C;j++)
            swap(mat[i][j],mat[j][i]);
}
void reversecol(int mat[R][C], int x)
{
    int l=0,h=R-1;
    while(l<=h)
    {
        swap(mat[l][x],mat[h][x]);
        l++; h--;
    }
        
}
void rotate90(int mat[R][C])
{
    transpose(mat);
    for(int i=0;i<C;i++)
        reversecol(mat,i);
}
void print(int mat[R][C])
{
    for(int i=0;i<R;i++)
    {    
        for(int j=0;j<C;j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;       
    }
}
int main() {
	int mat[R][C];
	creatematrix(mat);
	print(mat);
	cout<<endl;
	rotate90(mat);
	print(mat);
	return 0;
}
