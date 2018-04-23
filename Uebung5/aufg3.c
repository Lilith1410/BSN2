#include <unistd.h> 
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <wait.h> 

#ifndef MAX_ZEICHEN
#define MAX_ZEICHEN 30
#endif 

int main(void) {
  
  int pid, ppA, ppB, n, i; 
  int pipeA[2]; 
  int pipeB[2]; 
  char zeile[MAX_ZEICHEN]; 


  ppA = pipe(pipeA); 
  ppB = pipe(pipeB); /* pipes anlegen */

  pid = fork(); /* Kindprozess erzeugen */

  if(ppA < 0 || ppB < 0) {
    perror("Fehler beim pipen"); 
    exit(1); 
  } 
  if(pid < 0) {
    perror("Fehler beim forken"); 
    exit(1); 
  } 

  if( pid > 0) {
    close(pipeA[0]); /* Lesezugriff von pipeA geschlossen */
    close(pipeB[1]); /* Schreibzugriff von pipeB geschlossen */
    printf("Hier Eltern, bitte Zeile eingeben: \n");  
    while ( (wait(WIFEXITED)) == 0 ) { /* Mache so lange, bis Kind sich beendet hat */ 
      fgets(zeile, MAX_ZEICHEN, stdin); /* Schreibe in Array *zeile */
      if(strlen(zeile) < 10) exit(0);  
      write(pipeA[1], zeile, strlen(zeile)); /* schreibe die daten aus dem Array in die PipeA */
    }
    exit(0); 
    }


  } 
  
  if (pid == 0) {
    close(pipeA[1]); /* Schreibzugriff von pipeA geschlossen */
    close(pipeB[0]); /* Lesezugriff von pipeB geschlossen */

    n = read(pipeA[0], zeile, MAX_ZEICHEN); 

    if(n < 10) {
      exit(0); /* Wenn Zeile kleiner 10 Zeichen, beende dich Kind! */ 
    } 

    for ( i = 0; i < n; i++) {
      zeile[i] = toupper(zeile[i]); /* in Großbuchstaben wandeln */
    }

    printf("Hier Kind, Zeile in Groß: %s\n ", zeile); 
  }
  
  return 0; 
}
