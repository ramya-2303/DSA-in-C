#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* create_node(int value)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    newnode->prev=NULL;
    return newnode;
}

void display(struct Node* head)
{
    if(head==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    struct Node* temp=head;
    printf("Doubly linked list\n");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

struct Node* insert_front(struct Node* head,int element)
{
    struct Node* newnode = create_node(element);
    if(head!=NULL)
    {
        newnode->next=head;
        head->prev=newnode;
    }
    head=newnode;
    return head;
}

struct Node* insert_end(struct Node* head,int element)
{
    struct Node* newnode = create_node(element);
    if(head==NULL)
    {
        return newnode;
    }
    struct Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}

struct Node* insert_index(struct Node* head,int element,int index)
{
    if(index==0)
    {
        return insert_front(head,element);
    }
    struct Node* temp=head;
    for(int i=0;i<index-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if(temp == NULL)
    {
        printf("Index out of bounds. Inserting at end.\n");
        return insert_end(head,element);
    }
    struct Node* newnode = create_node(element);
    newnode->next = temp->next;
    newnode->prev = temp;
    if(temp->next != NULL)
        temp->next->prev = newnode;
    temp->next = newnode;
    return head;
}

struct Node* delete_front(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

struct Node* delete_end(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {    
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct Node* delete_index(struct Node* head, int index) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (index == 0) {
        return delete_front(head);
    }
    struct Node* temp = head;
    for (int i = 0; i < index && temp != NULL; i++) 
    {
        temp = temp->next;
    }
    if(temp == NULL)
    {
        printf("Index out of bounds\n");
        return head;
    }
    if(temp->prev != NULL)
        temp->prev->next = temp->next;
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    free(temp);
    return head;
}

int main()
{
    struct Node* head=NULL;
    struct Node* temp=NULL;
    int n,value,choice,index,element;

    printf("Enter the number of nodes to be entered: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node: ");
        scanf("%d",&value);
        struct Node* newnode=create_node(value);
        if(head==NULL)
        {
            head=newnode;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            newnode->prev=temp;
            temp=temp->next;
        }
    }
    display(head);
    
    printf("Enter the value of element: ");
    scanf("%d", &element);
    printf("\nMenu\n");
    printf("1. insert_front\n");
    printf("2. insert_index\n");
    printf("3. insert_end\n");
    printf("4. delete_front\n");
    printf("5. delete_index\n");
    printf("6. delete_end\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            head=insert_front(head,element);
            break;
        case 2:
            printf("Enter index: ");
            scanf("%d", &index);
            head = insert_index(head, element, index);
            break;
        case 3:
            head = insert_end(head, element);
            break;
        case 4:
            head = delete_front(head);
            break;
        case 5:
            printf("Enter index: ");
            scanf("%d", &index);
            head = delete_index(head, index);
            break;
        case 6:
            head = delete_end(head);
            break;
        default:
            printf("Invalid choice\n");
    }
    display(head);
    while(head != NULL)
        head = delete_front(head);

    return 0;
}
