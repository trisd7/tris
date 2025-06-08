#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main(){
int n;
void producer();
void consumer();
 int wait(int);
int signal(int);
printf("\n1.producer\n2.consumer\n3.exit");
while(1){
printf("\n enter choice:");
scanf("%d",&n);
switch(n)
{
case 1:if((mutex==1)&&(empty!=0))
producer();

else
  printf("buffer full");
  break;
case 2:if((mutex==1)&&(full!=0))
consumer();
else
 printf("empty");
 break;
case 3:
 exit(0);
}
}
return 0;
}

int wait(int s){
return(--s);
}
int signal(int s){
return (++s);
}
void producer(){
empty=wait(empty);
mutex=wait(mutex);
x++;
printf("producer produces item %d",x);
mutex=signal(mutex);
full=signal(full);
}
void consumer(){
full=wait(full);
mutex=wait(mutex);
printf("\n consumer consumes item %d",x);
x--;
mutex=signal(mutex);
empty=signal(empty);
}
