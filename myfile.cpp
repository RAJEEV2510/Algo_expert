#include<iostream>
#include<fstream>
using namespace std;
int main()
{

    int arr[100];
    cout<<"Enter your name and age";
    //cin.getline(arr,100);
   // ofstream myfile("xyz.txt");//write in file

   // myfile<<arr;
    ifstream obj("xyz.txt");
    int i=0;
    while(!obj.eof())
    {
        obj>>arr[i];
        i++;
    }
    for(int j=0;j<i;j++)
    {
        cout<<arr[j];
    }

}
