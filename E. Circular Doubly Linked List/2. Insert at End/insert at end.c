//Here we will insert a node at end in doubly circular linked list
#include<stdio.h>
#include<stdlib.h>

// creating the node structure for doubly circular linked list
typedef struct node
{
    struct node* prev;
    int data;
    struct node* next;
}Node;

//create the first node
Node* addEmpty(int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = temp;
    temp->next = temp;

    return temp;
}

//creating a node and adding it at the end
Node* addEnd(Node* tail, int data)
{
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->data = data;

    Node* head = tail->next;
    newN->next = head;
    newN->prev = tail;
    head->prev = newN;
    tail->next = newN;
    tail = newN;

    return tail;
}

void display(Node* tail)
{
    if(tail == NULL)
        printf("\n   :: The List is Empty ::\n");
    else
    {
        Node* temp = tail->next;
        printf("\n\n");
        do
        {
            printf("   %d   ",temp->data);
            temp = temp->next;
        }while(temp != tail->next);
        printf("\n\n");
    }
}


int main()
{
    Node* tail = NULL;
    tail = addEmpty(10);
    printf("\n---------- 1st Node Created ----------\n");
    display(tail);

    tail = addEnd(tail,20);
    printf("\n---------- Next Node Added at End ----------\n");
    display(tail);
}
