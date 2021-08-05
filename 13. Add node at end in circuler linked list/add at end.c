// Creating a singly linked circular linked list
// Here we will add a node at end

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
    // creating a new node and store the data in the "data" part of the "temp" node
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    //"temp" node's next node will be the tail node's next node
    temp->next = tail->next;
    //now the "temp" node will be the next node of tail
    tail->next = temp;
    //update the tail and make the temp tail
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
    printf("---------------1st Node is created---------------");
    display(tail);

    tail = addEnd(tail,30);

    printf("---------------1 Node added at the End---------------");
    display(tail);

    return 0;
}
