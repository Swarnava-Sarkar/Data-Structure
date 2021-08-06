// Creating a singly linked circular linked list
// Here we will Search a data and print its position

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


int searchList(Node* tail, int data)
{
    int i =1;
    Node* ptr = tail->next;
    do
    {
        if(ptr->data == data)
            return i;
        i++;
        ptr = ptr->next;
    }while(ptr != tail->next);
    return -1;
}

int main()
{
    Node* tail = addEmpty(45);
    tail = addEnd(tail,30);
    tail = addEnd(tail,25);
    tail = addEnd(tail,20);
    printf("---------------Circular Linked List is created---------------");
    display(tail);
    int data = 20;
    int c =  searchList(tail,data);
    if(c == -1)
        printf(":: The Element %d is not found ::\n",data);
    else
        printf(":: The Element %d is found at Position %d ::\n",data,c);

    return 0;
}
