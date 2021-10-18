//PROGRAM TO IMPLEMENT STACK USING LINKED LISTS (with PUSH & POP operations)
#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

struct Node{
    int data;
    struct Node *link;
} *TOP = NULL;   

//TO DISPLAY STACK ELEMENTS
void display()
{
    struct Node *temp;
    temp = TOP;
    if (TOP == NULL)
    {
        cout << "STACK UNDERFLOW";
        exit(1);
    }
    while(temp != NULL)
    {
        cout << temp -> data;
        temp = temp -> link;
        cout << "\n";
    }
}

//TO INSERT AN ELEMENT IN THE STACK
void push(int data)
{
        struct Node *temp = (Node*)malloc(sizeof(struct Node));
        temp -> data = data;
        temp -> link = NULL;
    
        temp -> link = TOP;
        TOP = temp;
} 

//TO REMOVE THE TOP ELEMENT FROM THE STACK
int pop()
{ 
    struct Node* temp;
    temp = TOP;
    if(TOP == NULL)
    {cout << "STACK UNDERFLOW";
    exit(1);
    }
    int val = temp -> data;
    TOP = TOP -> link;
    free(temp);
    return val;    

}

int main()
{
    int ch, value;
    char c;
    do{
        cout << "STACK OPERATIONS MENU -\n";
        cout << "\n 1)Insert an element in the stack";
        cout << "\n 2)Remove an element from the stack";
        cout << "\n\nEnter your choice" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter the value of the element to be inserted" << endl;
            cin >> value;
            push(value);
            cout << "\nUsing the push function \nSTACK IS - \n";
            display();
            break;

        case 2:
            cout << "\nRemoving the top-most element..." << endl;
            cout << pop() << " is the deleted element ";
            break;
        
        default:
            cout << "\nEnter a valid choice";
            break;
        }
        cout << "\nWant to perform more actions? Press y/Y for YES else n/N : \n";
        cin >> c;
        if ((c == 'n') || (c == 'N'))
        {cout << "\nSTACK after performing INSERTIONS and DELETIONS \n";
        display();
        }
    } while ((c == 'y') || (c == 'Y'));
}