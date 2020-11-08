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
    {4,0,2,6,0},
    {8,2,0,3,9},
    {0,6,3,0,5},
    {0,0,9,5,0},
};
int main(){

    int dist[V];//initialise all with infinity path
    bool visit[V]={false}; //all visited array is false
    int parent[V];
    parent[0]=-1;
    for(int i=0;i<5;i++)
        dist[i]=INT_MAX;
    dist[0]=0;


        for(int i=0;i<5;i++)
        {
                    int u=findVertex(dist,visit);
                    visit[u]=true;
                    for(int v=0;v<5;v++)
                    {
                        if(graph[u][v] && visit[v]!=true)
                        {
                           if(graph[u][v]<dist[v])
                           {
                               dist[v]=graph[u][v];
                               parent[v]=u;
                           }
                        }
                    }

        }

        int cost=0;
        for(int i=0;i<5;i++)
            if(graph[i][parent[i]])
                cost=cost+graph[i][parent[i]];
        cout<<"Cost of Mst is "<<cost;
}

