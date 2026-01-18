#include<stdio.h>
#include<stdlib.h>
struct Node 
{  
    int data;
    struct Node* next;
};
void display(struct Node *head)
{
    struct Node* temp=head;
    if(temp==NULL)
    {
        printf("The list is empty\n");
        return;
    }
    printf("circular singlylinked list:");
    printf("%d ", temp->data);
    temp = temp->next;
    while (temp != head)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
struct Node* create_node(int value)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=newnode;  
    return newnode;
}
struct Node* insert_front(struct Node* head,int element)
{
    struct Node* newnode=create_node(element);
    if(head==NULL)
    {
        return newnode;
    }
    struct Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    newnode->next=head;
    temp->next=newnode;
    return newnode;
}
struct Node* insert_index(struct Node* head,int element,int index)
{
    struct Node*p=head;
    if(head==NULL)
    {
        printf("The linked list is null\n");
        return create_node(element);
    }
    if(index==0)
    {
        return insert_front(head,element);
    }
    for(int i=0;i<index-1 && p->next!=head;i++)
    {
        p=p->next;
    }
    struct Node* newnode=create_node(element);
    newnode->next=p->next;
    p->next=newnode;
    return head;
}
struct Node* insert_end(struct Node* head,int element)
{
    struct Node* newnode=create_node(element);
    if(head==NULL)
    {
        return newnode;
    }
    struct Node* temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    return head;
}
struct Node* delete_front(struct Node* head)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    if (head->next == head) {  // only one node
        free(head);
        return NULL;
    }
    struct Node* temp=head;
    struct Node* last=head;
    while(last->next!=head)
    {
        last=last->next;
    }
    head=head->next;
    last->next=head;
    free(temp);
    return head;
}
struct Node* delete_index(struct Node* head,int index)
{
   if(head==NULL)
    {
        printf("The linked list is empty\n");
        return NULL;
    }
    if(index==0)
        return delete_front(head);

    struct Node *p=head, *q=head->next;
    int i;
    for(i=0; i<index-1 && q!=head; i++)
    {
        p=p->next;
        q=q->next;
    }

    if(q==head)
    {
        printf("Index out of bounds\n");
        return head;
    }

    p->next=q->next;
    free(q);
    return head;
}
struct Node* delete_end(struct Node* head)
{
    struct Node* p=head;
    struct Node* q=NULL;
    if(head==NULL)
    return NULL;
    if(head->next==head)
    {
        free(head);
        return NULL;
    }
    while(p->next->next!=head)
    {
        p=p->next;
    }
    q=p->next;
    p->next=head;
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
        printf("Enter the value of nodes %d:",i);
        scanf("%d",&value);
        struct Node* newnode=create_node(value);
        if(head==NULL)
        {
            head=newnode;
            newnode->next=head;
            temp=head;
        }
        else
        {
            temp->next=newnode;
            newnode->next=head;
            temp=temp->next;
        }
    }
    display(head);
    printf("Enter the menu\n");
    printf("1.insert_front\n");
    printf("2.insert_index\n");
    printf("3.insert_end\n");
    printf("4.delete_front\n");
    printf("5.delete_index\n");
    printf("6.delete_end\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice){
        case 1:
          printf("Enter the value of element:");
          scanf("%d",&element);
            head=insert_front(head,element);
            break;
        case 2:
          printf("Enter the value of element:");
          scanf("%d",&element);
            printf("Enter the index");
            scanf("%d",&index);
            head=insert_index(head,element,index);
            break;
        case 3:
          printf("Enter the value of element: ");
          scanf("%d",&element);
            head=insert_end(head,element);
            break;
        case 4:
            head=delete_front(head);
            break;
        case 5:
            printf("Enter the index:");
            scanf("%d",&index);
             head=delete_index(head,index);
            break;
        case 6:
            head=delete_end(head);
            break;
        default:
            printf("Invalid case");
    }
    display(head);
    return 0;
}
