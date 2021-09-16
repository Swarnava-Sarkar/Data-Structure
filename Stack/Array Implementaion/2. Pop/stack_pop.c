#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int top=-1;
int stack[MAX];

void push(int data)
{
    if(top == MAX-1)
        printf("\n--------------The Stack is Full!!!--------------\n");
    else
    {
        top++;
        stack[top] = data;
        printf("\n--------%d is Pushed Successfully--------\n",data);
    }
}

void pop()
{
    if(top == -1)
        printf("\n--------------The Stack is Empty!!!--------------\n");
    else
    {
        printf("\n--------%d is Poped Successfully--------\n",stack[top]);
        top--;
    }
}

void display()
{
    printf("\n----The Stack is----\n\n");
    for(int i=top ; i>=0; i--)
        printf("\t%d\n\n",stack[i]);
    printf("\n\n");
}

int main()
{
    int data,ch;
    while(1)
    {
        printf("\nWhat operation do you want to do ?\n\n");
        printf("\t1. PUSH\n");
        printf("\t2. POP\n");
        printf("\t3. Display\n");
        printf("\t4. Exit\n");
        printf("\nAns :: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the number to Push :: ");
            scanf("%d",&data);
            push(data);
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            exit(0);
            break;

        default :
            printf("\nWrong Choice try Again....\n\n");
            break;
        }
    }
    return 0;
}
