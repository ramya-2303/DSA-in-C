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
    newnode->next=newnode;
    newnode->prev=newnode;
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
    do{
        printf(" %d",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}

struct Node* insert_front(struct Node* head,int element)
{
        struct Node* newnode = create_node(element);
        struct Node* last=head->prev;
        newnode->next=head;
        newnode->prev=last;
        last->next=newnode;
        head->prev=newnode;
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
    struct Node* last=head->prev;
    last->next=newnode;
    newnode->prev = last;
    newnode->next = head;
    head->prev = newnode;
    return head;
}

struct Node* insert_index(struct Node* head,int element,int index)
{
    struct Node* newnode = create_node(element);
    if(head==NULL)
    {
        return newnode;
    }
    if(index==0)
    {
        printf("insertion not possible\n");
        return insert_front(head,element);
    }
    struct Node* temp=head;
    for(int i=0;i<index-1 && temp->next!=head;i++)
    {
        temp=temp->next;
    }
    newnode->next = temp->next;
    temp->next->prev=newnode;
    newnode->prev=temp;
    temp->next=newnode;
    return head;
}

struct Node* delete_front(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
      if (head->next == head) 
      { // single node
        free(head);
        return NULL;
    }
    struct Node* temp = head;
    struct Node* last=head->prev;
    head = head->next;
    head->prev=last;
    last->next=head;
    free(temp);
    return head;
}

struct Node* delete_end(struct Node* head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    struct Node* last=head->prev;
    struct Node* second_last=last->prev;
    second_last->next = head;
    head->prev = second_last;
    free(last);
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
    struct Node* q=head->next;
    for (int i = 0; i < index-1 && temp->next!=head; i++) 
    {
        temp = temp->next;
        q=q->next;
    }
    temp->next=q->next;
    q->next->prev=temp;
    free(q);
    return head;
}

int main()
{
    struct Node* head=NULL;
    struct Node* temp=NULL;
    int n,value,choice,index,element;
    printf("Enter the number of nodes to be entered:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter the value of node:");
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
    if (head != NULL)
    {
        temp->next = head;
        head->prev = temp;
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
    return 0;
}
