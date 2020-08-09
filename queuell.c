#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void display();
void insert();
void delete();
struct node
{
	int data;
	struct node *link;
};
typedef struct node qnode;
qnode *front=NULL,*rear=NULL;


int main()
{
		int ch;
		while(1)
		{
			printf("\n1-Insert\n2-Delete\n3-display\n4-exit\n");
			printf("enter ur choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: insert();
				break;
				case 2: delete();
				break;
				case 3: display();
				break;
				case 4: exit(0);
				break;
				default : printf("wrong choice");
				
			}
			
		}
		
		
}



void insert()
{
	qnode *lnode;
	int elem;
	lnode=malloc(sizeof(struct node));
	if(lnode!=NULL)
	{
		printf("\nenter the element to insert:");
		scanf("%d",&elem);
		lnode->data=elem;
		lnode->link=NULL;
		if(front==NULL)
		{
		
			front=rear=lnode;
		
		}
		else
		{
			rear->link=lnode;
			rear=lnode;
		
		}
	}
	else
	{
		printf("\n\t\t overflow");
	}
}



void delete()
{
	qnode *ptr;
	ptr=front;
	if(front==NULL)
	{
		printf("\n Queue underflow");
	}
	else
	{
		ptr=front;
		printf("the element deleted is %d",ptr->data);
		front=front->link;
		free(ptr);
	}
	
	
}



void display()
{
	qnode *ptr;
	ptr=front;
	if(front==NULL)
	{
		printf("no elements in queue");
		
	}
	else
	{
		while(ptr!=NULL)
		{
			printf("---%d--->",ptr->data);
			ptr=ptr->link;
		}
	
	}
}