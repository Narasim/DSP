/* 
Author 		: Y NARASIMHULU
Roll No		: 18MCPC17
LAB		: DSP LAB ASSIGNMENT 3
OBJECTIVE	: Write a program to implement two stacks in a single array.
		  Accept your name in one stack and display the name in reverse in another stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void push(char c, int top);
char pop(int top);

char arr[50];
int main()
{


	int i,j,n,top=-1,top1,test_cases;
	char ch;
	FILE *fp;
	fp = fopen("testcase_DSP_lab3.txt","r");
	if(fp==NULL){
		printf("Error: File Open\n");
		exit(1);
	}
	fscanf(fp,"%d",&test_cases);
	/* Test case exception */
	if(test_cases>0 || isalpha(test_cases))
	{
		while(test_cases>0)
		{		
			/* Read the string from the file*/
			fscanf(fp,"%s",arr);
			
			/* Finding the length of the string and pushing to Stack 1*/
			n=0;
			while(arr[n]!='\0')
			{
				push(arr[n],top++);
				n++;
			}

			printf("\nOriginal string is : %s",arr);
			
			/* Location for the second stack */
			top1 = top+n;

			/* Poping from stack 1 and pushing to stack 2 */
			while(top>=0)
			{
				push(pop(top--),top1--);
			}	

			printf("\n");

			/* Printing the reverse of the string */
			printf("Reverse of the string is: \n");
			for(i=top1+n+1;i>=top1+1;i--)
				printf("%c",arr[i]);
			printf("\n");
			test_cases--;
		}

	}
	else
	{
		printf("Number of test cases cannot be less than 1 or cannot be a aplhabet\n");
	}
}

/* ADT operations push and pop*/
void push(char c, int top)
{
	arr[++top]=c;
}

char pop(int top)
{
	return arr[top--];
}
