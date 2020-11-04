#include<iostream>
#include<fstream>
using namespace std;
void quicksort(int quick[],int low,int high);
int Dpartition(int quick[],int low,int high);
int main()
{

    cout<<"-------------quick sort program-------------\n";
    int quick[30];
     ifstream obj("xyz.txt");
    int i=0;
    while(!obj.eof())
    {
        obj>>quick[i];
        i++;
    }
    //taking input from users
    int low=0;
    //low index
    int high=i-1;//high index
    //array
    quicksort(quick,low,high);
    //output
      for(int k=low;k<=high;k++)
    {
        cout<<quick[k]<<endl;
    }

}

void quicksort(int quick[],int low,int high)
{


    //partition
    if(low<high)
    {
        int pi=Dpartition(quick,low, high);
        quicksort(quick,low,pi-1);
        quicksort(quick,pi+1,high);
    }
}


int Dpartition(int quick[],int low,int high)
{
    int pivot=high;
    int i=low-1;
    for(int j=low;j<high;j++)
    {
            if(quick[j]<quick[pivot])
            {
                i++;
                swap(quick[i],quick[j]);
            }
    }
    i++;
    swap(quick[i],quick[pivot]);
    return i;
}
