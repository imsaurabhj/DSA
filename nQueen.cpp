#include<bits/stdc++.h>
using namespace std;
#define N 8
bool isSafe(int board[][N], int row, int col)
{
    int r=row-1,c=col-1;                  
    while(r>=0 && r<N && c>=0 && c<N)       // check for upper primary diagonal
    {
        if(board[r][c]==1)
            return false;
        r--; c--;
    }

    r=row+1; c=col+1;
    while(r>=0 && r<N && c>=0 && c<N)  //check for lower primary diagonal
    {
        if(board[r][c]==1)
            return false;
        r++; c++;
    }

    r=row+1; c=col-1;
    while(r>=0 && r<N && c>=0 && c<N)  //check for lower secondary diagonal
    {
        if(board[r][c]==1)
            return false;
        r++; c--;
    }

    r=row-1; c=col+1;
    while(r>=0 && r<N && c>=0 && c<N)  //check for upper primary diagonal
    {
        if(board[r][c]==1)
            return false;
        r--; c++;
    }
    return true;

}

bool fillboard(int board[N][N], int row[], int count=0)
{
    if(count==N)
        return true;
    for(int i=0;i<N;i++)
    {
        if(row[i]==0)
        {
            board[i][count]=1;
            row[i]=1;
            if(isSafe(board,i,count))
            {
                if(fillboard(board,row,count+1))
                    return true;
            }
            board[i][count]=0; 
            row[i]=0;
        }
    }
    return false;
}
void printboard(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int board[N][N]={0};
    int row[N]={0};
    if(fillboard(board,row))
    {
        cout<<"YES"<<endl;
        printboard(board);
    }
    else
        cout<<"NO"<<endl;

}