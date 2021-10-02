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

        printf("\n\tEnter the Coefficient :: ");
        scanf("%f",&cof);

        printf("\n\tEnter the Exponent :: ");
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

Node* polyMul(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head3 = NULL;
    int res1, res2;

    while(ptr1 != NULL)
    {
        ptr2 = head2;
        while(ptr2 != NULL)
        {
            res1 = ptr1->cof * ptr2->cof;
            res2 = ptr1->exp + ptr2->exp;
            head3 = addnext(head3,res1,res2);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return head3;
}

Node* normal(Node* head)
{
    Node* ptr = head;
    Node* temp = NULL;

    while(ptr->next != NULL)
    {
        if(ptr->exp == ptr->next->exp)
        {
            ptr->cof = ptr->cof + ptr->next->cof;
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp); temp=NULL;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return head;
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

    head3 = polyMul(head1,head2);
    head3 = normal(head3);
    printf("\n\nAfter Multiplication ::\t");
    display(head3);
    return 0;
}
