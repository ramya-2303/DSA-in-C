// Binary search in an array
#include<stdio.h>
int binarysearch(int arr[],int size,int element)
{
    int low,mid,high;
    low=0;
    high=size-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]=element)
        {
            return mid;
        }
        if(arr[mid]<element)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}
int main()
{
    int a[]={1,8,23,45};
    int n=sizeof(a)/sizeof(a[0]);
    int m=8;
    int searchindex=binarysearch(a,n,m);
    printf("%d %d",m,searchindex);
    return 0;
}
