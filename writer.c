#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msg_buffer{
long msg_type;
char msg[100];
}message;
int main(){
key_t mykey;
int msg_id;
mykey=ftok("programfile",85);
 msg_id=msgget(mykey,0666|IPC_CREAT);
message.msg_type=120;
printf("write message:");
fgets(message.msg,100,stdin);
msgsnd(msg_id,&message,sizeof(message),0);
printf("sent message is :%s\n",message.msg);
return 0;
}
