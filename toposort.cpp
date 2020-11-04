#include<iostream>
#include<stack>
#define node 6
using namespace std;
void toposort(int u ,bool ary[]);
int graph[node][node]={

    {0,0,0,0,0,0},
    {0,0,0,0,0,0},
    {0,0,0,1,0,0},
    {0,1,0,0,0,0},
    {1,1,0,0,0,0},
    {1,0,1,0,0,0}
};
stack <int> arr;

int main()
{
    bool ary[node];
    for(int i=0;i<node;i++)
    {
        ary[i]=false;
    }

    for(int u=0;u<node;u++)
    {
        if(!ary[u])
       {

            toposort(u,ary);
       }
    }

    //stack printing
    while(!arr.empty())
    {
        cout<<arr.top();
        arr.pop();
    }

}


void toposort(int u ,bool ary[])
{
    ary[u]=true;
    for(int v=0;v<node;v++)
    {
        if(graph[u][v])
        {
            if(!ary[v])
            toposort(v,ary);
        }
    }

    arr.push(u);

}
