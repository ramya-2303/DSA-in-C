//Implementing heap and its operations
//(c-1)/2  ->  parent
// 2*p + 1 ->  left child
// 2*p + 2 ->  right child

// insert() → Heapify-up
// delete() → Delete root (maximum element) + heapify-down
// display() → Print heap array

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void insert(int H[],int *pcount,int key)
{
//pcount = pointer to number of element
	int c,p,temp;
    //temp = temporary variable for swapping
    //key = new value to insert
    // c = child index
    // p = parent index
	if(*pcount == MAX-1)            
		printf("Heap is full");
	else{
		c=*pcount;          
		H[*pcount]=key;     
		(*pcount)++; 
    
		while(c>0){
			p=(c-1)/2;
			if(H[p]>H[c])
				break;
        
			else{
				temp=H[p];
				H[p]=H[c];
				H[c]=temp;
				c=p;
			}
		}
	}
}

void display(int H[],int count)
{
	for(int i=0;i<count;i++)
	{
		printf("%d ",H[i]);
	}
}

int delete(int H[], int *pcount)
{
	int p,c,i,lc,rc,temp;
	int delkey = H[0];
	int j = *pcount;
	H[0]=H[j-1];          
	(*pcount)--;           
	p=0;                  
	lc=2*p+1;
  
	while(lc <= (*pcount - 1)){
		c=lc;
		if(lc != (*pcount-1))7{
			rc=lc+1;
			if(H[rc] > H[lc])
				c=rc;
		}
		if(H[p]>H[c])
			break;
		else
		{
			temp=H[p];
			H[p]=H[c];
			H[c]=temp;
			p=c;
			lc=2*p+1;
		}
	}
	return delkey;
}

int main()
{
	int H[MAX],count=0,key,n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		insert(H,&count,key);
	}
	display(H,count);
	int del = delete(H,&count);
	printf("%d\n",del);
	display(H,count);
	return 0;
}
