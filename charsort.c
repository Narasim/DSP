#include <stdio.h>
#include <string.h>
int main()
{

	char str[50][50],temp[50];
	int i,j,n;
	printf("Enter value of n");
	scanf("%d",&n);
	printf("Enter values/strings: ");
	for(i=0;i<n;i++)
	scanf("%s",str[i]);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(str[i],str[j])<0)
			{
				strcpy(temp,str[i]);
				strcpy(str[i],str[j]);
				strcpy(str[j],temp);
			}
		}
	}

	for(i=0;i<n;i++)
		printf("%s ",str[i]);

	
}