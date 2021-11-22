//PROGRAM FOR INSERTION AND DELETIONS OF ELEMENT IN THE QUEUE 
#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
#define SIZE 3

int CQUEUE[SIZE];
int front = -1, rear = -1;

//TO INSERT ELEMENTS IN THE QUEUE THROUGH THE REAR END
void enqueue(int val)
{
    if ((rear == (SIZE - 1)) && (front == 0) || (rear == (front - 1)))                     //to check if the QUEUE is full
    {
        cout << "The QUEUE is FULL!! Addition not possible.";
        exit(1);
    }

    if ( front == -1 && rear == -1)                                                        //insertion of first element
        front = rear = 0;
  
    else if (rear == (SIZE-1))                                                             //when reaches the end of the CIRCULAR queue
        rear = 0;

    else
        rear++;

    CQUEUE [rear] = val;
}

//TO DELETE ELEMENTS IN THE QUEUE FROM THE FRONT END
int dequeue()
{
    int del = 0;
    
    if (front == -1 && rear == -1)                                                         //if the QUEUE is EMPTY
    {
        cout << "The QUEUE is EMPTY!! Deletion not possible.";
        exit(1);
    }

    del = CQUEUE[front];                                                                    //value of deleted front element

    if ((front == 0 && rear == 0) || (front == (SIZE - 1) && rear == (SIZE-1)))            //if only single element exists
        front = rear = -1;

    if(front == (SIZE - 1))                                                                 
        front = 0;

    else
        front++;
    
    return del ;
}

//TO DISPLAY THE ELEMENTS IN THE QUEUE FROM FRONT TO REAR END
void cirQueue()
{
    if (front == -1 && rear == -1)                                                          //if the QUEUE is EMPTY
    {
        cout << "The QUEUE is EMPTY!!!";
        return;
    }

    if (front <= rear)                                                                     
    {
        for (int i = front; i <= rear; i++)
        cout << CQUEUE[i] << "\t";
    }

    else  if (front >= rear)
    {
        int i = front;
        while ( i <= (SIZE - 1))
        {
            cout << CQUEUE[i] << "\t";
            i++;
        }
        i = 0;                                                                              //starting from the front position
        while ( i <= rear)                                                                  //till rear
        {
            cout << CQUEUE[i] << "\t"; 
            i++; 
        }        
    }
}

int main()
{
    int ch, val;
    char c;
    do{
        cout << "\nCIRCULAR QUEUE OPERATIONS MENU -\n";
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
            cirQueue();
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
        cout << "\nCIRCULAR QUEUE after performing ADDITIONS and DELETIONS :- \n";
        cirQueue();
        }
    } while ((c == 'y') || (c == 'Y')); 
}

