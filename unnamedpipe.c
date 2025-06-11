#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int fd[2];
if(pipe(fd)==-1)
{
printf("\n error in creating pipe");
exit (1);
}
if(fork()>0)
{
close(1);
dup(fd[1]);
close(fd[0]);
execlp("ls","ls",NULL);
}
else
{
close(0);
dup(fd[0]);
close(fd[1]);
execlp("sort","sort","-r",NULL);
}
return 0;
}
