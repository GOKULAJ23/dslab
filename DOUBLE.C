#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
struct node *left;
int data;
struct node *right;
};
struct node *head=NULL;
struct node *GetNode();
void insertlast();
void insertfirst();
void display();
void search();
void insertpos();
void deletefirst();
void deletelast();
void deletepos();
void main()
{
int opt=0;
clrscr();
while(opt!=9)
{
printf("\nMENU\n1.Insert first\n2.Inserfirst\n3.Insertlast\n.4.insertpos\n5.deletefirst\n6.deletelast\n7.deletepos\n8.search\n9.search\n");
scanf("%d",&opt);
switch(opt)
{
case 1:insertfirst();
break;
case 2:insertlast();
break;
case 3:insertpos();
break;
case 4:deletefirst();
break;
case 5:deletelast();
break;
case 6:deletepos();
break;
case 7:search();
break;
case 8:display();
break;
}
}
printf("exit");
getch();
}
void display()
{
struct node *ptr=head;
if(head==NULL)
{
printf("list is empty");
return;
}
printf("the elements are \n");
while(ptr!=NULL)
{
printf("%d",ptr->data);
ptr=ptr->right;
}
}
struct node *GetNode()
{
int x;
struct node *ne=(struct node *)malloc(sizeof(struct node));
if(ne==NULL)
printf("insufficient memory\n");
else
{
printf("enter the value to insert");
scanf("%d",&x);
ne->left=NULL;
ne->right=NULL;
ne->data=x;
}
return ne;
}
void insertfirst()
{
struct node *ne;
ne=GetNode();
if(ne==NULL)
return;
if(head==NULL)
head=ne;
else
{
head->left=ne;
ne->right=head;
head=ne;
}
display();
}
void insertlast()
{
struct node *ne,*ptr;
ne=GetNode();
if(ne==NULL)
return;
if(head==NULL)
head=ne;
else
{
ptr=head;
while(ptr->right!=NULL)
{
ptr=ptr->right;
}
ptr->right=ne;
ptr->left=ptr;
}
display();
}
void insertpos()
{
int value;
struct node *ne,*ptr,*ptr1;
ne=GetNode();
if(ne==NULL)
return;
if(head==NULL)
{
printf("list is empty.the node is inserted as the first node");
head=ne;
return;
}
printf("enter the key value after the the node has to  be inserted\n");
scanf("%d",&value);
ptr=head;
while(ptr->right!=NULL &&ptr->data!=value)
{
ptr=ptr->right;
}
if(ptr->right==NULL)
{
ptr->right=ne;
ne->left=ptr;
printf("\nnode is inserted at the last position");
}
else
{
ptr1=ptr->right;
ne->right=ptr1;
ne->left=ptr1;
ptr->right=ne;
ptr1->left=ne;
}
printf("\nthe element inserted\n");
display();
}
void deletefirst()
{
struct node *ptr;
if(head==NULL)
{
printf("list is empty");
return;
}
ptr=head;
head=head;
head=head->right;
if(head!=NULL)
head->left=NULL;
free(ptr);
display();
}
void deletelast()
{
struct node *ptr,*prev;
if(head==NULL)
{
printf("\nlist is empty\n");
return;
}
if(head->right==NULL)
{
free(head);
head==NULL;
}
ptr=head->right;
while(ptr->right!=NULL)
{
ptr=ptr->right;
}
prev=ptr->left;
prev->right=NULL;
free(ptr);
display();
}
void deletepos()
{
struct node *ptr,*prev,*next;
int x;
if(head==NULL)
{
printf("\nlist is empty");
return;
}
printf("enter the element to delete");
scanf("%d",&x);
if(head->data==x)
{
ptr=head;
head=ptr->right;
if(head!=NULL)
{
head->left=NULL;
}
free(ptr);
return;
}
ptr=head;
while(ptr->data!=x && ptr->right!=NULL)
{
ptr=ptr->right;
}
if(ptr->data==x)
{
next=ptr->right;
prev=ptr->left;
prev->right=ptr->right;
if(next!=NULL)
next->left=ptr->left;
free(ptr);
return;
}
printf("/nelementnot present in the list\n");
}
void search()
{
struct node *ptr;
int x;
if(head==NULL)
{
printf("\nlinked list is empty");
return;
}
printf("enter the element to search");
scanf("%d",&x);
ptr=head;
while(ptr!=NULL)
{
if(ptr->data==x)
{
printf("\nelement present in the list\n");
break;
}
ptr=ptr->right;
}
if(ptr==NULL)
printf("\n element not in the list\n");
}
