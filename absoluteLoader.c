//Program to implement absolute loader
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
FILE* f1;
f1=fopen("abs.txt","r");
char name[10],name_obj[10],line[50],staddr_obj[6];
int staddr;
printf("Enter the program name to be loaded:");
scanf("%s",name);
int i,j;
fscanf(f1,"%s",line);
for(i=2,j=0;i<8;i++,j++)
{
name_obj[j]=line[i];
}
name_obj[j]='\0';
printf("\nThe program name in .obj is:%s\n",name_obj);
if(strcmp(name,name_obj)==0)
{
printf("\nThe contents of memory are:\n");
fscanf(f1,"%s",line);
while(!feof(f1))
{
if(line[0]=='T')
{
for(i=2,j=0;i<8;i++,j++)
{
staddr_obj[j]=line[i];
}
staddr_obj[j]='\0';
staddr=atoi(staddr_obj);
i=12;
while(line[i]!='$')
{
if(line[i]!='^')
{
printf("00%d 
\t%c%c\n",staddr,line[i],line[i+1]);
i+=2;
}
else
{
i++;
}
}
}
fscanf(f1,"%s",line);
}
}
else
{
printf("%s.obj doesnot exists\n",name);
}
fclose(f1);
}
