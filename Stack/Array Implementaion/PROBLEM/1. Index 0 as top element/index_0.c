#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int first = -1;
int top=-1;
int stack[MAX];

int isFull()
{
    if(first == MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(first == -1)
        return 1;
    else
        return 0;
}

void push(int data)
{
    if(isFull())
        printf("\n--------------The Stack is Full!!!--------------\n");
    else
    {
        first++; //1st element changes
        for(int i=first ; i>0 ; i--) //shifting element
            stack[i] = stack[i-1];
        stack[0] = data; //pushing data in top i.e. 0
        printf("\n--------%d is Pushed Successfully--------\n",data);
    }
}

int pop()
{
    int data;
    if(isEmpty())
    {
        printf("\n--------------The Stack is Empty!!!--------------\n");
        return 0;
    }
    else
    {
        data = stack[0];  // as 0 is top element
        printf("\n--------%d is Poped Successfully--------\n",data);
        for(int i=1 ; i<=first ; i++) //moving data left
            stack[i-1] = stack[i];
        first--;
        return data;
    }
}

int popData()
{
    int data;
    if(isEmpty())
    {
        printf("\n--------------No Top Data Available--------------\n");
        return 0;
    }
    else
    {
        return stack[0];
    }
}

void display()
{
    if(isEmpty())
        printf("\n--------------The Stack is Empty!!!--------------\n");
    else
    {
        printf("\n----The Stack is----\n\n");
        for(int i=0 ; i<=first; i++)
            printf("\t%d\n\n",stack[i]);
        printf("\n\n");
    }
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
        printf("\t4. Print The Top Element\n");
        printf("\t5. Exit\n");
        printf("\nPlease enter your choice :: ");
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
            data = popData();
            printf("\nThe Top Element is :: %d\n",data);
            break;

        case 5:
            exit(0);
            break;

        default :
            printf("\nWrong Choice try Again....\n\n");
            break;
        }
    }
    return 0;
}
