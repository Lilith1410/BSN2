#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
 int fd, i; 
 char x[10]; 
 fd = open("./aufg7text.txt", O_RDONLY); 
 read(fd, x, 10); 
 for (i = 0; i < 10; ++i){
  printf("%c", x[i]);
 }

 close(fd); 
 return 0; 
}
