//program to implement Indexed file allocation

#include<stdio.h>
#include <stdlib.h>
void main()
{
int f[50],i,k,j,inde[50],n,c,count=0,p;
for ( i = 0; i < 50; i++)
f[i]=0;
while(1)
{
printf("Implementation of Indexed file allocation\n");
x: printf("\nEnter index block:- ");
scanf("%d",&p);
if(f[p]!=1)
{ 
f[p]=1;
printf("Enter number of disk blocks to be allocated:- ");
scanf("%d",&n);
}
else
{
printf("Disk Block %d already allocated\n",p);
goto y;
}
printf("Enter disk blocks to be allocated:- ");
for(i=0;i<n;i++)
scanf("%d",&inde[i]);
for(i=0;i<n;i++)
{
if(f[inde[i]]==1)
{ 
printf("Disk Block %d already allocated\n",inde[i]);
goto y;
}
} 
for(j=0;j<n;j++)
f[inde[j]]=1;
printf("Disk block %d successfully allocated as index block\n",p);
printf("Disk blocks allocated are:- ");
for(k=0;k<n;k++)
printf("%d ",inde[k]);
printf("\n");
y: printf("Enter 1 if you want to continue else enter 0:- ");
scanf("%d",&c);
if(c==1)
goto x;
else
{
printf("Exiting program\n");
exit(0);
}
getchar();
}
}
