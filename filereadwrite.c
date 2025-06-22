#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define BUFF_SIZE 1000
int main(void) {
int n, fd1, fd2;
char buff[BUFF_SIZE];
// Open the file for reading
fd1 = open("testfile.txt", O_RDWR);
if (fd1 == -1) {
perror("Error opening testfile.txt");
return 1;
}
// Read data from file
n = read(fd1, buff, BUFF_SIZE);
if (n == -1) {
perror("Error reading file");
close(fd1);
return 1;
}
// Create a new file using open
fd2 = open("fileforcopy2.txt", O_CREAT | O_RDWR, 0777);
if (fd2 == -1) {
perror("Error creating fileforcopy.txt");
close(fd1);
return 1;
}
// Writing data to file (fd2)
if (write(fd2, buff, n) != n) {
perror("Error writing to fileforcopy.txt");
close(fd1);
close(fd2);
return 1;
}
printf("File copying is successful. The data is:\n");
// Write to standard output (1 is stdout)
write(1, buff, n);
printf("\n");
// Closing the files
close(fd1);
close(fd2);
return 0;
}
