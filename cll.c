#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
void insert_by_val();
void insert_at_end();
void insert_at_front();
void delete_at_front();
void search();
void delete_at_end();
void display();
struct snode
{
	int data;
	struct snode *link;
};
typedef struct snode node;
node *head=NULL;


int main()
{
		int ch;
		while(1)
		{
			printf("\n1-Insert at front\n2-Insert at end\n3-Insert by value\n4-Delete at front\n5-Delete at end\n6-search\n7-Display\n8-exit\n");
			printf("enter ur choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: insert_at_front();
				break;
				case 2: insert_at_end();
				break;
				case 3: insert_by_val();
				break;
				case 4: delete_at_front();
				break;
				case 5: delete_at_end();
				break;
				case 6: search();
				break;
				case 7: display();
				break;
				case 8: exit(0);
				break;
				default : printf("wrong choice");
				
			}
			
		}
		
		
}



void insert_at_front()
{
	node *lnode,*ptr,*last;
	int elem;
	last=head;
	lnode=(struct snode*)malloc(sizeof(struct snode));
	if(lnode!=NULL)
	{
		printf("\nenter the element to insert:");
		scanf("%d",&elem);
		lnode->data=elem;
		lnode->link=NULL;
		if(head==NULL)
		{
		
			head=lnode;
			head->link=head;
		}
		else
		{
			while(last->link!=head)
				last=last->link;
			
			last->link=lnode;
			lnode->link=head;
			head=lnode;
		}
		
	}
	else
	{
		printf("\n\t\t overflow");
	}
}


void insert_by_val()
{
	node *last,*lnode,*ptr,*ptr1;
	int elem,loc;
	last=head;
	lnode=(struct snode*)malloc(sizeof(struct snode));
	
	if(lnode!=NULL)
	{
		
		printf("\nenter the element to insert:");
		scanf("%d",&elem);
		lnode->data=elem;
		lnode->link=NULL;
		printf("\nenter where the element to be inserted:");
		scanf("%d",&loc);
		if(head==NULL)
		{
		
			head=lnode;
			head->link=head;
		}
		else
		{
			ptr=head;
			while((ptr->data!=loc) && (ptr->link!=head))
				ptr=ptr->link;
			if(ptr->data==loc)
			{
				ptr1=ptr->link;
				ptr->link=lnode;
				lnode->link=ptr1;
			}
			else
			{
				printf("\nelement not found");
				
			}
		}
		
	}
	
}

void insert_at_end()
{
	node *last,*lnode;
	int elem;
	last=head;
	lnode=(struct snode*)malloc(sizeof(struct snode));
	
	if(lnode!=NULL)
	{
		
		printf("\nenter the element to insert:");
		scanf("%d",&elem);
		lnode->data=elem;
		lnode->link=NULL;
		
		if(head==NULL)
		{
		
			head=lnode;
			head->link=head;
		}
		else
		{
			
			while(last->link!=head)
			{
			last=last->link;
			}
			last->link=lnode;
			lnode->link=head;
			
		}
		
	}
	else
	{
		printf("\n\t\t overflow");
	}
	
	
}

void delete_at_front()
{
	node *ptr,*last;
	if(head==NULL)
	{
		printf("\nno elements to delete");
		
	}
	else
	{
		ptr=head;
		printf("The element deleted is %d",ptr->data);
		last=ptr;
		head=head->link;
		if(ptr==head)
		{
			
			head=NULL;
		}
		else
		{
			while(last->link!=ptr)
				{
				last=last->link;
				}
			last->link=head;
		}
		free(ptr);
	}
	
}

void search()
{
	node *ptr;
	int loc,count=0;
	ptr=head;
	if(head==NULL)
	{
		printf("\nno elements to delete");
		
	}
	else
	{
		printf("\nenter the element to be searched:");
		scanf("%d",&loc);
		while((ptr->data!=loc)&&(ptr->link!=head))
		{
			count++;
			ptr=ptr->link;
		}
		if(ptr->data==loc)
		{
			printf("\nElement is found at loc %d",count+1);
			
		}
		else
		{
			printf("\nElement is not found");
			
		}
	}
	
}

void delete_at_end()
{
	node *ptr,*last;
	if(head==NULL)
	{
		printf("\nno elements to delete");
		
	}
	else
	{
		last=head;
		ptr=NULL;
		while(last->link!=head)
		{
			ptr=last;
			last=last->link;
		}
		printf("\nThe element deleted is %d",last->data);
		
		if(last==head)
		{
			
			printf("\nNo elements");
			head=NULL;
			free(last);	
			
		}
		else
		{
			ptr->link=last->link;
			free(last);	
		}
	}
}



void display()
{
	node *ptr;
	ptr=head;
	if(head==NULL)
	{
		printf("\n No elements in Circular linked list");
		
	}
	else
	{
			while(ptr->link!=head)
			{
				printf("---%d--->",ptr->data);
				ptr=ptr->link;
			}
			printf("---%d--->",ptr->data);
	}
}