#include<iostream>
using namespace std;
int INF=99;

int main()
{
     int graph[4][4]={
        {0,1,0,1},
        {0,0,1,0},
        {0,0,0,1},
        {0,0,0,0},
        };
        //distance matrix
        int dist[4][4]{
        {0,5,INF,10},
        {INF,0,3,INF},
        {INF,INF,0,1},
        {INF,INF,INF,0},
        };
    int i,j,k;

    for(k=0;k<4;k++)
   {

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {

                if(dist[i][j]>dist[i][k]+dist[k][j])
                    dist[i][j]=dist[i][k]+dist[k][j];
            }

        }
   }

//all the distances finding by warshel algorithm

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(dist[i][j]!=INF)
            {
                dist[i][j]=1;
            }
            else
            {
                dist[i][j]=0;
            }
        }

    }


      for(i=0;i<4;i++)
   {

       for(j=0;j<4;j++)
       {
           cout<<dist[i][j]<<"\t";
       }
       cout<<"\n";
   }


}
