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

void merge(int *a, int low, int mid, int high)
{
    int i = low;
    int j = mid+1;
    int k = low;
    int* b =(int*)malloc(sizeof(int)*high);
    while((i<=mid) && (j<=high))
    {
        if(*(a+i) < *(a+j))
        {
            *(b+k) = *(a+i);
            k++; i++;
        }
        else
        {
            *(b+k) = *(a+j);
            k++; j++;
        }
    }
    while(i<=mid)
    {
        *(b+k) = *(a+i);
        k++; i++;
    }
    while(j<=high)
    {
        *(b+k) = *(a+j);
        k++; j++;
    }
    for( i=low ; i<=high ; i++)
        *(a+i)= *(b+i);
}

void mergeSort(int *a, int low , int high)
{
    int mid;
    if(high>low)
    {
        mid = (high+low)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,low,mid,high);
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
    mergeSort(arr,0,n-1);       //passing the lowest index , and highest index
    printf("\n====================SORTED====================\n");

    display(arr,n);
}
