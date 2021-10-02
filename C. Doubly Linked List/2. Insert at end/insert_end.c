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


int main()
{
    Node* head = NULL;
    head = addToEmpty(head,10);
    display(head);
    head = addToEnd(head , 20);
    head = addToEnd(head , 30);
    head = addToEnd(head , 40);
    display(head);

    return 0;
}
