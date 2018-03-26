#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
 int fd, i; 
 char x[] = "Hello "; 

 creat("./aufg5.txt", S_IWUSR); 
 fd = open("./aufg5.txt", O_SYNC); 
 for(i = 0; i < 30000; ++i){
  write(fd, x, 6); 
 }
 close(fd); 
 return 0; 
}
