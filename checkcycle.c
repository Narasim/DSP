/* 
Author 		: Y NARASIMHULU
Roll No		: 18MCPC17
LAB		: DSP LAB ASSIGNMENT 8
OBJECTIVE	: Write a program to find the starting node if there exist a cycle in a linked list.
*/

#include <stdio.h>
#include <stdlib.h>

struct cycle
{
	int data;
	struct cycle *next;
}*start=NULL,*end=NULL,*loop=NULL,*listnode,*cyclenode=NULL,*temp=NULL;

void main()
{
	int input,n,i,test_cases,ele,cyclen,j;
	FILE *fp;
	fp = fopen("testcase.txt","r");
	if(fp==NULL) // File Exception
	{
		printf("Error: File Open\n");
		exit(1);
	}
	else
	{
		fscanf(fp,"%d",&test_cases);

		if(test_cases>0) // Testcase Exception
		{
			start = NULL;
			end = NULL;
			while(test_cases>0)
			{
				printf("***** OUTPUT *****\n");
				fscanf(fp,"%d",&n);
				if(n>0) // Number of nodes Exception
				{
					fscanf(fp,"%d",&cyclen);
					start = NULL;
					if(cyclen>0 && cyclen<n) // Cycle location exception
					{
						for(i=0;i<n;i++)
						{
							fscanf(fp,"%d",&ele);
							listnode = malloc(sizeof(struct cycle));
							listnode->data = ele;
							listnode->next = NULL;
							if(start == NULL)
							{
								start = listnode;
								end = listnode;
							}
							else
							{
								end->next = listnode;
								end = listnode;
							}
							if(i==cyclen-1)
							{
								cyclenode = listnode;
							}
							printf("%d\t",end->data);
						}
						end->next = cyclenode;
						temp = start;
						i = 0;
						while(i<n)
						{
							loop = temp;
							j=0;
							while(loop->next!=temp && j<n)
							{
								loop = loop->next;
								j++;
							}
							if(j<n)
							{
								printf("Cycle exist at location %d\n",i+1);
								break;
							}
							else
							{
							temp = temp->next;
							}
							i++;
						}
						if(i==n)
						{
							printf("There exist no cycle\n");
						}
					}
					else
					{
						printf("Cycle location cannot be less than or equal to zero, or it cannot be greater than %d\n",n);
						printf("Exit from the program\n");
						exit(0);
					}
				}
				else
				{
					printf("number of elements cannot be less than zero\n");
					printf("Exit from the program\n");
					exit(0);
				}
				test_cases--;	
			}
		}
		else
		{
			printf("Testcases cannot be less than zero\n");
		}
	}
}
