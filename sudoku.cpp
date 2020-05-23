#include<bits/stdc++.h>
using namespace std;
#define N 9
//solve Sudoku for N x N

bool isSafe(int board[][N], pair<int,int> point)
{
    int sqN=(int)sqrt(N);
    int r=point.first;
    int c=point.second;
    unordered_set<int> row;
    for(int i=0;i<N;i++)
    {
        if(board[r][i]!=0)
        {
            if(row.find(board[r][i])==row.end())
                row.insert(board[r][i]);
            else
                return false;
        }
    }
    // cout<<"yo"<<endl;
    unordered_set<int> col;
    for(int i=0;i<N;i++)
    {
        if(board[i][c]!=0)
        {
            if(col.find(board[i][c])==col.end())
                col.insert(board[i][c]);
            else
                return false;
        }
    }
//    cout<<"yo"<<endl;
    unordered_set<int> grid;
    int startr = ((int)(r/sqN))*sqN; int endr= startr+sqN-1;
    int startc = ((int)(c/sqN))*sqN; int endc= startc+sqN-1;

    for(int i=startr;i<=endr;i++)
    {
        for(int j=startc;j<=endc;j++)
        {
            if(board[i][j]!=0)
            {
                if(grid.find(board[i][j])==grid.end())
                    grid.insert(board[i][j]);
                else
                    return false;
            }
        }
    }
    return true;

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

bool solveSudoku(int board[][N], vector<pair<int,int>> v,int index=0)
{
    if(index==v.size())
        return true;
    
    int r=v[index].first;
    int c=v[index].second;
    //cout<<r<<" "<<c<<endl;
    for(int i=1;i<=N;i++)
    {
        board[r][c]=i;
        if(isSafe(board,v[index]))
        {   
            if(solveSudoku(board,v,index+1))
                return true;
        }
        board[r][c]=0;
    }
    return false;
}


int main()
{
    int board[N][N]={
                    {7,5,0,1,0,0,0,0,4},
                    {0,9,6,8,3,2,1,5,7},
                    {0,1,8,7,0,0,3,9,6},
                    {5,0,0,0,0,0,6,7,2},
                    {0,0,0,0,0,0,8,3,1},
                    {0,2,0,0,0,3,0,0,9},
                    {3,0,4,0,6,0,0,0,8},
                    {0,8,5,4,0,0,0,0,3},
                    {0,0,0,3,7,0,0,0,0,}
                    };
    vector<pair<int,int>> vec;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j]==0)
                vec.push_back({i,j});
        }
    }

    if(solveSudoku(board,vec))
    {
        cout<<"YES"<<endl;
        printboard(board);
    }
    else
        cout<<"NO"<<endl;
     //   printboard(board);
    // board[0][1]=2;
    // cout<<isSafe(board,{0,1})<<endl;; 
    return 0;
}