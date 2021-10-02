// Creating a singly linked circular linked list
// Here we will make a single node whose "next" will point to itself

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}Node;

Node* addEmpty(int data)
{
    //creating a struct node called "temp" and allocating memory in heap
    Node* temp = (Node*)malloc(sizeof(Node));

    //assingning the data in the "data" part of the "temp" node
    temp->data = data;
    //the "next" part will point to itself i.e. "temp"
    temp->next = temp;
    return temp;
}

void display(Node* tail)
{
    printf("\n\n");
    // creating a pointer that points tail's next node i.e head
    Node* ptr = tail->next;
    do
    {
        printf("%d   ",ptr->data);
        // moving the pointer to its next node
        ptr = ptr->next;
    }while(ptr->next != tail->next);
    printf("\n\n");
}

int main()
{
    Node* tail = addEmpty(45);
    display(tail);
    return 0;
}
