// Creating a singly linked circular linked list
// Here we will Count the number of node

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


int count(Node* tail)
{
    int i =0;
    Node* ptr = tail->next;
    do
    {
        i++;
        ptr = ptr->next;
    }while(ptr != tail->next);
    return i;
}

int main()
{
    Node* tail = addEmpty(45);
    tail = addEnd(tail,30);
    tail = addEnd(tail,25);
    tail = addEnd(tail,20);
    printf("---------------Circular Linked List is created---------------");
    display(tail);

    int c =  count(tail);
    printf("The number of Node is ::   %d\n",c);

    return 0;
}
