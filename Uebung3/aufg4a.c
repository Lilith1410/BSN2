#include <stdio.h>
#include <stdlib.h>

/*Liest Textdatei Zeichenweise ein. */ 
/* Alternativ: ((c = getc(stdin)) != EOF) -> dann kann aber auf fgetc verzichtet werden, 
da c an dieser stelle schon gelesen wurde. Ansonsten wird nur jeder zweite Buchstabe eingelesen ;) */ 

int main(void){
 int c = 1; 
 while(c != EOF){
  c = fgetc(stdin); 
  fputc(c, stdout);  
 }
 return 0; 
}
