/* 
Author 		: Y NARASIMHULU
Roll No		: 18MCPC17
LAB		: DSP LAB ASSIGNMENT 9
OBJECTIVE	: Given trouser and shirt colors of n members, check whether the members are ordered in a way that, 
		  trouser color of a person is equal to shirt color of the next person, if no, modify the colors to retain the order.
*/

#include <stdio.h>
#include <stdlib.h>

struct person
{
	int shirt, trouser;
	struct person *next;
}*start=NULL,*end=NULL,*node=NULL,*temp;

void main()
{
	int testcases,n,i;
	FILE *fp;
	fp=fopen("testcases.txt","r");
	if(fp==NULL)
	{
		printf("Error: File Open\n");
		exit(1);
	}
	else
	{
		fscanf(fp,"%d",&testcases);
		if(testcases<=0 && isalpha(testcases))
		{
			printf("Test cases cannot be less than or equal to zero\n");
			exit(0);
		}
		else
		{
			while(testcases>0)
			{
				fscanf(fp,"%d",&n);
				if(n<=0)
				{
					printf("number of persons cannot be less than or equal to zero\n");
				}
				else
				{
					start = end = NULL;
					printf("Initial colors are:\n");
					for(i=0;i<n;i++)
					{
						node = malloc(sizeof(struct person));
						fscanf(fp,"%d%d",&node->shirt,&node->trouser);
						node->next=NULL;
						if(start==NULL)
						{
							start = node;
							end = node;
							end->next = start;
						}
						else
						{
							end->next = node;
							node->next = start;
							end = node;
						}
						printf("%d%d  ",end->shirt,end->trouser);

					}
					printf("\n");
					printf("Final list\n");
					node = start;
					while(node->next!=start)
					{
						temp = node->next;
						if(node->trouser!=temp->shirt)
						{
							temp->shirt = node->trouser;
						}
						printf("%d%d  ",node->shirt,node->trouser);
						node = temp;
						temp = temp->next;
					}
					node->trouser = start->shirt;
					printf("%d%d",node->shirt,node->trouser);
				}
				printf("\n");
				testcases--;
			}
		}
	}




}