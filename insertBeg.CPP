//Program to INSERT a node at the BEGINNING of the linked list
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

    // TO INSERT AT FIRST POSITION
    struct Node *new1;
    new1 = new Node;
    if(FIRST == NULL){
        new1 -> data = 50;
        new1 -> link = NULL;
    }
    new1 -> data = 50;
    new1 -> link = FIRST;
    FIRST = new1;
    cout << "\n\nThe linked list After insertion (on first position)";
      
    temp = FIRST;
    while(temp != NULL){
        cout<<" \n"<<temp -> data;
        temp = temp->link;
    }
}