#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void){
 int fd; 

 fd = open("./test123.txt", O_RDONLY); 
 printf("Dateideskriptor: %d \n", fd); 
 sleep(60); 
 return 0; 
}
