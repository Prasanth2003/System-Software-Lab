//program to implement Linked file allocation

#include<stdio.h>
#include<stdlib.h>
void main()
{
int f[50],p,i,j,k,a,st,len,n,c;
for ( i = 0; i < 50; i++)
{
f[i]=0;
}
while(1)
{
printf("Implementation of Linked file allocation\n\n");
printf("Enter number of disk blocks already allocated:- ");
scanf("%d",&p);
printf("Enter disk blocks already allocated:- ");
for(i=0;i<p;i++)
{
scanf("%d",&a);
f[a]=1;
}
X: printf("\nEnter starting block:- ");
scanf("%d",&st);
printf("Enter length of file:- ");
scanf("%d",&len);
k=len;
for(j=st;j<(k+st);j++)
{
if(f[j]!=1)
{
f[j]=1;
printf("Disk block %d allocated\n",j);
}
else
{
printf("Disk block %d is already allocated\n",j);
k++;
}
}
printf("Enter 1 if you want to continue else enter 0:- ");
scanf("%d",&c);
if(c==1)
goto X;
else
{
printf("Exiting program\n");
exit(0);
}
getchar( );
}
}