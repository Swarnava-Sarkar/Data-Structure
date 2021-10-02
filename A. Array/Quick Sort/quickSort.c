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

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int* a,int low, int high)
{
    int j = low;        // j is pointing the 1st element of the array
    int pivot = *(a+j); // the 1st element is the pivot that we need to place in correct position
    for(int i = low+1 ; i<=high ; i++)
    {
        if(pivot > *(a+i))
        {
            j++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[j],&a[low]);
    return j;
}

void quickSort(int *a ,int low, int high )
{
    int pivotIndex;
    if(low<high)        // partition the array if high > low i.e. there is more then 1 element
    {
        pivotIndex = Partition(a,low,high);     // partition returns the index of the sorted element
        quickSort(a,low,pivotIndex);
        quickSort(a,pivotIndex+1,high);
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
    quickSort(arr,0,n-1);       //passing the lowest index , and highest index
    printf("\n====================SORTED====================\n");

    display(arr,n);
}
