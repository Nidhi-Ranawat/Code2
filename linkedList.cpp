// LINKED LIST

#include<iostream>
#include<conio.h>
#include<malloc.h>

using namespace std;

struct Node{
    int data;
    struct Node *link;
} *FIRST = NULL, *n1, *n2;         

int main(){

//METHOD-1 using seperate pointers for Each NODE

    FIRST = (Node*)malloc(sizeof(struct Node));
    FIRST -> data = 100;
    FIRST -> link = NULL;

    n1 = (Node*)malloc(sizeof(struct Node));
    n1 -> data = 200;
    n1 -> link = NULL;
    FIRST -> link = n1;

    n2 = (Node*)malloc(sizeof(struct Node));
    n2 -> data = 300;
    n2 -> link = NULL;
    n1 -> link = n2;

    cout<<"\n First -> " <<FIRST ->data <<" -> "<<n1->data<<" -> "<<n2->data<<" -> NULL";

// METHOD-2 Using single pointer (first) to access each NODE

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
    
    cout<<"\n First -> " <<FIRST ->data <<" -> "<<n1->data<<" -> "<<n2->data<<" -> NULL";

// METHOD-3 Printing data within each NODE using LOOP

    struct Node *temp;
    temp = FIRST;
    while(temp != NULL){
        cout<<" \n"<<temp -> data;
        temp = temp->link;
    }
getch();
}  