# include <stdio.h>
# include <math.h>

int bytes[3];
int trans[3][2];
int dfa_tran[8][2],dfastates[8];

int exists(int n){
    for(int i=0;i<8;i++){
        if(dfastates[i]==n){
            return 1;
        }
    }
    return 0;
}

int addele(int n,int inp){
    // printf("n= %d\n",n);
    for(int i=0;i<3;i++){
        bytes[i]=0;
    }
    int i=2;
    while(n!=0){
        bytes[i]=n%10;
        n=n/10;
        i--;
    }
    int str=0;
    for(int i=0;i<3;i++){
        if(bytes[i]==1){
            str=str|trans[2-i][inp];
        }
    }
    return str;
}

int findbin(int n){
    int binary;
    if (n == 0)
      binary = 0;
   else
      binary = n%2+10*findbin(n/2);

    return binary;
}

int main(){
    int nstates,nsym,ndfa,flag=1,k=0,l=0;
    printf("Enter the nstates and nsym : ");
    scanf("%d %d",&nstates,&nsym);
    ndfa=pow(2,nstates);
    // printf("or is %d ",5|2);
    printf("%d",findbin(2));
    printf("Enter the table of NFA : \n");

    for(int i=0;i<nstates;i++){
        for(int j=0;j<nsym;j++){
            scanf("%d",&trans[i][j]);
        }
    }

    printf("Trans table is : \n");
    dfa_tran[0][0]=trans[0][0];
    dfa_tran[0][1]=trans[0][1];
    k=1;
    while(flag==1){
        if(exists(dfa_tran[k-1][0])&&exists(dfa_tran[k-1][1])){
            flag=0;
        }
        if(!exists(dfa_tran[k-1][0])){
            dfastates[l]=dfa_tran[k-1][0];
            dfa_tran[l+1][0]=addele(findbin(dfa_tran[k-1][0]),0);
            printf("\n\n\n %d\n\n",dfa_tran[l+1][0]);

            dfa_tran[l+1][1]=addele(findbin(dfa_tran[k-1][0]),1);
            l++;
        }
        if(!exists(dfa_tran[k-1][1])){
            // printf("\n\n\n %d\n\n",dfa_tran[k-1][1]);
            dfastates[l]=dfa_tran[k-1][1];
            dfa_tran[l+1][0]=addele(findbin(dfa_tran[k-1][1]),0);
            printf("\n\n\n %d\n\n",dfa_tran[l+1][0]);

            dfa_tran[l+1][1]=addele(findbin(dfa_tran[k-1][1]),1);
            l++;
        }
        k++;
    }
    for(int i=0;i<8;i++){
        printf("%d ",dfastates[i]);
    }
    for(int i=0;i<8;i++){
        printf("\n");
        for(int j=0;j<2;j++){
            printf("%d\t",dfa_tran[i][j]);
        }
    }
    int a;
    for(int i=0;i<8;i++){
        for(int j=0;j<2;j++){
            if(dfa_tran[i][j]!=0){
                int f=findbin(dfa_tran[i][j]);
                int i=0,j=0;
                while(f!=0){
                    if(f%10!=0){
                        a=a*10+i;
                    }
                }
                printf("%d ",a);
            }
        }
    }

    // for(int i=0;i<nstates;i++){
    //     for(int j=0;j<nsym;j++){
    //         printf("%d",trans[i][j]);
    //     }
    // }
}
