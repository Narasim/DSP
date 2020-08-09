#include<stdio.h>
void toh(int n,char s, char d, char i);
int main()
{
int n;
char s='A',d='C',i='B';
printf("enter no of disks");
scanf("%d", &n);

printf("1-Source\n2-Intermerdiate\n3-Destination");

toh(n,s,d,i);

}

void toh(int n,char s, char d, char i)
{
	if(n==1)
		printf("\nmove disk from %c to %c", s,d);
	else{
		
		toh(n-1,s,i,d);
		printf("\nmove disk from %c to %c", s,d);
		toh(n-1,i,d,s);
	}
	
}