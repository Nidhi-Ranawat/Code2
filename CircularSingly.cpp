//CIRCULAR SINGLY LINKED LIST WITH THE NODES AS PER THE USER
#include<iostream>
#include<conio.h>
#include<malloc.h>

using namespace std;

struct Node{
    int data;
    struct Node *link;
} *LAST, *FIRST;  

struct Node *addNode(int d1)
{
    FIRST = (Node*)malloc(sizeof(struct Node));        //first node
    FIRST -> data = d1;
    FIRST -> link = FIRST;
    return FIRST;
}

struct Node *lastNode(struct Node* last, int data)
{
    LAST = (Node*)malloc(sizeof(struct Node)); 
    LAST -> data = data;
    LAST -> link = NULL;

    LAST -> link = last -> link;
    last -> link = LAST;
    last = last -> link;
    return last;
} 

struct Node *theList(struct Node* last)
{
    int i, n, d1;
    cout << "Enter the number of nodes\n";
    cin >> n;

    if(n == 0)
    {cout << "NULL";
    }
    cout << "Enter the data of FIRST node\n";
    cin >> d1;
    last = addNode(d1);
    int d[10];
      for(int i = 1; i < n; i++)
        {
            cout << "Enter the data of node " << i+1 <<"\n";
            cin >> d[i];
            last = lastNode(last, d[i]);
        }
    return last;
}

    void display(struct Node* last)
    {
        if(last == NULL)
        cout << "NULL";
        else{
            struct Node* n = last -> link;
            do{
                cout << n -> data;
                n = n -> link;
            }
            while(n!= (last -> link));
            cout << "\n";
        }
    }

int main()
{
    struct Node* last = NULL;
    last = theList(last);
    display(last);
}