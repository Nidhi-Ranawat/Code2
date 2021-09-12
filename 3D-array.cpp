// Addition of Two 3-D Arrays

#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
int A[10][10][10], B[10][10][10], C[10][10][10], i,j,k;
int M,N,K;
cout<<"Addition of two 3D arrays \n\n";
cout<<"Enter the DIMENSIONS of 3d arrays you want to form \n";
cin>>M>>N>>K;
cout<<"Total number of elements = "<<M*N*K<<"\n";

cout<<"\nEnter the values in matrix 1 \n";
for(i=0;i<M;i++)
  {
  for(j=0;j<N;j++)
    {
      for(k=0;k<K;k++)
      {
      cin>>A[i][j][k];
      }
    }
  }

cout<<"\nEnter the values in matrix 2 \n";
for(i=0;i<M;i++)
  {
  for(j=0;j<N;j++)
    {
      for(k=0;k<K;k++)
      {
      cin>>B[i][j][k];
      }
    }
  }

cout<<"\nSum of the two 3-D Matrices "<<"\n";
cout<<"{";
for(i=0;i<M;i++)
  {
  for(j=0;j<N;j++)
    {
      for(k=0;k<K;k++)
      {
        C[i][j][k]=A[i][j][k]+B[i][j][k];
          if(k==0){
            cout<<"{";
          }
        cout<<C[i][j][k]<<", ";
          if(k==K-1){
            cout<<"}   ";
          }
        if((j==(N-1))&&(k==(K-1))){
          cout<< "\n";
        }
      }
    }
  }
cout<<"}";
getch();
} 