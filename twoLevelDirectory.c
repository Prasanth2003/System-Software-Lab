//program to implement two level directory 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
char dname[10],fname[10][10];
int fcnt;
}dir[10];
void main()
{
int i,ch,dcnt,k;
char f[30], d[30];
dcnt=0;
printf("Implementation of two level directory\n\n");
printf("MENU\n");
printf("1. Create Directory\n2. Create File\n3. Delete File");
printf("\n4. Search File\n5. List files\n6. Exit\n");
while(1)
{
printf("\nEnter your choice:- ");
scanf("%d",&ch);
switch(ch)
{
case 1: printf("Enter directory name:- ");
scanf("%s", dir[dcnt].dname);
dir[dcnt].fcnt=0;
dcnt++;
printf("Directory successfully created !!!\n");
break;
case 2: printf("Enter directory name:- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
{
if(strcmp(d,dir[i].dname)==0)
{
printf("Enter file name:- ");
scanf("%s",dir[i].fname[dir[i].fcnt]);
dir[i].fcnt++;
printf("File successfully created !!!\n");
break;
}
}
if(i==dcnt)
printf("Directory %s not found\n",d);
break;
case 3: printf("Enter directory name:- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
{
if(strcmp(d,dir[i].dname)==0)
{
printf("Enter file name:- ");
scanf("%s",f);
for(k=0;k<dir[i].fcnt;k++)
{
if(strcmp(f, dir[i].fname[k])==0)
{
printf("File %s is deleted\n",f);
dir[i].fcnt--;
strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
goto jmp;
}
}
printf("File %s not found\n",f);
goto jmp;
}
}
printf("Directory %s not found\n",d);
jmp : break;
case 4: printf("Enter directory name:- ");
scanf("%s",d);
for(i=0;i<dcnt;i++)
{
if(strcmp(d,dir[i].dname)==0)
{
printf("Enter file name:- ");
scanf("%s",f);
for(k=0;k<dir[i].fcnt;k++)
{
if(strcmp(f, dir[i].fname[k])==0)
{
printf("File %s is found\n",f);
goto jmp1;
}
}
printf("File %s not found\n",f);
goto jmp1;
}
}
printf("Directory %s not found",d);
jmp1: break;
case 5: if(dcnt==0)
printf("No Directories currently available to be displayed\n");
else
{
printf("Directory\tFiles");
for(i=0;i<dcnt;i++) 
{
printf("\n%s\t",dir[i].dname);
for(k=0;k<dir[i].fcnt;k++)
printf("\t%s",dir[i].fname[k]);
}
}
printf("\n");
break;
default:printf("Exiting from the menu\n");
exit(0);
}
}
getchar();
}
