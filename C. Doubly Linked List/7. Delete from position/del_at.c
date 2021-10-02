#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}Node;

void display(Node* head)
{
    Node* ptr = head;
    printf("\nList is :: \n\n");
    if(head == NULL)
        printf("-----Empty-----");
    else
    {
        while(ptr != NULL)
        {
            printf("\t%d",ptr->data);
            ptr = ptr->next;
        }
    }
    printf("\n");
}

Node* addToEmpty(Node* head, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    temp->prev = NULL;
    head = temp;
    return head;
}

Node* addToEnd(Node* head, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;

    Node* ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

Node* creatList()
{
    int n,d;
    Node* head = NULL;
    printf("\nEnter the number of Nodes :: ");
    scanf("%d",&n);
    if(n==0)
        return NULL;
    printf("\n\tEnter the no.1 Data :: ");
    scanf("%d",&d);
    head = addToEmpty(head,d);
    for(int i=2; i<=n ; i++)
    {
        printf("\n\tEnter the no.%d Data :: ",i);
        scanf("%d",&d);
        head = addToEnd(head , d);
    }
    return head;
}

Node* delStart(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node* ptr = head->next;
        free(head);
        ptr->prev = NULL;
        head = ptr;
        return head;
    }
}

Node* delEnd(Node* head)
{
    if(head == NULL)
    {
        return NULL;
    }
    else if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        Node* ptr = head;
        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        return head;
    }
}

Node* delAt(Node* head, int pos)
{
    if(head == NULL)
    {
        return NULL;
    }
    else if(head->next == NULL)
    {
        free(head);
        return NULL;
    }
    else
    {
        if(pos == 1)
        {
            head = delStart(head);
            return head;
        }

        Node* ptr = head;
        while(pos>1)
        {
            ptr = ptr->next;
            pos--;
        }

        if(ptr->next == NULL)
            head = delEnd(head);
        else
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            free(ptr);
        }
        return head;
    }
}


int main()
{
    Node* head = NULL;
    head = creatList();
    display(head);
    printf("\nEnter the position to Delete :: ");
    int pos;
    scanf("%d",&pos);
    head = delAt(head,pos);
    printf("\n---------After Deleting No.%d Node---------\n",pos);
    display(head);

    return 0;
}
