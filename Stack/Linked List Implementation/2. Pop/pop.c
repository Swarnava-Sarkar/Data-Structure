#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* push(Node* head, int data)
{
    printf("\n\t\t\t\t\t\t%d is Pushed\n",data);
    Node* newp = (Node*)malloc(sizeof(Node));
    newp->data = data;
    newp->next = head;
    head = newp;
    return head;
}

Node* pop(Node* head)
{
    if(head == NULL)
    {
        printf("\n\t\t\t\t\t\tNoting can be Poped...\n");
    }
    else
    {
        printf("\n\t\t\t\t\t\t%d is Poped\n",head->data);
        Node* ptr = head;
        head = head->next;
        ptr->next = NULL;
        free(ptr);
    }
    return head;
}

void display(Node* head)
{
    if(head == NULL)
        printf("\n\t\t\t\t\t\t---------Stack is Empty---------\n\n");
    else
    {
        Node* ptr = head;
        printf("\n\t\t\t\t\t\t-----Stack is-----\n\n");
        while(ptr != NULL)
        {
            printf("\t\t\t\t\t\t\t%d\n\n",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int main()
{
    Node* head = NULL;
    int data,ch;
    while(1)
    {
        printf("\nWhat operation do you want to do ?\n\n");
        printf("\t1. PUSH\n");
        printf("\t2. POP\n");
        printf("\t3. Display\n");
        printf("\t4. Exit\n");
        printf("\nPlease enter your choice :: ");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the number to Push :: ");
            scanf("%d",&data);
            head = push(head,data);
            break;

        case 2:
            head = pop(head);
            break;

        case 3:
            display(head);
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
