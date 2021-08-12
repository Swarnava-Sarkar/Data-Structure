#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* addnext(Node* head, int data)
{
    Node* newp = (Node*)malloc(sizeof(Node));
    newp->data = data;
    newp->next = NULL;

    if(head == NULL || data<head->data)
    {
        newp->next = head;
        head = newp;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL && temp->next->data < data)
            temp = temp->next;
        newp->next = temp->next;
        temp->next = newp;
    }
    return head;
}

void display(Node* head)
{
    if(head == NULL)
        printf("No list Found !!");
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            printf(" %d ",temp->data);
            temp = temp->next;
            if(temp != NULL)
                printf(",");
        }
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;
    int n;
    int ch = 1;
    while(1)
    {
        printf("\nEnter the data :: ");
        scanf("%d", &n);
        head = addnext(head,n);

        printf("\nDo you want to continue ? (1 for YES / 0 for NO) :: ");
        scanf("%d",&ch);

        if(ch == 0)
            break;
    }
    printf("\n--------------------------------------------------------\n");
    printf("\n Your List is ::    ");
    display(head);
    return 0;
}
