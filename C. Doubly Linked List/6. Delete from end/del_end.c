#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}Node;

void display(Node* head)
{
    Node* ptr = head;
    printf("\nList is :: \n\n");
    if(head == NULL)
        printf("-----Empty-----");
    else
    {
        while(ptr != NULL)
        {
            printf("\t%d",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

Node* addToEmpty(Node* head, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    return head;
}

Node* addToEnd(Node* head, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    Node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

Node* creatList()
{
    int n,d;
    Node* head = NULL;
    printf("\nEnter the number of Nodes :: ");
    scanf("%d",&n);
    if(n==0)
        return NULL;
    printf("\n\tEnter the no.1 Data :: ");
    scanf("%d",&d);
    head = addToEmpty(head,d);
    for(int i=2; i<=n ; i++)
    {
        printf("\n\tEnter the no.%d Data :: ",i);
        scanf("%d",&d);
        head = addToEnd(head , d);
    }
    return head;
}

Node* delEnd(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node* ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        return head;
    }
}


int main()
{
    Node* head = NULL;
    head = creatList();
    display(head);

    head = delEnd(head);
    printf("\n---------After Deleting the Last Node---------\n");
    display(head);

    return 0;
}
