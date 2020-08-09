/* 
Author 		: Y NARASIMHULU
Roll No		: 18MCPC17
LAB		: DSP LAB ASSIGNMENT 4
OBJECTIVE	: Implement n number of queues where insertion is done at the rear end of the queue
		  with less data and deletion is done at front of any random queue.
*/
void insert_queue(char a, int j);
void delete_queue();
#include <stdio.h>
#include <stdlib.h>
char q[50][50],ch[2];
int f[50],r[50];
int d,n;
int main()
{
	int i,j,less,less_i,test_cases,op;
	FILE *fp;
	fp = fopen("testcase.txt","r");
	if(fp==NULL){
		printf("Error: File Open\n");
		exit(1);
	} 
	/* Take test cases */
	fscanf(fp,"%d",&test_cases);
	/* Check for test case exception */
	if(test_cases>0)
	{
		while(test_cases>0)
		{
			printf("****************OUTPUT************\n");
			d=0;
			fscanf(fp,"%d",&n);
			for(i=0;i<50;i++)
				f[i]=r[i]=0;
			fscanf(fp,"%d",&op);
			i=0;
			while(i<op)
			{
				fscanf(fp,"%s",ch);
				if(ch[0]=='i')
				{	
					j=1;
					less_i=0;
					less=r[0]-f[0];
					while(j<n)
					{
						if((r[j]-f[j])<less)
							less_i=j;
						j++;
					}
					insert_queue(ch[1],less_i);
				}
				else if(ch[0]=='d')
				{			
					delete_queue();
					d=(d+1)%n;
				}
				else
				{
					printf("Illegal operation\n");
				}
				i++;
			}
			printf("Elements in the queue are :\n");

			for(i=0;i<n;i++)
			{
				printf("Queue %d elements are :",i);
				if((r[i]-f[i])==0)
					printf("Queue is empty");
				else
				{
					for(j=f[i];j<r[i];j++)
					{
						printf(" %c",q[i][j]);
					}
				}
				printf("\n");
			}
			test_cases--;
		}
	}

}

void insert_queue(char a, int j)
{
	if(r[j]<50)
	{
	q[j][r[j]]=a;
	printf("%c is inserted in Queue %d at %d\n",q[j][r[j]],j,r[j]);
	r[j]++;
	}
	else
	{
		printf("The current queue is full, inserting in the next possible queue\n");
		insert_queue(a,j++);
	}
}

void delete_queue()
{
	int a=d,i=0;	
	while(i<n)
	{
		if((r[a]-f[a])>0)
			break;
		else
		{
			a=(a+1)%n;
			i++;
		}
		
	}
	if(i==n)
	{
		printf("no deletions possible \n");
	}
	else
	{
	printf("The data deleted is %c from the queue %d\n",q[a][f[a]],a);
	f[a]++;
	}
}
