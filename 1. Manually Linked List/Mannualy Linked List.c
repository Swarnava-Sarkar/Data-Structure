//BASIC OF LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void display(struct node* str)
{
    while(str != NULL)
    {
        printf("The element is :: %d\n",str->data);
        str = str->next;
    }
}

int main()
{
    struct node* head;
    struct node* first;         // making the struct node type pointers
    struct node* second;
    struct node* third;

    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));      // allocating memory for the nodes
    second = (struct node*)malloc(sizeof(struct node));     // which is equal to one struct node
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 1;
    head->next = first;     // the next pointer of the head node pointing to address of 1st node

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    display(head);
}
