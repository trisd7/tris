//SHMServer.c 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#define MAXSIZE   27 
int main() 
{ 
char c; 
int shmid; 
key_t key; 
char *shm, *s; 
key = 5678; 
if ((shmid = shmget(key, MAXSIZE, IPC_CREAT | 0666)) < 0) 
{ 
printf("shmget error"); 
return 1; 
} 
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) 
{ 
printf("shmat error"); 
return 1; 
} 
/* 
*      * Put some things into the memory for the 
*        other process to read. 
*        */ 
s = shm; 
for (c = 'a'; c <= 'z'; c++) 
*s++ = c; 
/* 
* Wait until the other process 
* changes the first character of our memory 
* to '*', indicating that it has read what 
* we put there. 
*/ 
while (*shm != '*') 
sleep(1); 
//detach from shared memory   
shmdt(shm); 
// destroy the shared memory 
shmctl(shmid,IPC_RMID,NULL); 
return 0; 
//exit(0); 
} 
//SHMClient.c 
#include <sys/types.h> 
#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 
#include <stdlib.h> 
#define MAXSIZE     27 
int main() 
{ 
int shmid; 
key_t key; 
char *shm, *s; 
key = 5678; 
if ((shmid = shmget(key, MAXSIZE, 0666)) < 0) 
{ 
printf("shmget error"); return 1; 
} 
if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) 
{ 
printf("shmat error"); 
return 1; 
} 
//Now read what the server put in the memory. 
for (s = shm; *s != '\0'; s++) 
putchar(*s); 
putchar('\n'); 
/* 
*Change the first character of the 
*segment to '*', indicating we have read 
*the segment. 
*/ 
*shm = '*'; 
exit(0); 
} 
Output: Run the two programs simultaneously on two terminals.
