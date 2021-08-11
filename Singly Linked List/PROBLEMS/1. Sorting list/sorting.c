#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void display(Node* str)
{
    printf("\n");
    while(str != NULL)
    {
        printf("   %d   ",str->data);
        str = str->next;
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

void sortList(Node* head)
{
    Node* i;
    Node* j;
    int temp;
    for(i = head ; i!=NULL ; i=i->next)
    {
        for(j = i->next ; j!=NULL ; j=j->next)
        {
            if(j->data < i->data)
            {
                temp = j->data;
                j->data = i->data;
                i->data = temp;
            }
        }
    }
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

    sortList(head);
    printf("\n ----------List is Sorted----------\n");
    display(head);
    return 0;
}
