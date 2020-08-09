#include<stdio.h>
#include<string.h>
int main()
{
	int h,i,index,sumkey,j;
	char keys[20][30],hashtable[20][30];
	printf("\n enter the size of the hash table");
	scanf("%d",&h);
	printf("\n enter the strings");
	for(i=0;i<h;i++)
	{
		scanf("%s",keys[i]);
		
		strcpy(hashtable[i],"NULL");
		/*printf("hash table %s and keys %s",hashtable[i],keys[i]);*/
	}
	for(i=0;i<h;i++)
	{
		sumkey=0;
		
		for(j=0;keys[i][j]!='\0';j++)
		{
			sumkey+=keys[i][j];	
		}
		printf("\n%s the sum key is %d\n",keys[i],sumkey);
		index=(sumkey%h);
		strcpy(hashtable[index],keys[i]);	
	}
	for(i=0;i<h;i++)
	{
		
		printf("%s at %d \n",hashtable[i],i);
		
	}
	
	return 0;
}