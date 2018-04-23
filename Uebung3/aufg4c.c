#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Liest Textdatei Zeileweise ein. */ 

int main(void){
 char s[100]; 
 while(fgets(s, 50, stdin) != NULL){
  fputs(s, stdout);  
 }
 return 0; 
}
