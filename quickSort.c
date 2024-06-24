// Online C compiler to run C program online
#include <stdio.h>

void printArr(int*arr, int sz)
{
    int i =0;
    for(i= 0; i< sz; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int fix_pivot_pos(int* arr, int li, int hi)
{
    int p = arr[hi]; // assumed pivot as last elem.
    //now find suitable pos for p
    int it = li;
    int pi = li -1;
    
    //at start of loop assuming the pivot index is -1
    for (it = li; it < hi; it++)
    {
        if (arr[it] <= p)
        {
            pi++;
            //swap assumed pi and 'it'
            swap(&arr[pi], &arr[it]);
        }
    }
    //iterated thru the arr. found pi for 'p'. so move pivot to pi
    pi++;
    swap(&arr[pi], &arr[hi]);
    return pi;
}
void quickSort(int* arr, int li, int hi)
{
    //when to break this quickSort() recursive call ?
    if (li < hi) {
        //1. find and fix position for pivot elem chosen
        int pi = fix_pivot_pos(arr, li, hi);
        //2. divide arr to sub arrays. left to pivot, and right to pivot
        //3. rerun quick sort on left sub arr and right sub arr
        quickSort(arr, li, pi -1);
        quickSort(arr, pi+1, hi);
    }
    
}

int main() {
    // Write C code here
    int arr[] = {6,2,1,4,8,7,5,1,3,12,14,11};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int li = 0;
    int hi = sz -1;
    quickSort(arr, li, hi);
    //print arr
    printArr(arr, sz);

    return 0;
}