#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
 int fd, zugriffszeiger=0, success; 
 char x[] = "Hallo"; 
 fd = open("./aufg8.txt", O_APPEND); 
 zugriffszeiger = lseek(fd, 0, SEEK_CUR); 
 printf("1. Mal: %d", zugriffszeiger); 
 success = write(fd, x, 5); 
 zugriffszeiger = lseek(fd, 0, SEEK_CUR); 
 printf("2. Mal: %d", zugriffszeiger); 
 return close(fd); 
}
