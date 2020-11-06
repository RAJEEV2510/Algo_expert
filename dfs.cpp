#include<iostream>
#include<queue>
using namespace std;
//graph
int graph[4][4]={
    {0,1,1,0},
    {0,0,1,0},
    {1,0,0,1},
    {0,0,0,1},

};
//queue
queue <int> que;
//main function
int main()
{
    bool node[4]={false};

    que.push(0);

    node[0]=true;

    while (!que.empty())
    {
       int u= que.front();
       que.pop();
        cout<<u;

       for(int v=0;v<=3;v++)
       {

           if(graph[u][v])
           {
               if(!node[v])

               {

                 que.push(v);
                 node[v]=true;
               }

           }
        }
    }
}
