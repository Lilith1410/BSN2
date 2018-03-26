#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
 int fd, zugriffszeiger=0; 
 char x; 
 fd = open("./aufg8.txt", O_RDONLY); 
 zugriffszeiger = lseek(fd, 0, SEEK_END); 
 printf("%d", zugriffszeiger); 
 close(fd); 
 return 0; 
}
