//MENU DRIVEN TREE PROGRAM
#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;

struct treeNode
{
    treeNode *left;
    treeNode *right;
    int data;
} *ROOT = NULL, *temp;

void insertTreeNode(int data)
{
    treeNode *Node = new treeNode();
    Node -> data = data;
    Node -> left = NULL;
    Node -> right = NULL;

    if (ROOT == NULL)                           //if the tree is empty 
        ROOT = Node;                            //root node

    else 
    {
        temp = ROOT;                            //to traverse tree using temp
        int x = temp -> data;
        int y = data;
        while (temp != NULL)
        {
            if ( x == y )
            {
                cout <<"DATA already exists!";
                return;
            }

            else if ((data < temp -> data) && (temp -> left == NULL))           //data belonging to left subtree
                temp -> left = Node;
            
            else if (data < temp -> data)                                       //if root already has a left child
                temp = temp -> left;                                            //then going to next left child
            
            else if ((data > temp -> data) && (temp -> right == NULL))          //data belonging to right subtree
                temp -> right = Node;                                           
            
            else
                temp = temp -> right;                                           //if root already has a right child
        }
    }
}

void preOrder(treeNode *root)         //Root Left Right
{
    if (root == NULL)
    return;
    cout << root-> data << "\t";
    preOrder ( root -> left);         //recursive function
    preOrder ( root -> right);
}

void InOrder(treeNode *root)          //Left Root Right
{
    if (root == NULL)
    return;
    InOrder ( root -> left);
    cout << root-> data << "\t";
    InOrder ( root -> right);
}

void postOrder(treeNode *root)         //Left Right Root
{
    if (root == NULL)
    return;
    postOrder ( root -> left);
    postOrder ( root -> right);
    cout << root -> data << "\t";
}

treeNode* deleteTreeNode(int data, treeNode *root)
{
    if ( root == NULL )
    {
        cout << "The TREE is EMPTY!!";
        return root;
    }
        //if the data to be deleted is less than then the parent node
        if ( data < root -> data)           
        root -> left = deleteTreeNode ( data, root -> left);

        else if ( data > root -> data)
        root -> right = deleteTreeNode ( data, root -> right);
        // till here the instructions were to reach the node to be deleted
    else
    {
        //else part if the data matches the value of a node, it's to be deleted 
        struct treeNode* node;

        if ( root -> left == NULL )     //node with single child (right child)
        {
            node = root -> right;
            return node;                
        }
        else if ( root -> right == NULL)
        {
            node = root -> left;
            return node;
        }

        else                                //node with two children
        {
            struct treeNode *n;
            n = root -> right;              // to enter left subtree
            while ( n -> left != NULL)
               n = n -> left;               //to traverse till the node with minimum value
            root -> data = n -> data; 
            root -> right = deleteTreeNode ( n -> data, root -> right);             //deleting the node with min value from current pos
        }
    }
    return root;
}

int main ()
{
    int ch, data, del;
    char c;
    do
    {
        cout << "TREE OPERATIONS MENU -\n";
        cout << "\n 1)INSERT a NODE in the tree";
        cout << "\n 2)REMOVE a NODE from the tree";
        cout << "\n 3)DISPLAY Nodes of the TREE";
        cout << "\n\nEnter your choice" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "\nEnter the value of the element to be inserted" << endl;
            cin >> data;
            insertTreeNode(data);
            break;

        case 2:
            cout << "Enter the value of the node to be deleted" << endl;
            cin >> del;
            deleteTreeNode(del, ROOT);
            break;
        
        case 3:
            cout << "\nTREE ELEMENTS AS FOLLOWS- " << endl;
            cout << "\n a)Inorder : \t";
            InOrder(ROOT);
            cout << "\n b)Preorder : \t";
            preOrder(ROOT);
            cout << "\n c)Postorder : \t";
            postOrder(ROOT);
            break;

        default:
            cout << "\nEnter a valid choice";
            break;
        }
        cout << "\n\nWant to perform more actions? Press y/Y for YES else n/N : \n";
        cin >> c;
        if ((c == 'n') || (c == 'N'))
        exit (0);
    }
    while ((c == 'y') || (c == 'Y')); 
}