#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    float cof;      // coefficient of the a term
    int exp;        // exponent of the term
    struct node* next;
}Node;

Node* addnext(Node* head, float cof, int exp)
{
    Node* newp = (Node*)malloc(sizeof(Node));
    newp->cof = cof;
    newp->exp = exp;
    newp->next = NULL;

    if(head == NULL || exp>head->exp)
    {
        newp->next = head;
        head = newp;
    }
    else
    {
        Node* temp = head;
        while(temp->next != NULL && temp->next->exp > exp) // move temp until last or until its next node's exp become small
            temp = temp->next;
        newp->next = temp->next;
        temp->next = newp;
    }
    return head;
}

Node* creat(Node* head)
{
    int n;
    float cof;
    int exp;
    printf("\nEnter the Number of terms in the Polynomial :: ");
    scanf("%d",&n);
    for(int i=0; i<n ; i++)
    {
        printf("\n\t----- For the %d term -----\n",i+1);

        printf("\n\t\tEnter the Coefficient :: ");
        scanf("%f",&cof);

        printf("\n\t\tEnter the Exponent :: ");
        scanf("%d",&exp);

        head = addnext(head,cof,exp);
    }
    return head;
}

void display(Node* head)
{
    if(head == NULL)
        printf("No Polynomial Found !!");
    else
    {
        Node* temp = head;
        while(temp != NULL)
        {
            printf(" ( %.1f x ^ %d ) ",temp->cof,temp->exp);
            temp = temp->next;
            if(temp != NULL)
                printf("+");
        }
    }
    printf("\n");
}

Node* polyAdd(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head3 = NULL;

    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->exp == ptr2->exp)
        {
            head3 = addnext(head3, (ptr1->cof + ptr2->cof) , ptr1->exp);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->exp > ptr2->exp)
        {
            head3 = addnext(head3, ptr1->cof, ptr1->exp);
            ptr1 = ptr1->next;
        }
        else if(ptr1->exp < ptr2->exp)
        {
            head3 = addnext(head3, ptr2->cof, ptr2->exp);
            ptr2 = ptr2->next;
        }
    }
    while(ptr1 != NULL)
    {
        head3 = addnext(head3, ptr1->cof, ptr1->exp);
        ptr1 = ptr1->next;
    }
    while(ptr2 != NULL)
    {
        head3 = addnext(head3, ptr2->cof, ptr2->exp);
        ptr2 = ptr2->next;
    }
    return head3;
}

int main()
{
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;
    printf("\nEnter the 1st Polynomial --->\n");
    head1 = creat(head1);
    printf("\nEnter the 2nd Polynomial --->\n");
    head2 = creat(head2);

    printf("\n--------------------------------------------------------------------\n");
    printf("\n1st Polynomial is ::\t");
    display(head1);
    printf("\n2nd Polynomial is ::\t");
    display(head2);

    head3 = polyAdd(head1,head2);
    printf("\n\nAfter Addition   ::\t");
    display(head3);
    return 0;
}
