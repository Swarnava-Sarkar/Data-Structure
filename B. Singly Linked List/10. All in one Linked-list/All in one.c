#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
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
    printf("\n\n");
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

Node* insertAtBeginig(Node* head, int data)
{
    struct node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

Node* insertAtIndex(Node* head, int data,int pos)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    Node* p = head;
    int i = 1;
    while(i<pos-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

Node* insertAtEnd(Node* head, int data)
{
    Node* ptr = (Node*)malloc(sizeof(Node));
    Node* p = head;
    while(p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next=ptr;
    return head;
}

Node* deleteStart(Node* head)
{
    Node* ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

Node* deleteIndex(Node* head, int pos)
{
    Node* ptr = head;
    Node* q = head->next ;
    int i=1;
    while(i<pos-1)
    {
        ptr = ptr->next;
        q = q->next;
        i++;
    }
    ptr->next = q->next;
    free(q);
    return head;
}

Node* deleteEnd(Node* head)
{
    Node* ptr = head;
    Node* q = head->next;
    while(q->next != NULL)
    {
        ptr = ptr->next;
        q = q->next;
    }
    free(q);
    ptr->next = NULL;
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
    while(1)
    {
        printf("\nWhich oparation you wanna do ?\n");
        printf("\t1. Add a Node\n ");
        printf("\t2. Delete a Node\n ");
        printf("\t3. Sort the List\n ");
        printf("\t4. Exit \n ");
        printf("\nChoice :: ");
        int ch1;
        scanf("%d",&ch1);
        switch(ch1)
        {
        case 1:
            printf("\nWhere to add the Node ?\n");
            printf("\t1.At Begining\n");
            printf("\t2.At a Index\n");
            printf("\t3.At End\n");
            printf("\nChoice :: ");
            int ch2;
            scanf("%d",&ch2);
            switch(ch2)
            {
            case 1:
                printf("\nEnter the Element to be inserted :: ");
                int n1st;
                scanf("%d",&n1st);
                head = insertAtBeginig(head, n1st);
                printf("\n-------Updated Linked List-------\n\n");
                display(head);
                break;
            case 2:
                printf("\nEnter the Position :: ");
                int pos;
                scanf("%d",&pos);
                printf("Enter the Element to be inserted :: ");
                int npos;
                scanf("%d",&npos);
                head = insertAtIndex(head, npos,pos);
                printf("\n-------Updated Linked List-------\n\n");
                display(head);
                break;
            case 3:
                printf("\nEnter the Element to be inserted :: ");
                int nend;
                scanf("%d",&nend);
                head = insertAtEnd(head, nend);
                printf("\n-------Updated Linked List-------\n\n");
                display(head);
                break;
            default:
                printf("\nWrong choice try again...\n");
            }
            break;

        case 2:
            printf("\nFrom where to Delete the Node ?\n");
            printf("\t1.From Begining\n");
            printf("\t2.At a Index\n");
            printf("\t3.From End\n");
            printf("\nChoice :: ");
            int ch3;
            scanf("%d",&ch3);
            switch(ch3)
            {
            case 1:
                head = deleteStart(head);
                printf("\n-------Updated Linked List-------\n\n");
                display(head);
                break;
            case 2:
                printf("\nEnter the Position to Delete:: ");
                int delpos;
                scanf("%d",&delpos);
                head = deleteIndex(head,delpos);
                printf("\n-------Updated Linked List-------\n\n");
                display(head);
                break;
            case 3:
                head = deleteEnd(head);
                printf("\n-------Updated Linked List-------\n\n");
                display(head);
                break;
            default:
                printf("\nWrong choice try again...\n");
            }
            break;

        case 3:
            sortList(head);
            printf("\n-------Updated Linked List-------\n\n");
            display(head);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("\nWrong choice try again...\n");
        }
    }
}








