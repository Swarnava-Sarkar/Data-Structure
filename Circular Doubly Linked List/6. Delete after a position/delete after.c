//Here we will delete a node at beginning in doubly circular linked list
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

Node* delAfter(Node* tail,int pos)
{
    if(tail->next == tail)
    {
        free(tail);
        return NULL;
    }
    else
    {
        Node* temp = tail->next;
        while(pos>1)
        {
            temp = temp->next;
            pos--;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if(temp == tail)
            tail = tail->prev;

        free(temp);

        return tail;
    }
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
    tail = addEnd(tail,20);
    tail = addEnd(tail,30);
    tail = addEnd(tail,40);
    printf("\n---------- List is Created ----------\n");
    display(tail);

    int pos = 3;
    tail = delAfter(tail,pos);
    printf("\n---------- Node at position %d is Deleted ----------\n",pos);
    display(tail);

    return 0;
}
