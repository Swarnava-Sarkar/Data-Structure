#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void display(Node* head)
{
    Node* str = head;
    if(head == NULL)
        printf("\nNo Number !!\n");
    else
    {
        while(str != NULL)
        {
            printf("   %d   ",str->data);
            str = str->next;
        }
        printf("\n");
    }
}

Node* addNext(Node* head, int data)
{
    Node* newN = (Node*)malloc(sizeof(Node));
    newN->data = data;
    newN->next = head;
    head = newN;

    return head;
}

Node* digNode(Node* head, int num)
{
    while(num != 0)
    {
        head = addNext(head, num%10);
        num = num/10;
    }
    return head;
}

Node* revList(Node* head)
{
    Node* current = NULL;
    Node* prev = head->next;
    head->next = NULL;

    while(prev != NULL)
    {
        current = prev;
        prev = prev->next;
        current->next = head;
        head = current;
    }
    return head;
}

Node* addNumber(Node* head1, Node* head2)
{
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* head3 = NULL;
    int sum=0, carry=0;

    while(ptr1 || ptr2)
    {
        sum = 0;
        if(ptr1)
            sum = sum + ptr1->data;
        if(ptr2)
            sum = sum + ptr2->data;
        sum = sum + carry;
        carry = sum /10;
        sum = sum%10;

        head3 = addNext(head3,sum);
        if(ptr1)
            ptr1 = ptr1->next;
        if(ptr1)
            ptr2 = ptr2->next;
    }
    if(carry)
        head3 = addNext(head3,carry);
    return head3;
}

int main()
{
    int num1,num2 ;
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;

    printf("\nEnter the 1st Number :: ");
    scanf("%d",&num1);
    printf("\nEnter the 2nd Number :: ");
    scanf("%d",&num2);

    head1 = digNode(head1,num1);
    head2 = digNode(head2,num2);

    printf("\n1st Number is ::");
    display(head1);
    printf("\n2nd Number is ::");
    display(head2);

    head1 = revList(head1);
    head2 = revList(head2);

    printf("\n-----------After Reverse-----------\n");
    printf("\n1st Number is ::");
    display(head1);
    printf("\n2nd Number is ::");
    display(head2);

    head3 = addNumber(head1,head2);
    printf("\n-----------After Addition-----------\n");
    printf("\nThe Number is ::");
    display(head3);
    return 0;
}
