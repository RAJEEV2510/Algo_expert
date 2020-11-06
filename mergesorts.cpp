#include<fstream>
#include<iostream>
using namespace std;
void mergesort(int mergearray [],int n);
void merging(int leftarray [],int leftlength, int rightarray [],int rightlength,int mergearray []);
int main()
{
    int mergearray[]={5,4,3,2,1,8,6,7};

    mergesort(mergearray,8);
    for(int i=0;i<=7;i++)
    {
        cout<<mergearray[i];
    }

}

void mergesort(int mergearray [],int n)
{



    if(n<2)
        return;


        int mid=n/2;
        int leftarray[mid];
        int rightarray[n-mid];


           for(int i=0;i<mid;i++)
           {
               leftarray[i]=mergearray[i];

           }

         for(int j=mid;j<n;j++)
           {
               rightarray[j-mid]=mergearray[j];

           }


          mergesort(leftarray,mid);
          mergesort(rightarray,n-mid);
          merging(leftarray,mid,rightarray,n-mid,mergearray);




}

void merging(int leftarray [],int leftlength, int rightarray [],int rightlength,int mergearray [])
{



    int i=0;//for left array
    int j=0;//for right array
    int k=0;//for main array
    while(i< leftlength && j<rightlength)
    {
        if(leftarray[i]<rightarray[j])
        {
            mergearray[k]=leftarray[i];
            i++;
            k++;
        }

        else
        {
            mergearray[k]=rightarray[j];
            j++;
            k++;

        }

    }
    while(i<leftlength)
    {
        mergearray[k]=leftarray[i];
        i++;
        k++;
    }

    while(j<rightlength)
    {
          mergearray[k]=rightarray[j];
        j++;
        k++;

    }

}
