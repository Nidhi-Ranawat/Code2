#include<iostream>
#include<conio.h>
#include<malloc.h>

using namespace std;

struct Node{
    int data;
    struct Node *link;
} *FIRST = NULL, *n1;        

int main(){
 
    FIRST = (Node*)malloc(sizeof(struct Node));
    FIRST -> data = 100;
    FIRST -> link = NULL;

    n1 = (Node*)malloc(sizeof(struct Node));
    n1 -> data = 200;
    n1 -> link = NULL;
    FIRST -> link = n1;

    n1 = (Node*)malloc(sizeof(struct Node));
    n1 -> data = 300;
    n1 -> link = NULL;

    FIRST -> link -> link = n1;
    
    cout << "\nThe linked list - ";
    struct Node *temp;
    temp = FIRST;           
    while(temp != NULL){
        cout<<" \n"<<temp -> data;
        temp = temp->link;                      //updating temp, to point to next node
    }

    // TO INSERT AT THE END POSITION
    int data; Node *ptr, *nn;
    cout << " \nEnter the data of the linked list to be inserted :\n";
    cin >> data;

    ptr = FIRST;
    nn = (struct Node*)malloc(sizeof(struct Node));
    nn -> data = data;
    nn -> link = NULL;

    while(ptr -> link != NULL){                 //traversing the list till END using the ptr pointer
        ptr = ptr -> link;
    }
    ptr -> link = nn;

    cout << "\n\nThe linked list After insertion (at the end)";
      
    temp = FIRST;
    while(temp != NULL){
        cout<<" \n"<<temp -> data;
        temp = temp->link;
    }
}