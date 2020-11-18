#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int partion(int arr[],int low,int high)
{
    int i=low-1;
    int pivot=arr[high];
    for(int j=low;j<=high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
        i++;
        swap(arr[i],arr[high]);

    return i;
}
void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partion(arr,low,high);

        quicksort(arr,low,pi-1);///left

        quicksort(arr,pi+1,high);///right
    }
}
int main()
{

    int arr[5];
    srand(time(0));
    for(int i=0;i<5;i++)
        arr[i]=rand();
    int low=0;
    int high=4;
    quicksort(arr,low,high);
    for(int i=low;i<=high;i++)
    cout<<arr[i]<<endl;
}
