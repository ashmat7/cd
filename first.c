#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int f=0,z=0;
void first(int * input,int ** pro,char ch)
{
int p=1,j,i,t;
while(input[p]!='\0')
{
if(ch==input[p])
{
i=p;
break;
}
p++;
}
for(j=0;j<10;j++)
{
if(pro[i][j]!='\0')
{

if(isupper(pro[i][j]))
{
f++;
first(input,pro,pro[i][j]);
f--;
if(z!=0)
{
j++;
if(pro[i][j]!=35 && pro[i][j]!='\0')
printf("%c ",pro[i][j]);
z=0;
}
}
else
{
if(j==0)
{
printf("%c ",pro[i][j]);
}
else if(pro[i][j]==124)
{
j++;
if(isupper(pro[i][j]))
{
f++;
first(input,pro,pro[i][j]);
f--;
if(z!=0)
{
j++;
if(pro[i][j]!=35 && pro[i][j]!='\0')
printf("%c ",pro[i][j]);
z=0;
}
}
else if(f>0 && pro[i][j]==35)
{
j++;
z=1;
}
else
{
printf("%c ",pro[i][j]);
}
}
}
}
else
{
break;
}
}

}
int main()
{
int n,i,j,k,m;
char ch,str[10];
printf("Enter the no: of non-terminals");
scanf("%d",&n);
int * input=malloc(sizeof(char *)*n);
int ** pro=malloc(sizeof(char *)*n);
for(i=0;i<=n;i++)
{
pro[i]=malloc(sizeof(int *)*10);
}
printf("Enter the non-terminals");
for(i=0;i<=n;i++)
{
scanf("%c",&ch);
input[i]=ch;
}
input[i]='\0';
for(i=0;i<=n;i++)
{
ch=input[i];
printf("%c",ch);
}
i=1;

while(input[i]!='\0')
{
ch=input[i];
printf("Enter production of %c ",ch);
scanf("%s",str);
j=0;
k=0;
while(str[k]!='\0')
{
pro[i][j]=str[k];
k++;
j++;
}
pro[i][j]='\0';
i++;
}

k=1;
while(input[k]!='\0')
{
ch=input[k];
printf("\nfirst of %c ",ch);
first(input,pro,input[k]);
k++;
}
return 0;
}