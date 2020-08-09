#include<stdio.h>
int factorial(int n);
int rfactorial(int m);
int main()
{
	int n,m;
	printf("enter a two values for factorial");
	scanf("%d%d",&n,&m);
	factorial(n);
	printf("\nfactorial is %d", factorial(n));
	printf("\nRecursive factorial is %d", rfactorial(m));
	
	
}

int factorial(int n)
{
	
	int fact=1,i;
	for(i=n;i>=1;i--)
	{
		fact=fact*i;
		
	}
	
	return fact;
}

int rfactorial(int m)
{
	
	if(m==1)
	{
		return 1;		
	}
	else{
		return m*rfactorial(m-1);
		
	}
}

