#include<iostream>
#define V 5
using namespace std;
int findVertex(int dist[],bool visit[])///find Min vertex distance
{
    int min_value=INT_MAX;
    int min_index;
    for(int i=0;i<V;i++)
        if(min_value>dist[i] && visit[i]!=true)
         {
             min_value=dist[i];
             min_index=i;
         }
    return min_index;
}
int graph[5][5]={
    {0,4,8,0,0},
    {4,0,2,5,0},
    {8,2,0,5,9},
    {0,5,5,0,4},
    {0,0,9,4,0},
};
int main(){

    int dist[V];//initialise all with infinity path
    bool visit[V]={false}; //all visited array is false
    for(int i=0;i<5;i++)
        dist[i]=INT_MAX;
    dist[0]=0;
        for(int i=0;i<5;i++)
        {
                    int u=findVertex(dist,visit);
                    for(int v=0;v<5;v++)
                    {
                        if(graph[u][v] && visit[i]!=true)
                        {
                            if(graph[u][v]+dist[u]<dist[v])//relaxation condition
                                dist[v]=graph[u][v]+dist[u];
                        }

                    }
                        visit[u]=true;
        }

    for(int i=0;i<5;i++)
        cout<<i<<"->"<<dist[i]<<endl;
}
