#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void display(struct node* str)
{
    printf("\n");
    if(str == NULL)
    {
        printf("   The List is Empty !!");
    }
    else
    {
        while(str != NULL)
        {
            printf("   %d   ",str->data);
            str = str->next;
        }
    }
    printf("\n");
}

struct node* deleteEnd(struct node* head)
{
    struct node* ptr = head;
    struct node* q = head->next;
    while(q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    free(q);
    ptr->next = NULL;
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

    head->data = 1;
    head->next = first;     // the next pointer of the head node pointing to address of 1st node

    first->data = 2;
    first->next = second;

    second->data = 3;
    second->next = third;

    third->data = 4;
    third->next = NULL;

    printf("The linked list is created.\n");
    display(head);

    head = deleteEnd(head);
    head = deleteEnd(head);
    head = deleteEnd(head);
    head = deleteEnd(head);

    printf("\nThe node is Deleted.\n");
    display(head);
}
