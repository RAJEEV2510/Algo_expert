#include<iostream>
#include<stack>
using namespace std;
int graph[4][4]={
    {0,1,0,0},
    {1,0,0,0},
    {0,0,0,1},
    {0,0,1,0},

};
stack <int> stk;
int main()
{

    bool node[4]={false};

    stk.push(0);
    node[0]=true;
    int   i=0;
    while(!stk.empty())
    {
        int top=stk.top();
        cout<<top<<" ";
        i++;
        stk.pop();

        for(int v=0;v<4;v++)
        {
            if(graph[top][v]==1 && node[v]!=true)
            {
                stk.push(v);
            }

        }

    }

    if(i<4)
    {

        cout<<"This graph is Not connected \n";
    }

    else
    {
        cout<<"connected\n";
    }

}
