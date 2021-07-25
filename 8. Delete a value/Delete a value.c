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
        printf(" %d \t",str->data);
        str = str->next;
    }
    printf("\n");
}

struct node* deleteVal(struct node* head , int val)
{
    struct node* p = head;
    struct node* q = head->next;
    while(q->data != val && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if(q->data == val)
    {
        p->next = q->next;
        free(q);
    }
    return head;
};

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

    head->data = 17;
    head->next = first;     // the next pointer of the head node pointing to address of 1st node

    first->data = 52;
    first->next = second;

    second->data = 34;
    second->next = third;

    third->data = 41;
    third->next = NULL;

    printf("The linked list is created.\n\n");
    display(head);

    head = deleteVal(head, 34);

    printf("\n\nThe node is Deleted.\n\n");
    display(head);
}
