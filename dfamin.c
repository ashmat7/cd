#include<stdio.h>

//checks if final state

int chkfinal(int d,int n,int f[n])
{
int i;
for(i=0;i<n;i++)
{
if(d==f[i])
{
return 1;
}
}

return 0;
}
//prints minimized

// void   printmini(int i,int s,int ip,int t[s][ip+1],int ks,int un[ks])
// {
// p=check(i,ks,un);
// if(p==-1)
// {

// }
   
// }

// main function


 void main()
 {
  int s,i,j,n,ip,flag=1,p,q,k,ks,fl=0,st;
char ch='a';

  printf("Enter no of states - ");
  scanf("%d",&s);
printf("Enter no of inputs - ");
  scanf("%d",&ip);
int a[s-1][s-1];
int t[s][ip+1];


  printf("Enter no of final states - ");
  scanf("%d",&n);
int f[n];

 
printf("Enter the final states :- \n");
for(i=0;i<n;i++)
{   printf(" ->q");
scanf("%d",&f[i]);

}  


  for(i=0;i<s-1;i++)
  for(j=0;j<s-1;j++)
  {   if(i<j)
  a[i][j]=-1;
else
a[i][j]=-0;
  }

for(i=0;i<s-1;i++)
  {
for(j=0;j<s-1;j++)
{
if(a[i][j]!=-1)
{
if((chkfinal((i+1),n,f)==0 && chkfinal(j,n,f)==1)||(chkfinal((i+1),n,f)==1 && chkfinal(j,n,f)==0))
     a[i][j]=1;
}
}
}



    printf("\nEnter the transitions :- \n\nState ");
for(i=0;i<ip;i++)
      printf("%d ",i);
    printf("\n");

for(i=0;i<s;i++)
{
      printf("->q%d  ",i);
 t[i][0]=i;
 for(j=1;j<ip+1;j++)
scanf("%d",&t[i][j]);

}



while(flag==1)
{




 flag=0;
      for(i=0;i<s-1;i++)
  {
for(j=0;j<s-1;j++)
{
if(a[i][j]==0)
{

                   for(k=1;k<ip+1;k++)
   {
p=t[i+1][k];
q=t[j][k];
if(a[p-1][q]==1 && p>0)
   {
a[i][j]=1;
//printf("%d %d maari with %d %d\n",i,j,p-1,q);
flag=1;
break;

}
       }
}
}
}  

}

    ks=0;
    for(i=0;i<s-1;i++)
  {
for(j=0;j<s-1;j++)
{
if(a[i][j]==0)
   ks++;
}
}

int un[ks][3];
    k=0;

for(i=0;i<s-1;i++)
  {
for(j=0;j<s-1;j++)
{
if(a[i][j]==0)
 {
 un[k][1]=i+1;
 un[k++][2]=j;

 }  
}
}

    int no=-1;
    un[0][0]=no;

for(i=1;i<ks;i++)
{   fl=0;
for(j=0;j<i;j++)
{
if(un[i][1]==un[j][1]||un[i][1]==un[j][2]||un[i][2]==un[j][1]||un[i][2]==un[j][2])
{
fl=1;
un[i][0]=un[j][0];
break;
}
}
if(fl==0)
{
un[i][0]=--no;
}
     
}

    int min[s];
int ms=0;

printf("\n\n");
fl=1;
p=-1;
while(fl==1)
{ fl=0;
       
  for(i=0;i<s;i++)
  {
  for(j=0;j<ks;j++)
  {
  if(un[j][0]==p && (un[j][1]==i||un[j][2]==i) )
  {
  fl=1;
  printf("q%d ",i);
  break;

  }
  }
  }
  if(fl==1)
  printf(" ->q%c \n",96-p);
  p--;
}

      printf("\n\nST\t\ttransitions");

for(i=0;i<s;i++)
 {
fl=0;
st=i;
for(k=0;k<ks;k++)
{
if(i==un[k][1]||i==un[k][2])
{
st=un[k][0];
break;
}
}

for(j=0;j<ms;j++)
{
if(st==min[j])
{
fl=1;
break;
}
}
 

if(fl==0)
{  
printf("\n");
min[ms]=st;
ms++;
if(st<0)
printf("q%c   ",96-st);
else
printf("q%d   ",st);
                   
for(j=1;j<ip+1;j++)
{  fl=0;
for(k=0;k<ks;k++)
   {
if(t[i][j]==un[k][1]||t[i][j]==un[k][2])
{
fl=1;
break;
}
   }

if(fl==0)
  printf("q%d ",t[i][j]);
else
{
                       printf("q%c ",96-un[k][0]);
}


}

}

     }
 }
