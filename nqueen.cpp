#include<iostream>
using namespace std;

bool safePlaceBoard(int board[][10],int i ,int j,int n)
{
    //check in top row
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
            return false;
    }
    int x,y;
    x=i;
    y=j;

    //left diagonal
    while(x>=0 && y>=0)
    {
        if(board[x][y]==1)
            return false;

        x--;
        y--;

    }
    x=i;
    y=j;
    while(x>=0 && y<n)
    {
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }

    return true;

}


bool solvequeen(int board[][10],int i ,int n)
{
    if(i==n)
    {
        //print the answer
        for(int k=0;k<n;k++)
        {
            for(int j=0;j<n;j++)
               {
                    cout<<board[k][j]<<"\t";
                }
            cout<<"\n";

        }
        return true;
    }

    //check one by one column where we can place the queen at right place
    for(int j=0;j<n;j++)
    {
        if(safePlaceBoard(board,i,j,n))
        {
            board[i][j]=1;//if get true then we put 1 there

            //now check for next row it is true or not
            bool nextrowqueenplace=solvequeen(board,i+1,n);
            if(nextrowqueenplace)
                return true;

            board[i][j]=0;//backtrack
        }

    }
    //if all the column failed to place the queen then return false
    return false;

}

int main()
{
    int n;//number of queen;
    cout<<"Enter the number of queen\n";
    cin>>n;
    int i=0;
    int board[10][10]={0};//chess board
    solvequeen(board,i,n);//passing the board 1st row and number of rows

}
