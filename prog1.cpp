#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter total num of sub";
    cin>>n;
    string arr[300];
    for(i=0;i<n;i++)
    {
    cout<<"Enter the name of course"<<(i+1)<<"\n";
    cin>>arr[i];
    }
    cout<<"The name of subjects are";
    for(i=0;i<n;i++)
    {
    cout<<"Courses name"<<(i+1)<<arr[i];
    }
    getch();
}