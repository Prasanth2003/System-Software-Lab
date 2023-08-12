//Program to implement pass one of two pass assembler
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
char la[10],mne[10],op[10],opt[10];
FILE *f1,*f2,*f3;
int lc,sa,o;
f1=fopen("input.txt","r");
f2=fopen("symtab.txt","w");
fscanf(f1,"%s %s %d",la,mne,&lc);
if(strcmp(mne,"START")==0)
{
sa=lc;
printf("\t%s\t%s\t%d\n",la,mne,sa);
}
fscanf(f1,"%s %s %s",la,mne,op);
while(strcmp(mne,"END")!=0)
{
if(strcmp(la,"-")!=0)
{
fprintf(f2,"%s\t%d\n",la,lc);
}
printf("%d\t%s\t%s\t%s\n",lc,la,mne,op);
//Searching OPTAB
f3=fopen("optab.txt","r");
fscanf(f3,"%s %d",opt,&o);
while(!feof(f3))
{
if(strcmp(opt,mne)==0)
{
lc+=3;
}
fscanf(f3,"%s %d",opt,&o);
}
fclose(f3);
//Assembler directives
if(strcmp(mne,"RESW")==0)
{
lc+=3*atoi(op);
}
else if(strcmp(mne,"RESB")==0)
{
lc+=atoi(op);
}
else if(strcmp(mne,"WORD")==0)
{
lc+=3;
}
else if(strcmp(mne,"BYTE")==0)
{
if(op[0]=='x')
{
lc+=1;
}
else
{
lc+=strlen(op)-2;
}
}
fscanf(f1,"%s %s %s",la,mne,op);
}
int plen;
if(strcmp(mne,"END")==0)
{
plen=lc-sa;
printf("%d\t%s\t%s\t%s\n",lc,la,mne,op);
}
fclose(f1);
fclose(f2);
printf("\nThe program length is:%d\n",plen);
}
