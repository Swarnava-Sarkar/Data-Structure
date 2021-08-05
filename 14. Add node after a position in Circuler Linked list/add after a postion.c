// Creating a singly linked circular linked list
// Here we will add a node after a position

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

Node* addAfter(Node* tail, int data, int pos)
{
    // make the ptr pointer the head
    Node* ptr = tail->next;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    while(pos > 1)
    {
        ptr = ptr->next;
        pos--;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    if(ptr == tail)
    {
        tail = temp;
    }
    return tail;
}

void display(Node* tail)
{
    printf("\n\n");
    Node* ptr = tail->next;
    do
    {
        printf("%d   ",ptr->data);
        ptr = ptr->next;
    }while(ptr != tail->next);
    printf("\n\n");
}

int main()
{
    Node* tail = addEmpty(45);
    tail = addEnd(tail,30);
    tail = addEnd(tail,25);
    printf("---------------Circuler Linked List is created---------------");
    display(tail);
    int pos = 2;
    printf("--------------- Node added after Position \" %d \" ---------------",pos);
    tail = addAfter(tail,20,pos);
    display(tail);
    return 0;
}
