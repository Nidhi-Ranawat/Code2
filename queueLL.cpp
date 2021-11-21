//PROGRAM FOR INSERTION AND DELETIONS OF ELEMENT IN THE QUEUE 
#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
#define SIZE 15

struct Node
{
    int data;
    struct Node *link; 
} *FRONT , *REAR;

//TO INSERT ELEMENTS IN THE QUEUE THROUGH THE REAR END
void enqueue(int val)
{
    struct Node *temp = (Node*)malloc(sizeof(struct Node));         //creating a node
    temp -> data = val;
    temp -> link = NULL;

    if (FRONT == NULL && REAR == NULL)                              //firstnode
    {   
        FRONT = temp;
        REAR = FRONT;
    }

    else                                                                
    {
        REAR -> link = temp;
        REAR = temp;
    }
}

//TO DELETE ELEMENTS IN THE QUEUE FROM THE FRONT END
int dequeue()
{
    int del;
    if (FRONT == NULL && REAR == NULL)
    {
        cout << "The QUEUE is EMPTY!! Deletion not possible.";
        exit(1);
    }
    else
    {   
        del = FRONT -> data;                                         
        FRONT = FRONT -> link;
    }
    return del;
}

//TO DISPLAY THE ELEMENTS IN THE QUEUE FROM FRONT TO REAR NODE
void display()
{
    if (FRONT == NULL && REAR == NULL)                    
    {
        cout << "The QUEUE is EMPTY!!!";
        return;
    }
    
    else
    {
        struct Node *temp = FRONT;
        while(temp!= NULL)
            {
                cout << temp -> data;
                temp = temp -> link;
                cout << "\n";
            }
    }
}

int main()
{
    int ch, val;
    char c;
    do{
        cout << "\nQUEUE OPERATIONS MENU -\n";
        cout << "\n 1)Insert an element in the queue";
        cout << "\n 2)Delete an element from the queue";
    
        cout << "\n\nEnter your choice : ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the value of the element to be inserted in the queue : ";
            cin >> val;
            enqueue(val);
            cout << "\nUsing the enqueue function \nQUEUE IS :-";
            display();
            break;

        case 2:
            cout << "\nDeleting the element from the front..." << endl;
            cout << dequeue() << " is the deleted element ";
            break;
        
        default:
            cout << "\nEnter a valid choice";
            break;
        }
        cout << "\n\nWant to perform more actions? Press y/Y for YES else n/N : ";
        cin >> c;
        if ((c == 'n') || (c == 'N'))
        {
        cout << "\nQUEUE after performing ADDITIONS and DELETIONS :- \n";
        display();
        }
    } while ((c == 'y') || (c == 'Y')); 
}

