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

void swap(int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int* arr, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
       for (j = 0; j < n-i; j++)
       {
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
       }
    }
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
    bubbleSort(arr,n-1);       //passing the lowest index , and highest index
    printf("\n====================SORTED====================\n");

    display(arr,n);
}
