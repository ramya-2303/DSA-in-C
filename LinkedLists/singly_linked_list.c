//singly linked list without Header Node ( Dummy node )

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
    printf("linked list:");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct Node* create_node(int value)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
struct Node* insert_front(struct Node* head,int element)
{
    struct Node* newnode=create_node(element);
    newnode->next=head;
    head=newnode;
    return head;
}
struct Node* insert_index(struct Node* head,int element,int index)
{
    struct Node*p=head;
    struct Node* newnode=create_node(element);
    if(index==0)
    {   
        return insert_front(head,element);
    }
    if(head==NULL)
    {
        printf("The linked list is null\n");
        return newnode;
    }
    for(int i=0;i<index-1 && p!=NULL;i++)    {
        p=p->next;
    }
    newnode->next=p->next;
    p->next=newnode;
    return head;
}
struct Node* insert_end(struct Node* head,int element)
{
    struct Node* newnode=create_node(element);
    if(head==NULL)
    {
        printf("The linked list is null\n");
        return newnode;
    }
    struct Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newnode;
    return head;
}
struct Node* delete_front(struct Node* head)
{
    if(head==NULL)
    {
        printf("list is empty\n");
        return NULL;
    }
    struct Node* temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct Node* delete_index(struct Node* head,int index)
{
    struct Node*p=head;
    struct Node *q=head->next;
    if(head==NULL)
    {
        printf("The linked list is null\n");
        return NULL;
    }
    if(index==0)
    {
        return delete_front(head);
    }
    for(int i=0;i<index-1 && p!=NULL;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct Node* delete_end(struct Node* head)
{
    struct Node* p=head;
    struct Node* q=head->next;
    if(head==NULL)
    return NULL;
    if(head->next==NULL)
    {
        free(head);
        return NULL;
    }
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
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
            temp=head;
        }
        else
        {
            temp->next=newnode;
            temp=temp->next;
        }
    }
    display(head);
    printf("Enter the Element value: ");
    scanf("%d",&element);
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
            head=insert_front(head,element);
            break;
        case 2:
            printf("Enter the index");
            scanf("%d",&index);
            head=insert_index(head,element,index);
            break;
        case 3:
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
