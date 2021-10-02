#include<stdio.h>
#include<stdlib.h>

void display(int *a,int n)
{
    printf("\nThe Array is :: ");
    for(int i=0 ; i<n ; i++)
    {
        printf("   %d    ",*(a+i));
    }
    printf("\n");
}

int binSearch(int *a ,int low , int high , int item)
{
    int pos;
    if(high>low)
    {
        int mid = (high+low)/2;
        if(a[mid] == item)
            return mid;
        else if(a[mid] > item)
            binSearch(a,0,mid-1,item);
        else
            binSearch(a,mid-1,high,item);
    }
    return -1;
}


int main()
{
    int n;
    printf("\nEnter the Number of Elements :: ");
    scanf("%d",&n);
    int* arr =(int*)malloc(sizeof(int)*n);
    for(int i=0 ; i<n ; i++)
    {
        printf("\n\tEnter the No.%d Element :: ",i+1);
        scanf("%d",(arr+i));
    }
    display(arr,n);
    printf("Enter the Element to Search :: ");
    int item;
    scanf("%d",&item);
    int pos = binSearch(arr,0,n-1,item);
    if(pos==-1)
        printf("\nElement not Found !!!\n");
    else
        printf("\nElement Found at Position :: %d\n",pos+1);
}
