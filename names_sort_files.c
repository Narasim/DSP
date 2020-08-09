/* 
Author 		: Y NARASIMHULU
Roll No		: 18MCPC17
LAB		: DSP LAB ASSIGNMENT 2
OBJECTIVE	: Write a program by taking your friend names as input and sort them in ascending order 
		  on their lenght of the name. In addition, if the lenght of the names are the names 
		  are sorted aplhabetically.
***** Please ignore the warning generated as it doesnot affect the output.*****
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{

	int n,i,j,k,l,m,end,test_cases,t;
	char names[50][50],temp_input[50],temp_swap[50];
	FILE *fp;
	fp = fopen("testcase.txt","r");
	if(fp==NULL){
		printf("Error: File Open\n");
		exit(1);
	}

		/* Take test cases */
		fscanf(fp,"%d",&test_cases);
		/* Check for test case exception */
		if(test_cases>0 || isalpha(test_cases))
		{
			while(test_cases>0)
			{
				
				printf("\n");
				fscanf(fp,"%d",&n);/* Number of Names */
				/* Check for number of names exception */
				if(n<=0 || isalpha(n))
				{ 
					printf("Number of names cannot be less than 1 or cannot be an alphabet\n");
					fscanf(fp, "%*[^\n]\n", NULL);
				}
				else
				{
					fscanf(fp,"%s",names[0]);
					for(i=1;i<n;i++)
					{
						fscanf(fp,"%s",temp_input);
						k=i-1;
						end = k+1;

						/* Find the location for the name based on length */
						while(k>=0 && strlen(names[k])>=strlen(temp_input))
						{
							strcpy(names[k+1],names[k]);

						/* Find the sub array with equal length */
							if(strlen(names[k+1]) != strlen(temp_input))
								end = k;
							k--;
						}
						strcpy(names[k+1],temp_input);

						/* Sort names lexicographically of equal lenghts */
						for(l=k+1;l<=end;l++)
						{
							for(m=l+1;m<=end;m++)
							{
								if(strcmp(names[l],names[m])>0)
								{
									strcpy(temp_swap,names[l]);
									strcpy(names[l],names[m]);
									strcpy(names[m],temp_swap);
								}
							}
						}
		
					}
					printf("\n");
					for(i=0;i<n;i++)
						printf("%s\n",names[i]);
				}
				test_cases--;
			}
		}
		else{
			printf("Number of test cases cannot be less than 1 or cannot be a aplhabet\n");
	
		}
}
