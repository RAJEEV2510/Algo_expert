#include<iostream>
#include<vector>
#include<map>
using namespace std;
map <int,vector <int>> map1;
int j=0;
void subset(int arr[],int l,int r,vector <int> v,int sum=0)
{
    if(l>r)
     {
         vector <int> v1;
         for(auto i=v.begin();i!=v.end();i++)
           v1.push_back(*i);

          map1.insert(make_pair(j,v1));
          j++;
         return;
     }

     //we will include it or not include it
     subset(arr,l+1,r,v,sum);
     //we will include int it
     v.push_back(arr[l]);
     subset(arr,l+1,r ,v,sum+arr[l]);

}

int main()
{
    int arr[]={1,2,5,6,8};
    int l=0;
    int r=4;
    vector <int> v;
    subset(arr,l,r,v);
    int answer=9;

    for(auto i=map1.begin();i!=map1.end();i++)
    {
        if(i->first!=0)
        cout<<i->first<<" - ";

        int sum=0;
        vector <int> v2;
        for (auto k=i->second.begin();k!=i->second.end();k++)
        {
            sum=sum+*k;

        }

            cout<<"\t"<<sum<<"\t";
            if(sum==9)
                for (auto k=i->second.begin();k!=i->second.end();k++)
                    cout<<*k<<",";


        cout<<"\n";
    }

}
