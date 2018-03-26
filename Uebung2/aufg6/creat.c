#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
 int fd, i; 
 char x[] = "Hello "; 
 fd = open("./creattest.txt", O_CREAT); 
 write(fd, x, 6); 
 close(fd); 
 return 0; 
}
