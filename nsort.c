#include <stdio.h>
int main()
{

	int arr[50],n,i,j,val,k;
	printf("Enter value of n");
	scanf("%d",&n);
	printf("Enter values: ");
	scanf("%d",&arr[0]);
	for(i=1;i<n;i++)
	{
		scanf("%d",&val);
		k=i-1;
		while(k>=0 && arr[k]<=val)
		{
			k--;
		}
		for(j=i-1;j>k;j--)
		{
			arr[j+1]=arr[j];
		}
		arr[k+1]=val;
		
	}

	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

}