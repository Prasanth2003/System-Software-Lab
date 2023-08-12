//program to implement Single level directory 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct
{
	char dname[10],fname[10][10];
	int fcnt;
}dir;
void main()
{
	int i,ch;
	char f[30];
	dir.fcnt = 0;
	printf("Implementation of single level directory\n\n");
	printf("Enter directory name:- ");
	scanf("%s", dir.dname);
	printf("MENU\n");
	printf("1. Create File\n2. Delete File\n3. Search File\n4. List Files\n5.Exit\n");
		while(1)
		{
			printf("\nEnter your choice:- ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: printf("Enter file to be created:- ");
				scanf("%s",dir.fname[dir.fcnt]);
				dir.fcnt++;
				printf("File successfully created\n");
				break;
				case 2: printf("Enter file to be deleted:- ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f, dir.fname[i])==0)
					{
						printf("File %s is deleted !!!\n",f);
						strcpy(dir.fname[i],dir.fname[dir.fcnt-1]);
						break;
					}
				}
				if(i==dir.fcnt)
				printf("File %s not found\n",f);
				else
				dir.fcnt--;
				break;
				case 3: printf("Enter file to be searched:- ");
				scanf("%s",f);
				for(i=0;i<dir.fcnt;i++)
				{
					if(strcmp(f, dir.fname[i])==0)
					{
						printf("File %s is found !!!\n", f);
						break;
					}
				}
				if(i==dir.fcnt)
				printf("File %s not found\n",f);
				break;
				case 4: if(dir.fcnt==0)
				printf("Current Directory is Empty\n");
				else
				{
					printf("Listing files ....\n ");
					for(i=0;i<dir.fcnt;i++)
					printf("%s ",dir.fname[i]);
				}
				printf("\n");
				break;
				default: printf("Exiting the menu\n");
				exit(0);
			}
		}
		getchar();
}	