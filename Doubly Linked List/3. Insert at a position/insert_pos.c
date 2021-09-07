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
    while(ptr != NULL)
    {
        printf("%d   ",ptr->data);
        ptr = ptr->next;
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

Node* addToPos(Node* head, int data, int pos)
{
    Node* newp = (Node*)malloc(sizeof(Node));
    newp->data = data;
    newp->prev = NULL;
    newp->next = NULL;

    Node* ptr1 = head;
    while(pos !=1)
    {
        ptr1 = ptr1->next;
        pos--;
    }
    if(ptr1->next == NULL)
    {
        newp->prev = ptr1;
        ptr1->next = newp;
    }
    else
    {
        Node* ptr2 = ptr1->next;
        ptr1->next = newp;
        ptr2->prev = newp;
        newp->prev = ptr1;
        newp->next = ptr2;
    }
    return head;
}


int main()
{
    Node* head = NULL;
    head = addToEmpty(head,10);
    head = addToEnd(head , 20);
    head = addToEnd(head , 30);
    head = addToEnd(head , 40);
    display(head);

    head = addToPos(head,100,3);
    display(head);

    return 0;
}
