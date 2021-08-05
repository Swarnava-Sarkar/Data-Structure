// Creating a singly linked circular linked list
// Here we will Delete a node after a node

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

Node* delAfter(Node* tail, int pos)
{
    Node* temp = tail->next;
    Node* p = tail;
    while(pos > 1)
    {
        p = p->next;
        temp = temp->next;
        pos--;
    }
    if(temp == tail)
        tail = p;
    p->next = temp->next;
    free(temp);
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
    tail = addEnd(tail,15);
    printf("---------------Circuler Linked List is created---------------");
    display(tail);
    int pos = 2;
    tail = delAfter(tail,pos);
    printf("--------------- No.%d Node Deleted ---------------",pos);
    display(tail);

    return 0;
}
