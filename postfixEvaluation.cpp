#include<stdio.h>
#include<iostream>
#include<conio.h>

using namespace std;
#define SIZE 40

int top = -1;

char EXP[20];
int digit, stack[SIZE];

void push(int data)                             //it will the pushed element and also the value of top after pushing
{
    if (top == SIZE - 1){
        cout << "OVERFLOW!!";                   //if the stack is FULL
        return;
    }
    top++;
    stack[top] = data;
    cout << "\npushed data  = " << data << "  Now top of after pushing = " << top <<"\n";
}

int pop()                                       //it will the popped element and also the value of top after popping
{
    if (top == -1){
        cout << "Now the stack is EMPTY!!";                  //if the STACK is EMPTY
        exit(1);
    }
    int data;
    data = stack[top];
    top--;
    cout << "\npopped data = " << data << "  ";
    cout << "Now top after popping = " << top << "\n";
    return (data);
    
}

int main()
{
    int result, x, n1, n2;
    cout << "Enter the postfix expression to be evaluated:";
    for (int i = -1; i != '\n' ; i++)
    {   cin >> EXP[i];
            
        if (isdigit(EXP[i]))
        {
            cout << "\n\nThe character is : " << EXP[i];
            // cout << "type of digit b4 conversion  " << typeid(EXP[i]).name() << "\n";
            x = (int)EXP[i];                                            // to convert the type of entered char array's digit to int

            //"now type is int of the digit  - x - '0';

            EXP[i] =  (x - '0');                                        //to convert the ASCII value to int

            // cout << "type of digit after conversion  " << typeid(x).name() << "\n";
            push(EXP[i]);
        }
        
        else                                    //operator
        {   
            cout << "\nThe character is : " << EXP[i];
            
            cout << "\nCalculating result of: " << stack[top] << " " << EXP[i] << " " << stack[top-1]  << ", " ;
            char ch = EXP[i];

            if ((stack[top] >= 0)  && (stack[top-1] >= 0) )                 //to perform the operation if there exists 2 operands int the stack
            {
                int x;
                
                switch(ch) 
                {   
                    case '+':
                       { x = stack[top] + stack[top-1];
                        cout << "result = " << x;
                        break;}

                    case '-':
                        {x = stack[top-1] - stack[top];
                        cout << "result =  " << x;
                        break;}

                    case '*':
                        {x =stack[top] * stack[top-1];
                        cout << "result =  " << x;
                        break;}

                    case '/':
                        {x = stack[top-1] /stack[top];
                        cout << "result =  " << x;
                        break;  }
                }
                    //popping the 2 operands and pushing the evaluated result 
                    pop();
                    pop();
                    push (x);
            }       
        }
    }
    cout << "\n\nThe result of the Expression after evaluation = " <<  pop();
}