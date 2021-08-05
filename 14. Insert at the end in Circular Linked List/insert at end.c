//CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void display(Node* head)
{
    Node* ptr = head;
    printf("\n\n");
    do
    {
        printf("%d   ",ptr->data);
        ptr = ptr->next;
    }while(ptr!=head);
    printf("\n\n");
}

Node* insertEnd(Node* head , int data)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;

    Node* p = head;
    do
    {
        p=p->next;
    }while(p->next!=head);

    ptr->next = head;
    p->next = ptr;

    return head;
}

int main()
{
    Node* head;
    Node* first;         // making the struct node type pointers
    Node* second;
    Node* third;

    head = (Node*)malloc(sizeof(Node));
    first = (Node*)malloc(sizeof(Node));      // allocating memory for the nodes
    second = (Node*)malloc(sizeof(Node));     // which is equal to one struct node
    third = (Node*)malloc(sizeof(Node));

    head->data = 1;
    head->next = first;     // the next pointer of the head node pointing to address of 1st node

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = head;     // linking the last node with the first node

    printf("------- The Circular Linked-List is -------");
    display(head);

    head = insertEnd(head,30);

    printf("------- Node Inserted -------");
    display(head);
}
