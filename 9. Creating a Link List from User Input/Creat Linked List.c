#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void display(Node* str)
{
    while(str != NULL)
    {
        printf("%d   ",str->data);
        str = str->next;
    }
    printf("\n");
}

Node* creatLinkList(int n)
{
    Node* head = NULL;
    Node* temp = NULL;
    Node* q;
    for(int i=0; i<n ; i++)
    {
         temp = (Node*)malloc(sizeof(Node));            //creating individual node callded temp
         printf("Enter the No.%d Element ::  ",i+1);
         scanf("%d",&(temp->data));                     // temp node data part
         temp->next = NULL;                             // temp next part is null, so node looks like | data->NULL  |

         if(head == NULL)           // if the head is NULL the it is the 1st node
         {
             head = temp;           // making the node  head
         }
         else
         {
             q = head;
             while(q->next != NULL)     //finds the last node whose next is null
             {
                 q = q->next;
             }
             q->next = temp;            // makes the temp as its next node
         }
    }
    return head;
}

int main()
{
    int n;
    printf("Enter the number of Nodes to be created :: ");
    scanf("%d",&n);
    Node* head;      //creating a head node

    head = creatLinkList(n);

    printf("\n-------The linked list is created-------\n\n");
    display(head);

}
