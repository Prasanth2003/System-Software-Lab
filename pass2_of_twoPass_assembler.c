//Program to implement pass two of two pass assembler
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main()
{
FILE *f1,*f2,*f3,*f4;
f1=fopen("INTER.txt","r");
f2=fopen("length.txt","r");
f3=fopen("symtab.txt","r");
f4=fopen("optab.txt","r");
char la[10],mne[10],op[10],addr[10],optab[10],op1[10],sym[10];
int saddr,len,symval;
fscanf(f2,"%X",&len);
fscanf(f1,"%s %s %s %X",addr,la,mne,&saddr);
printf("H^%s ^00%X^0000%X\nT^00%X",la,saddr,len,saddr);
fscanf(f1,"%s %s %s %s",addr,la,mne,op);
while(!feof(f1))
{
fscanf(f4,"%s %s",optab,op1);
while(!feof(f4))
{
if(strcmp(optab,mne)==0)
{
fscanf(f3,"%s %X",sym,&symval);
while(!feof(f3))
{
if(strcmp(sym,op)==0)
{
printf("^%s%X",op1,symval);
}
fscanf(f3,"%s %X",sym,&symval);
}
}
fscanf(f4,"%s %s",optab,op1);
}
fseek(f4,SEEK_SET,0);
fseek(f3,SEEK_SET,0);
if(strcmp(mne,"WORD")==0)
printf("^00000%s",op);
if(strcmp(mne,"BYTE")==0)
{
int len=strlen(op);
printf("^");
for(int i=2;i<len;i++)
{
printf("%X",op[i]);
}
}
fscanf(f1,"%s %s %s %s",addr,la,mne,op);
}
printf("\nE^00%X\n",saddr);
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
}
