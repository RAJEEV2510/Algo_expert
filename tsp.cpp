#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int graph[4][4]={
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };

    int minimum_path=INT_MAX;
    int source=0;
    int k=source;
    vector <int> vertex;
    int i;
    for(i=1;i<=3;i++)
        vertex.push_back(i);


   do{

        int current_path=0;
        for(int i=0;i<3;i++)
        {
            current_path=current_path+graph[k][vertex[i]];

            k=vertex[i];
        }
        current_path=current_path+graph[k][source];

        minimum_path=min(current_path,minimum_path);
    }while(next_permutation(vertex.begin(),vertex.end()));

    cout<<minimum_path;


}



