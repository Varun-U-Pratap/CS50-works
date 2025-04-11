#include<stdio.h>
int sorting(char * arr,int low,int high)
{
    int piv = arr[high],temp, i = high;
    for(j = low; j < high - 1; j++)
    {
        if(arr[j] < piv)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int a[] = {5,9,2,7,3,5,4,3,6},high = size(a)/size(a[0])-1,low = 0;
    sorting(a,low,high);
    return 0;
}
