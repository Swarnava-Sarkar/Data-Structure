#include<stdio.h>
#include<stdlib.h>
#define MAX 50

int top=-1;
int stack[MAX];

int isFull()
{
    if(top == MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty()
{
    if(top == -1)
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
        top++;
        stack[top] = data;
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
        data = stack[top];
        top--;
        return data;
    }
}

void prime_fact(int num)
{
    int i=2;
    while(num != 1)
    {
        while(num % i == 0)
        {
            push(i); //if factor then push
            num = num/i;
        }
        i++;
    }
    // for printing
    printf("\nThe Prime factors are :: ");
    while(top != -1)
    {
        printf("%d  ",pop());
    }
    printf("\n");
}


void display()
{
    if(isEmpty())
        printf("\n--------------The Stack is Empty!!!--------------\n");
    else
    {
        printf("\n----The Stack is----\n\n");
        for(int i=top ; i>=0; i--)
            printf("\t%d\n\n",stack[i]);
        printf("\n\n");
    }
}

int main()
{
    int data;
    printf("Enter the number :: ");
    scanf("%d",&data);
    prime_fact(data);
    return 0;
}
