/*
Program: Basic Array Operations
Language: C
Operations:
1. Insert at beginning
2. Insert at end
3. Insert at index
4. Delete from beginning
5. Delete from end
6. Delete from index
*/

#include<stdio.h>
#include<stdlib.h>

void display(int B[],int a)
{
    if(a==0)
    {
        printf("The array is empty");
        return;
    }
    for(int i=0;i<a;i++)
    {
        printf(" %d",B[i]);
    }
}  

//insert index
int insert_index(int B[], int a, int element, int index) {
    if (index < 0 || index > a) {
        printf("Invalid index!\n");
        return a;  
    }
    for (int i = a; i > index; i--) {
        B[i] = B[i - 1]; 
    }
    B[index] = element;
    return a + 1; 
}

// Inserti end
int insert_end(int B[], int a, int element) {
    B[a] = element;
    return a + 1;
}

// Insert front
int insert_front(int B[], int a, int element) {
    for (int i = a; i > 0; i--) {
        B[i] = B[i - 1];  
    }
    B[0] = element;
    return a + 1;
}

//delete at index
int delete_index(int B[],int a,int place)
{
    if(place<0||place>=a)
    {
        printf("invlid");
        return a;
    }
    for(int i=place;i<a-1;i++)
    {
        B[i]=B[i+1];
    }
    return a-1;
}

//delete front
int delete_front(int B[], int a)
{
    if (a == 0) {
        printf("Array is already empty\n");
        return a;
    }
    for (int i = 0; i < a - 1; i++) {
        B[i] = B[i + 1];
    }
    return a - 1;
}

//delete end
int delete_end(int B[],int a)
{
    if(a==0)
    {
        printf("the array is alredy empty");
      return a;
    }
    return a-1;
}

int main() {
    int A[100];
    int n, element, index, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    do {
        printf("\nCurrent Array: ");
        display(A, n);

        printf("\n\nMENU");
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Insert at index");
        printf("\n4. Delete from beginning");
        printf("\n5. Delete from end");
        printf("\n6. Delete from index");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &element);
                n = insert_front(A, n, element);
                break;

            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                n = insert_end(A, n, element);
                break;

            case 3:
                printf("Enter element and index: ");
                scanf("%d %d", &element, &index);
                n = insert_index(A, n, element, index);
                break;

            case 4:
                n = delete_front(A, n);
                break;

            case 5:
                n = delete_end(A, n);
                break;

            case 6:
                printf("Enter index to delete: ");
                scanf("%d", &index);
                n = delete_index(A, n, index);
                break;

            case 0:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
