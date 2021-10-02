#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* push(Node* head, int data)
{
    Node* newp = (Node*)malloc(sizeof(Node));
    newp->data = data;
    newp->next = head;
    head = newp;
    return head;
}

void display(Node* head)
{
    if(head == NULL)
        printf("\n---------Stack is Empty---------\n\n");
    else
    {
        Node* ptr = head;
        printf("-----Stack is-----\n\n");
        while(ptr != NULL)
        {
            printf("\t%d\n\n",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    Node* head = NULL;
    int n,data;
    printf("Enter the no of Element to PUSH :: ");
    scanf("%d",&n);

    for(int i=0 ; i<n ; i++)
    {
        printf("\n\tEnter the No.%d data :: ",i+1);
        scanf("%d",&data);
        head = push(head,data);
    }
    display(head);
    return 0;
}
