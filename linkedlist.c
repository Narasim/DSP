/* 
Author 		: Y NARASIMHULU
Roll No		: 18MCPC17
LAB		: DSP LAB ASSIGNMENT 6
OBJECTIVE	: Write a program to implement singly, doubly, circular singly and circular doubly linked list.
*/


#include<stdio.h>
#include<stdlib.h>

struct ll
{
	char data;
	struct ll *next;
	struct ll *prev;

}*start=NULL,*end=NULL;
int count=0;
void insert_sll(char key);
void insert_dll(char key);
void insert_scll(char key);
void insert_dcll(char key);
void delete_sll(int key);
void delete_dll(int key);
void delete_scll(int key);
void delete_dcll(int key);
void search_sll(char key);
void search_scll(char key);
void display_sll();
void display_scll();
void sll();
void dll();
void scll();
void dcll();

void main()
{

	int i,j,ch;
	count=0;
	printf("1-Singly Linked List\n");
	printf("2-Doubly Linked List\n");
	printf("3-Singly Circular List\n");
	printf("4-Doubly Circular List\n");
	printf("5-Exit\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		sll();
	}
	else if(ch==2)
	{
		dll();
	}
	else if(ch==3)
	{
		scll();
	}
	else if(ch==4)
	{
		dcll();
	}
	else if(ch==5)
	{
		exit(0);
	}
	else
		printf("Wrong Choice\n");
	printf("END\n");
}
void sll()
{
	int ch,delete_key;
	char insert_key,search_key;
	while(1)
	{
		printf("****Singly Linked List****\n");
		printf("1-Insert into list\n");
		printf("2-Delete from list\n");
		printf("3-Display list\n");
		printf("4-Search in the list\n");
		printf("5-Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nEnter the element to insert : ");
			scanf(" %c",&insert_key);
			insert_sll(insert_key);
		}
		else if(ch==2)
		{
			printf("\nEnter the node number to delete : ");
			scanf("%d",&delete_key);
			delete_sll(delete_key);
		}
		else if(ch==3)
		{
			display_sll();
			printf("\n");
		}
		else if(ch==4)
		{
			printf("\nEnter the element to search : ");
			scanf(" %c",&search_key);
			search_sll(search_key);
		}
		else if(ch==5)
		{
			exit(0);
		}
		else
			printf("Wrong Choice\n");
	}
}
void dll()
{
	int ch,delete_key;
	char insert_key,search_key;
	while(1)
	{
		printf("****Doubly Linked List****\n");
		printf("1-Insert into list\n");
		printf("2-Delete from list\n");
		printf("3-Display list\n");
		printf("4-Search in the list\n");
		printf("5-Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nEnter the element to insert : ");
			scanf(" %c",&insert_key);
			insert_dll(insert_key);
		}
		else if(ch==2)
		{
			printf("\nEnter the node number to delete : ");
			scanf("%d",&delete_key);
			delete_dll(delete_key);
		}
		else if(ch==3)
		{
			display_sll();
			printf("\n");
		}
		else if(ch==4)
		{
			printf("\nEnter the element to search : ");
			scanf(" %c",&search_key);
			search_sll(search_key);
		}
		else if(ch==5)
		{
			exit(0);
		}
		else
			printf("Wrong Choice\n");
	}
}
void scll()
{
	int ch,delete_key;
	char insert_key,search_key;
	while(1)
	{
		printf("****Circular Singly Linked List****\n");
		printf("1-Insert into list\n");
		printf("2-Delete from list\n");
		printf("3-Display list\n");
		printf("4-Search in the list\n");
		printf("5-Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nEnter the element to insert : ");
			scanf(" %c",&insert_key);
			insert_scll(insert_key);
		}
		else if(ch==2)
		{
			printf("\nEnter the node number to delete : ");
			scanf("%d",&delete_key);
			delete_scll(delete_key);
		}
		else if(ch==3)
		{
			display_scll();
			printf("\n");
		}
		else if(ch==4)
		{
			printf("\nEnter the element to search : ");
			scanf(" %c",&search_key);
			search_scll(search_key);
		}
		else if(ch==5)
		{
			exit(0);
		}
		else
			printf("Wrong Choice\n");
	}
}
void dcll()
{
	int ch,delete_key;
	char insert_key,search_key;
	while(1)
	{
		printf("****Circular Doubly Linked List****\n");
		printf("1-Insert into list\n");
		printf("2-Delete from list\n");
		printf("3-Display list\n");
		printf("4-Search in the list\n");
		printf("5-Exit\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("\nEnter the element to insert : ");
			scanf(" %c",&insert_key);
			insert_dcll(insert_key);
		}
		else if(ch==2)
		{
			printf("\nEnter the node number to delete : ");
			scanf("%d",&delete_key);
			delete_dcll(delete_key);
		}
		else if(ch==3)
		{
			display_scll();
			printf("\n");
		}
		else if(ch==4)
		{
			printf("\nEnter the element to search : ");
			scanf(" %c",&search_key);
			search_scll(search_key);
		}
		else if(ch==5)
		{
			exit(0);
		}
		else
			printf("Wrong Choice\n");
	}
}
void insert_sll(char key)
{
	struct ll *list_node_sll;
	list_node_sll = malloc(sizeof(struct ll));
	list_node_sll->data = key;
	list_node_sll->next = NULL;
	// at the beginning
	if(start == NULL)
	{
		start = end = list_node_sll;
	}
	// at the end
	else
	{
		end->next = list_node_sll;
		end = list_node_sll;
	}
	// counting the number of nodes.
	count++;
}
void insert_dll(char key)
{
	struct ll *list_node_dll;
	list_node_dll = malloc(sizeof(struct ll));
	list_node_dll->data = key;
	list_node_dll->next = NULL;
	list_node_dll->prev = NULL;
	// at the beginning
	if(start == NULL)
	{
		start = end = list_node_dll;
	}
	// at the end
	else
	{
		end->next = list_node_dll;
		list_node_dll->prev = end;
		end = list_node_dll;
	}
	// counting the number of nodes.
	count++;
}
void delete_sll(int key)
{
	int i;
	struct ll *trace_node_sll,*trace_back_node_sll=NULL;
	if(key>count)
	{
		printf("Number of elements in list is less than %d, so deletion is not possible\n",key);
	}
	else
	{
		// go to the node		
		i = 1;		
		trace_node_sll = start;
		while(i<key)
		{
			i++;
			trace_back_node_sll = trace_node_sll;
			trace_node_sll = trace_node_sll->next;
		}
		// reached at the node and
		// if it is a first node to be deleted
		if(trace_node_sll==start)
		{
			// if it is the only node.
			if(start->next==NULL)
			{
				start = NULL;
			}
			else
				start = start->next;
		}
		// if it is the end node to be deleted
		else if(trace_node_sll == end)
		{
			trace_back_node_sll->next = NULL;
			end = trace_back_node_sll;
		}
		// if it is the middle element to be deleted
		else
		{
			trace_back_node_sll->next = trace_node_sll->next;
		}
		count--;
	}
}
void delete_dll(int key)
{
	int i;
	struct ll *trace_node_dll,*trace_back_node_dll=NULL,*next_node_dll;
	if(key>count)
	{
		printf("Number of elements in list is less than %d, so deletion is not possible\n",key);
	}
	else
	{
		// go to the node		
		i = 1;		
		trace_node_dll = start;
		while(i<key)
		{
			i++;
			trace_back_node_dll = trace_node_dll;
			trace_node_dll = trace_node_dll->next;
		}
		// reached at the key'th node and
		// if it is a first node to be deleted
		if(trace_node_dll==start)
		{
			// if it is the only node.
			if(start->next==NULL)
			{
				start = NULL;
			}
			else
			{
			start = start->next;
			start->prev = NULL;
			}
		}
		// if it is the end node to be deleted
		else if(trace_node_dll == end)
		{
			trace_back_node_dll->next = NULL;
			end = trace_back_node_dll;
		}
		// if it is the middle element to be deleted
		else
		{
			next_node_dll = trace_node_dll->next;
			//trace_node_dll->next->prev = trace_back_node_dll;
			trace_back_node_dll->next = next_node_dll;
			next_node_dll->prev = trace_back_node_dll;
		}
		count--;	
	}
}
void search_sll(char key)
{
	int i=0;
	struct ll *trace_node_sll;
	// start tracing at the beginning
	trace_node_sll = start;
	while(trace_node_sll!=NULL)
	{
		i++;
		if(trace_node_sll->data == key)
		{
			printf("Element is found at location %d\n",i);
			break;
		}
		trace_node_sll = trace_node_sll->next;
		
	}
	// if reached the end of the list then no elements
	if(trace_node_sll==NULL)
		printf("Element is not found \n");
}
void display_sll()
{
	struct ll *trace_node_sll;
	trace_node_sll = start;
	// if no elements
	if(start == NULL)
		printf("No Elements\n");
	// if there are elements then print
	else
	{
		while(trace_node_sll!=NULL)
		{
			printf("%c ",trace_node_sll->data);
			trace_node_sll = trace_node_sll->next;
		}
	}
}
void insert_scll(char key)
{
	struct ll *list_node_sll;
	list_node_sll = malloc(sizeof(struct ll));
	list_node_sll->data = key;
	list_node_sll->next = NULL;
	// if no elements then insert at the beginning
	if(start == NULL)
	{
		start = end = list_node_sll;
		end->next = start;
	}
	// if there are elements then insert at the end
	else
	{
		end->next = list_node_sll;
		list_node_sll->next = start;
		end = list_node_sll;
	}
	count++;
}
void insert_dcll(char key)
{
	struct ll *list_node_dcll;
	list_node_dcll = malloc(sizeof(struct ll));
	list_node_dcll->data = key;
	list_node_dcll->next = NULL;
	list_node_dcll->prev = NULL;
	// if no elements then insert at the beginning
	if(start == NULL)
	{
		start = end = list_node_dcll;
		end->next = start;
		start->prev=end;
	}
	// if there are elements then insert at the end
	else
	{
		end->next = list_node_dcll;
		list_node_dcll->prev = end;
		list_node_dcll->next = start;
		start->prev = list_node_dcll;
		end = list_node_dcll;
	}
	// counting the number of nodes.
	count++;

}
void delete_scll(int key)
{
	int i;
	struct ll *trace_node_scll,*trace_back_node_scll=NULL;
	if(key>count)
	{
		printf("Number of elements in list is less tha %d, so deletion is not possible\n",key);
	}
	else
	{
		// go to the node		
		i = 1;		
		trace_node_scll = start;
		while(i<key)
		{
			i++;
			trace_back_node_scll = trace_node_scll;
			trace_node_scll = trace_node_scll->next;
		}
		// reached at the node and
		// if it is a first node to be deleted
		if(trace_node_scll==start)
		{
			// if it is the only node.
			if(start->next == start)
				start = end = NULL;
			else
			{
				start = start->next;
				end->next = start;
			}
		}
		// if it is the end node to be deleted
		else if(trace_node_scll == end)
		{
			trace_back_node_scll->next = start;
			end = trace_back_node_scll;
		}
		// if it is the middle element to be deleted
		else
		{
			trace_back_node_scll->next = trace_node_scll->next;
		}
		count--;	
	}
}
void delete_dcll(int key)
{
	int i;
	struct ll *trace_node_dcll,*trace_back_node_dcll=NULL,*next_node_dcll;
	if(key>count)
	{
		printf("Number of elements in list is less tha %d, so deletion is not possible\n",key);
	}
	else
	{
		// go to the node		
		i = 1;		
		trace_node_dcll = start;
		while(i<key)
		{
			i++;
			trace_back_node_dcll = trace_node_dcll;
			trace_node_dcll = trace_node_dcll->next;
		}
		// reached at the node and
		// if it is a first node to be deleted
		if(trace_node_dcll==start)
		{
			// if it is the only node.
			if(start->next == start)
				start = end = NULL;
			else
			{
				start = start->next;
				start->prev = end;
				end->next = start;
			}
		}
		// if it is the end node to be deleted
		else if(trace_node_dcll == end)
		{
			trace_back_node_dcll->next = start;
			start->prev = trace_back_node_dcll;
			end = trace_back_node_dcll;
		}
		// if it is the middle element to be deleted
		else
		{
			next_node_dcll = trace_node_dcll->next;
			trace_back_node_dcll->next = trace_node_dcll->next;
			next_node_dcll->prev = trace_back_node_dcll;
			
		}
		count--;	
	}

}
void search_scll(char key)
{
	int i=0;
	struct ll *trace_node_sll;
	// start tracing at the beginning
	trace_node_sll = start;
	while(i<=count)
	{
		
		if(trace_node_sll->data == key)
		{
			printf("Element is found at location %d\n",i+1);
			break;
		}
		trace_node_sll = trace_node_sll->next;
		i++;
	}
	// if reached the end of the list then no elements
	if(i>count)
		printf("Element is not found \n");
}
void display_scll()
{
	int i=0;
	struct ll *trace_node_sll;
	// start tracing at the beginning
	trace_node_sll = start;
	if(count == 0)
		printf("No elements to display\n");
	else
	{
		while(i<count)
		{
			printf("%c ",trace_node_sll->data);
			trace_node_sll = trace_node_sll->next;
			i++;
		}
	}
}

