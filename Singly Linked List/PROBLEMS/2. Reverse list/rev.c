#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void display(Node* str)
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

Node* addEmpty(int data)
{
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;

    return head;
}

Node* addEnd(Node* head, int data)
{
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->data = data;
    newN->next = NULL;

    Node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newN;

    return head;
}

Node* revList(Node* head)
{
    Node* temp1 = NULL;
    Node* temp2 = NULL;
    while(head != NULL)
    {
        temp2 = head->next;
        head->next = temp1;
        temp1 = head;
        head = temp2;
    }
    head = temp1;
    return head;
}

int main()
{
    Node* head = addEmpty(10);
    head = addEnd(head,50);
    head = addEnd(head,40);
    head = addEnd(head,30);
    head = addEnd(head,20);
    printf("\n ----------List is created----------\n");
    display(head);

    head = revList(head);
    printf("\n ----------List is Reversed----------\n");
    display(head);
    return 0;
}
