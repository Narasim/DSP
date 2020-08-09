#include<stdio.h>
int main(){

  int n,i,j,temp,a[20];

  printf("Enter total elements: ");
  scanf("%d",&n);

  printf("Enter %d elements: ",n);
  for(i=0;i<n;i++)
      scanf("%d",&a[i]);

  for(i=0;i<n;i++){
      for(j=i+1;j<n;j++){
           if(a[i]>a[j]){
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;
           }
      }
  }

  printf("After sorting is: ");
  for(i=0;i<n;i++)
      printf(" %d",a[i]);

  return 0;
}