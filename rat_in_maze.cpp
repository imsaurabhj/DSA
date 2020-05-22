#include<bits/stdc++.h>
using namespace std;
#define SIZE 4

bool findpath(int maze[SIZE][SIZE], int path[SIZE][SIZE],int x=0,int y=0)
{
    path[x][y]=1;
    if(x==SIZE-1 && y==SIZE-1)
        return true;
    int nx=x+1, ny=y;                          //nx=new x-co-ordiante, ny=new y-co-ordinate
    if(nx<SIZE && ny<SIZE && path[nx][ny]!=1 && maze[nx][ny]!=0)
    {
        if(findpath(maze,path,nx,ny))
            return true;
    }
    nx=x,ny=y+1;
    if(nx<SIZE && ny<SIZE && path[nx][ny]!=1 && maze[nx][ny]!=0)
    {
        if(findpath(maze,path,nx,ny))
            return true;
    }
    path[x][y]=0;
    return false;
    
}
void printpath(int path[SIZE][SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        for(int j=0;j<SIZE;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int maze[SIZE][SIZE]={{1,1,0,0},{1,1,0,1},{0,1,0,0},{1,1,1,1}};
    int path[SIZE][SIZE]={0};
    bool found=findpath(maze,path);
    found ? cout<<"YES"<<endl : cout<<"NO"<<endl;
    if(found)
    {
        printpath(path);
    }
    return 0;
}