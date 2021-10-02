// Creating a singly linked circular linked list
// Here we will Delete a node form end

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

Node* delEnd(Node* tail)
{
    Node* temp = tail->next;
    while(temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
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

int main()
{
    Node* tail = addEmpty(45);
    tail = addEnd(tail,30);
    tail = addEnd(tail,25);
    tail = addEnd(tail,20);
    printf("---------------Circuler Linked List is created---------------");
    display(tail);

    tail = delEnd(tail);
    printf("--------------- Last Node Deleted ---------------");
    display(tail);

    return 0;
}
