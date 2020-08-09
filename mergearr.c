#include<stdio.h>
int main()
{
int a[10],b[10],c[20],i,j,sizec,n,m;
printf("Enter size of array 1:");
scanf("%d",&n);
printf("Enter elements of array 1:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter size of array 2:");
scanf("%d",&m);
printf("Enter elements of array 2:");
for(i=0;i<m;i++)
scanf("%d",&b[i]);

sizec=n+m;
for(i=0;i<n;i++)
c[i]=a[i];

for(j=0;j<m;j++)
{
c[i]=b[j];
i++;
}

printf("\nElements of merged array are:");
for(i=0;i<sizec;i++)
printf(" %d ",c[i]);

}