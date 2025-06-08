#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct msg_buffer
{
long msg_type;
char msg[100];

}message;
int main(){
key_t mykey;
int msg_id;
mykey=ftok("programfile",85);
msg_id=msgget(mykey,0666|IPC_CREAT);
msgrcv(msg_id, &message, sizeof(message), 120, 0);
printf("received message is:%s\n",message.msg);
msgctl(msg_id,IPC_RMID,NULL);
return 0;
}
