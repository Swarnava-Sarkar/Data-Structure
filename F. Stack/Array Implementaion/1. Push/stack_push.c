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
        printf("\n\nWhat operation do you want to do ?\n\n");
        printf("\t1. PUSH\n");
        printf("\t2. Display\n");
        printf("\t3. Exit\n");
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
            display();
            break;
        case 3:
            exit(0);
            break;
        default :
            printf("\nWrong Choice try Again....\n\n");
            break;
        }
    }
    return 0;
}
