#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};
struct node *head = NULL;
void createnode(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node*));
    printf("enter data:");
    scanf("%d",&newnode->data);
    newnode->next=0;
    if (head==0){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
    }
}
void insertBeginning(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=data;
    newnode->next=head;
    head=newnode;
    printf("%d inserted at beginning of the linked list \n",data);
}
void insertAtPos(int data,int pos){
    struct node *newnode,*temp=head;
    if (pos<1){
        printf("Invalid position \n");
        return;
    }
    if (pos==1){
        insertBeginning(data);
        return;
    }
    newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=data;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if (temp==NULL){
        printf("Position out of range\n");
        free(newnode);
    }
    else{
        newnode->next=temp->next;
        temp->next=newnode;
    }
}
void insertEnd(int data){
    struct node *newnode=(struct node *)malloc(sizeof(struct node *));
    newnode->data=data;
    newnode->next=NULL;
    if (head==NULL){
        head=newnode;
    }
    else{
        struct node *temp=head;
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void displaylist(){
    struct node *temp=head;
    if (head==NULL){
        printf("Empty list\n");
        return;
    }
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
}
void main(){
    int ch=1;
    while(ch!=0){
        printf("Enter your choice:(\n");
        printf("1:Create\n");
        printf("2:insert at beginning\n");
        printf("3:insert at specific position\n");
        printf("4:insert at end\n");
        printf("5:display\n");
        printf("0:Stop)\n");
        scanf("%d",ch);
        switch(ch){
            case 1:
            {
                createnode();
                break;
            }
            case 2:
            {
                int num;
                printf("Enter data:");
                scanf("%d",&num);
                insertBeginning(num);
                break;
            }
            case 3:
            {
                int num,pos;
                printf("Enter data:");
                scanf("%d",&num);
                printf("Enter position:");
                scanf("%d",&pos);
                insertAtPos(num,pos);
                break;
            }
            case 4:
            {
                int num;
                printf("Enter data:");
                scanf("%d",&num);
                insertEnd(num);
                break;
            }
            case 5:
            {
                displaylist();
                break;
            }
            default:
            {
                printf("Invalid input");
                break;
            }
        }
        
    }
}
