#include<iostream>
#include<string>
#include<conio.h>
using namespace std;

int main()
{
    int n,i;
    cout<<"Enter total num of sub";
    cin>>n;
    char arr[300];
    for(i=0;i<n;i++)
    {
    cout<<"Enter the subject"<<(i+1)<<"\n";
    cin>>arr[i];
    }
    cout<<"The name of sub are";
    for(i=0;i<n;i++)
    {
    cout<<arr[i];
    }
    getch();
}