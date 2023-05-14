#include "adt.h"

void init(struct numberADT *N,int no)
{
  N->size=no;
}
void insertElements(struct numberADT *N,int x[])
{
    for(int i=0;i<N->size;i++)
      N->a[i]=x[i];
}
void selSort(struct numberADT *N)
{
  int i,j,min,temp,pos;
  for(i=0;i<N->size-1;i++)
  {
    min=N->a[i];
    for(j=i+1;j<N->size;j++)
      if(min>N->a[j])
      {
        min=N->a[j];
        pos=j;
      }
      temp=N->a[i];
      N->a[i]=min;
      N->a[pos]=temp;
  }
}

void shellsort(struct numberADT *N)
{
  int gap,i,j,t;
  gap=N->size/2;
  while(gap>0)
  {
    for (int i = gap; i < N->size; i++) 
    {
        int j=i-gap;
        int temp = N->a[i];
        while(j>=0 && N->a[j]>temp)
        {
            N->a[j+gap] = N->a[j];
            j-=gap;
        }
        N->a[j+gap]=temp;
    }
    gap/=2;
  }
}
void display(struct numberADT *N)
{
    printf("Sorted array is\n");
    for(int i=0;i<N->size;i++)
        printf("%d ",N->a[i]);
}
