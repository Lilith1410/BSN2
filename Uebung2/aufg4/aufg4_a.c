#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
 int fd; 
 char x[] = "Hallo"; 
 fd = open("./aufg4.txt", O_RDWR); 
 write(fd, x, 5);  
 return 0; 
}
