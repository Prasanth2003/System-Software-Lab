//program to implement Sequential file allocation

#include<stdio.h>
#include<stdlib.h>
void main()
{
int f[50],i,st,j,len,c,k;
for ( i = 0; i < 50; i++)
{
f[i]=0;
}
while(1)
{
printf("Implementation of Sequential file allocation\n");
X: printf("\nEnter starting block:- ");
scanf("%d",&st);
printf("Enter length of file:- ");
scanf("%d",&len);
for(j=st;j<(st+len);j++) 
{
if(f[j]!=1)
{
f[j]=1;
printf("Disk block %d is allocated\n",j);
}
else
{
printf("Disk Block %d already allocated\n",j);
break;
}
}
if(j==(st+len))
printf("File is successfully allocated to disk\n");
else
{
printf("File is not successfully allocated to disk\n");
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
getchar();
}
}