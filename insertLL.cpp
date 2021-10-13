/* PROGRAM TO INSERT NODES AT THE GIVEN POSITIONS AS LONG AS THE USER WISHES TO */

#include<iostream>
#include<conio.h>
#include<malloc.h>

using namespace std;

struct Node{
    int data;
    struct Node *link;
} *FIRST = NULL, *n1; 

void display()
    {
    struct Node *temp;
    temp = FIRST;
            while(temp != NULL){
                cout<<" \n"<<temp -> data;
                temp = temp->link;
            }
    }

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
    display();

char ch;
int t = 4;

do{
    int pos, data;
    Node *nn;

    do {
        cout <<"\n\nEnter the Position where the new NODE is to be inserted\n";
        cin >> pos;
        if (pos > t || (pos <= 0))
        cout<<"\nThe position should not be greater than "<< t <<" and not 0!!!";
    }
    while(pos > t || (pos == 0));

    cout << "\nEnter the DATA of the linked list\n";
    cin >> data;

    nn = (struct Node*)malloc(sizeof(struct Node));                     //creating the node
    nn -> data = data;
    nn -> link = NULL;

    // TO INSERT THE NODE AT GIVEN POSITION

    Node *ptr;
    ptr = FIRST;
    if(pos == 1)                                                         //if the node is to be inserted at first position
        {
        	nn -> link = ptr;
    		FIRST = nn;

            cout << "\n\nThe linked list After insertion at position " << pos <<" :\n";
            display();
    	}

    else{
            for (int i = 1; i < pos-1; i++){
            ptr = ptr -> link;
            }
            nn -> link = ptr -> link;
            ptr -> link = nn;
            cout << "\n\nThe linked list After insertion at position " << pos <<":\n";
            display();
        }
    t++;
    cout << "\n\nWant to enter more nodes. Press y/Y for YES else n/N : \n";
    cin >> ch;
    if ((ch == 'n') || (ch == 'N'))
    exit(0);

} while ((ch == 'y') || (ch == 'Y')); 
}
