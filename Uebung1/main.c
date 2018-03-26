#include <stdio.h>
#include "file1.h"
#include "file2.h"


int main(void){
 int a; 
 printf("Bitte Zahl eingeben: \n");
 scanf("%d", &a);   

 printf("Die eingegebene Zahl + 7 ist %d\n", addSeven(a)); 
 printf("Die eingegebene Zahl + 2 ist %d\n", addTwo(a)); 

 return 0; 
}


