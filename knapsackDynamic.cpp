#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
        cout<<"-------KNAPSACK DYNAMIC PROGRAMMING--------";
        int m=8,W=8,n=4,i,j;
        int p[]={0,1,2,5,6};//zero use for zero index
        int w[]={0,2,3,4,5};//zero use for zero index
        int t[5][9];///size declaration always greater than profit array and weight  array

        for(i=0;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                if(i==0 || j==0)///initialisation
                    t[i][j]=0;
                else if(w[i]<=j)
                    t[i][j]=max((p[i]+t[i-1][j-w[i]]),t[i-1][j]);
                else
                    t[i][j]=t[i-1][j];
            }

        }
       cout<<"\n";
       for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<t[i][j]<<"\t";
            }
            cout<<"\n";
        }


}
