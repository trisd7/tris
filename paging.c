#include<stdio.h>
int rempages,p,ms,ps,np,i,j,pa,offset,nop;
int x,y;
int s[10],fno[10][20];
void main(){
printf("\n enter memory size");
scanf("%d",&ms);
printf("\n enter page size");
scanf("%d",&ps);
nop=ms/ps;
printf("the no of available pages:%d",nop);
printf("\n enter no of processes:");
scanf("%d",&np);
rempages=nop;

for(i=1;i<=np;i++){
    printf("enter no of pages required for process p[%d]--",i);
    scanf("%d",&s[i]);
    if(s[i]>rempages){
        printf("full memory");
        break;
    }
    rempages=rempages-s[i];
     printf("enter page table for process p[%d]--",i);
    for( j=0;j<s[i];j++){
        scanf("%d",&fno[i][j]);
}
}
printf("enter logical add to phy address \n");
printf("enter process no,page number and offset");
scanf("%d %d %d",&x,&y,&offset);
if(x>np||y>=s[x]||offset>=ps){
    printf("invalid\n");
}
else{
    pa=fno[x][y]*ps+offset;
    printf("\n the physical address is --%d",pa);
}
 
}


