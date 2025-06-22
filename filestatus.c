#include <stdio.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <dirent.h> 
#include <unistd.h> 
#include <string.h> 
struct stat statbuf; 
char dirpath[256]; 
int main(int argc, char *argv[]) { 
// Get current working directory 
getcwd(dirpath, 256); 
// Open the directory 
DIR *dir = opendir(dirpath); 
if (dir == NULL) { 
perror("opendir failed"); 
return 1; 
} 
struct dirent *dp; 
// Read directory entries 
for (dp = readdir(dir); dp != NULL; dp = readdir(dir)) { 
stat(dp->d_name, &statbuf); 
printf("The file name is %s \n", dp->d_name); 
printf("Dir = %d\n", S_ISDIR(statbuf.st_mode)); 
printf("File size is %ld bytes \n", statbuf.st_size); 
printf("Last modified time is %ld seconds \n", statbuf.st_mtime); 
printf("Last access time is %ld seconds \n", statbuf.st_atime); 
printf("The device containing the file is %ld\n", statbuf.st_dev); 
printf("File serial number is %ld\n\n", statbuf.st_ino); 
} 
// Close directory 
closedir(dir); 
return 0; 
}
