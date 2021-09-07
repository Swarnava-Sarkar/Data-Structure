//#include<stdio.h>
//#include<stdlib.h>
//
//typedef struct node
//{
//    int data;
//    struct node* next;
//    struct node* prev;
//}Node;
//
//int main()
//{
//    Node* head = (Node*)malloc(sizeof(Node));
//    head->data = 10;
//    head->next = NULL;
//    head->prev = NULL;
//}
////////////////////////////////creating a single node

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

Node* addToStart(Node* head, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;

    temp->next = head;
    head->prev = temp;

    temp->prev = NULL;

    head = temp;
    return head;
}


int main()
{
    Node* head = NULL;
    head = addToEmpty(head,10);
    display(head);
    head = addToStart(head , 20);
    head = addToStart(head , 30);
    head = addToStart(head , 40);
    display(head);

    return 0;
}
