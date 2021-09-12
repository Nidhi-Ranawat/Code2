// 2-D Matrix Calculator where user chooses the operation to be performed

#include<iostream>
#include<conio.h>

using namespace std;
int main()
{
int m,n,i,j,k,mat[5][5], mat1[5][5], mat2[5][5], mat3[5][5],flag;  
char ans;   
do{  
cout<<"\n Enter Your choice";
cout<<"\n 1) Addition \n 2) Subtraction \n 3) Multiplication \n of two 2-D matrix: ";
cin>>k;
if(k==1||k==2)
{
	cout<<"Enter the number of rows and col of matrices (square matrices): ";      
    cin>>m>>n;
	cout<<"/n Enter the elements of matrix 1" ;
	for(i = 0; i < m; i++)
        {
        for(j = 0; j < n; j++)
        cin>>mat1[i][j];
        }
    cout<<"/n Enter the elements of 2 matrix" ;
    for(i = 0; i < m; i++)
        {
        for(j = 0; j < n; j++)
        cin>>mat2[i][j];
        }
}
switch(k)
{

    case 1:
        for(i = 0; i < m; i++)
            {
            for(j = 0; j < n; j++)
                {
                mat3[i][j] = mat1[i][j] + mat2[i][j];
                }
            }
        cout<<"After addition: \n";
        for(i = 0; i < m; i++)
            {
            for(j = 0; j < n; j++){
                cout<<mat3[i][j]<<" ";
                if(j==(n-1))
                cout<<"\n";
                }
            }
        break;

    case 2:
        for(i = 0; i < m; i++)
            {
            for(j = 0; j < n; j++)
                {
                mat3[i][j] = mat1[i][j] - mat2[i][j];
                }
            }
        cout<<"After subtraction: \n";
            for(i = 0; i < m; i++)
            {
                for(j = 0; j < n; j++){
                cout<<mat3[i][j]<<" ";
                  if(j==(n-1))
                cout<<"\n";
                }
            }
        break;

    case 3:
        int r1, c1, r2, c2;
        cout<<"Enter number of rows and columns of first matrix: ";
        cin>>r1>>c1;
        cout << "Enter number ofrows and columns of second matrix: ";
        cin>>r2>>c2;
        // If column of first matrix in not equal to row of second matrix
        while (c1!=r2)
        {
            cout<<"Error! column of first matrix not equal to row of second.";

            cout<<"Enter rows and columns for first matrix: ";
            cin>>r1>>c1;
            cout<<"Enter rows and columns for second matrix: ";
            cin>>r2>>c2;
        }

        cout << endl<< "Enter elements of matrix 1:"<<endl;
        for(i = 0; i < r1; ++i)
            for(j = 0; j < c1; ++j)
            {
                cin>>mat1[i][j];
            }

        cout << endl<< "Enter elements of matrix 2:"<<endl;
        for(i = 0; i < r2; ++i)
            for(j = 0; j < c2; ++j)
            {
                cin>>mat2[i][j];
            }

        for(i = 0; i < r1; ++i)
            for(j = 0; j < c2; ++j)
            {
                mat3[i][j]=0;
            }

        for(i = 0; i < r1; ++i)
            for(j = 0; j < c2; ++j)
                for(k = 0; k < c1; ++k)
                {
                    mat3[i][j]+=mat1[i][k]*mat2[k][j];
                }

        cout << endl << "After multiplication of 2 matrices: " << endl;
        for(i = 0; i < r1; ++i){
            for(j = 0; j < c2; ++j)
            {
                cout<<mat3[i][j]<<" ";
                if(j==c2-1)
                    cout<<"\n";
            }
        }
        break;  
        default: cout<<"You entered wrong choice ";
        break;
}
cout<<"Want to enter more: y/n";
cin>>ans;
}
while(ans=='y'||ans=='Y');
if(ans=='n')
exit(0);
getch();
}