#include<stdio.h>
#include<conio.h>
#define SZ 3
int front=-1,rear=-1;
void insert(int *q)
{
if(front==(rear+1)%SZ)
{
printf("queue is full\n");
return;
}
if(front==-1)
front=0;
rear=(rear+1)%SZ;
printf("enter the elements to insert\n");
scanf("%d",&q[rear]);
}
void delete(int *q)
{
if(front==-1)
{
printf("queue is empty\n");
return;
}
printf("deletd element is %d",q[front]);
if(front==rear)
front=rear=-1;
else
front=(front+1)%SZ;
return;
}
void search(int *q)
{
int x,f,pos;
if(front==-1)
{
printf("queue is empty\n");
return;
}
printf("enter the element to be searched\n");
scanf("%d",&x);
f=front;
pos=1;
while(1)
{
if(q[f]==x)
{
printf("element found location %d",pos);
break;
}
if(f==rear)
{
printf("element is not found\n");
break;
}
f=(f+1)%SZ;
pos=pos+1;
}
}
void display(int *q)
{
int f;
if(front==-1)
{
printf("queue is empty");
return;
}
f=front;
while(1)
{
printf("%d",q[f]);
if(f==rear)
break;
f=(f+1)%SZ;
}
}
void main()
{
int q[SZ];
int opt;
clrscr();
while(1)
{
printf("\nmenu\n");
printf("1.insert\n2.delete\n3.search\n4.display\n5.exit\nenter the option");
scanf("%d",&opt);
switch(opt)
{
case 1:insert(q);
break;
case 2:delete(q);
break;
case 3:search(q);
break;
case 4:display(q);
break;
case 5:printf("good bye");
      exit();
}
}
}