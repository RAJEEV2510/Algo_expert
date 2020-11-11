#include<iostream>
#include<algorithm>
using namespace std;
class Edge{
    public:
        int source;
        int dest;
        int weight;
        };
//compare weight
bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;//return true when e1.weight greater
}
//use for findparent
int findparent(int parent [],int v)
{
    if(parent[v]==v)
        return v;
    findparent(parent,parent[v]);
}
//kruskal algorithm
void kruskal(Edge *input ,int n,int E)
{
    sort(input,input+E,compare);//sort all the edges using stl algorithm

    int count=0;
    int j=0;
    Edge *output=NULL;
    output=new Edge[n-1];//output array for result
    //parent array
    int parent[n];
    for(int i=0;i<n;i++)
        parent[i]=i;

    while(count!=(n-1))
    {

            Edge currentEdge=input[j];
            int sourceparent=findparent(parent,currentEdge.source);
            int destparent=findparent(parent,currentEdge.dest);

            if(sourceparent!=destparent)
            {
                output[count]=currentEdge;
                count++;
                parent[currentEdge.dest]= currentEdge.source;

            }

        j++;
    }


    for(int i=0;i<count;i++)
    {
        if(output[i].source<output[i].dest)
        cout<<output[i].source<<"\t"<<output[i].dest<<"\t"<<output[i].weight<<endl;
        else

        cout<<output[i].dest<<"\t"<<output[i].dest<<"\t"<<output[i].weight<<endl;
    }
}




int main()
{
    int n ,E;
    cout<<"Enter the number of vertices and edges\n";
    cin>>n>>E;
    Edge *input=NULL;
    input =new Edge[n];//take input array
    for(int i=0;i<E;i++)
    {
        cout<<"\nenter the edge property\n";
        int source,dest,weight;
        cin>>source>>dest>>weight;
        input[i].source=source;//when pointer treat like array now we can use point otherwise use arrow
        input[i].dest=dest;
        input[i].weight=weight;
    }

    kruskal(input,n,E);

}
