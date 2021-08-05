// Creating a singly linked circular linked list
// Here we will make a circuler linked list form user input

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* addEmpty(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

Node* addEnd(Node* tail, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = tail->next;
    tail->next = temp;
    tail = temp;
    return tail;
}

Node* creatList(int n)
{
    int data;
    Node* tail;
    if(n == 0)
        return NULL;

    printf("\nEnter the No.1 data ::\t");
    scanf("%d",&data);
    tail = addEmpty(data);

    for(int i=1 ; i<n ; i++)
    {
        printf("\nEnter the No.%d data ::\t",i+1);
        scanf("%d",&data);
        tail = addEnd(tail,data);
    }

    return tail;
}

void display(Node* tail)
{
    if(tail == NULL)
    {
        printf("\nThe List is Empty !!!\n");
    }
    else
    {
        printf("\n-------------Your Circuler Linked List is-------------");
        printf("\n\n");
        Node* ptr = tail->next;
        do
        {
            printf("%d     ",ptr->data);
            ptr = ptr->next;
        }while(ptr != tail->next);
        printf("\n\n");
    }
}

int main()
{
    Node* tail = NULL;
    int n;
    printf("How many Nodes do you want to create ? \n");
    printf("Ans ::\t");
    scanf("%d",&n);
    tail = creatList(n);

    display(tail);
    return 0;
}
