//linear search in an array

#include<stdio.h>
int linearsearch(int arr[],int size,int element)
{
    for(int i=0;i<size;i++)
    {
        if(arr[i]==element)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    int a[]={1,8,75,23,45};
    int n=sizeof(a)/sizeof(a[0]);
    int m=75;
    int searchindex=linearsearch(a,n,m);
    printf("%d %d",m,searchindex);
    return 0;
}
