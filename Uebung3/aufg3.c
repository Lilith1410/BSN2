#include <stdio.h>
#include <string.h>

/*Gibt alle Fehlercodes der Reihe nach aus, sowie die zugehörigen Erklärungen. */ 

int main(void){
 int no; 

 for ( no = 1; no <= 99; ++no){
  printf("%d %s\n", no, strerror(no)); 
 }
 return 0; 
}
