#include <stdio.h>
#include <sys/stat.h>

/*Erwartet einen Dateinamen als Parameter und gibt zurück, welche Art Datei es ist (Ordner, Datei, programm, ...) */ 

int main(int argc, char* argv[]){
 struct stat stat_buf; 
 int i; 

 if (argc > 2 || argc < 2){
  printf("Falsche Anzahl Argumente übergeben: \n");
  printf("Bitte nur ein Wort als Dateinamen eingeben. ");   
 }

 i = lstat(argv[1], &stat_buf);

 if(S_ISREG(stat_buf.st_mode)){
  printf("Datei %s ist gewöhnliche Datei", argv[1]);
 } else if (S_ISDIR(stat_buf.st_mode)) {
  printf(" Datei %s ist Verzeichnis", argv[1]);
 } else if (S_ISCHR(stat_buf.st_mode)) {
  printf(" Datei %s ist zeichenorientierte Gerätedatei", argv[1]);
 } else if (S_ISBLK(stat_buf.st_mode)) {
  printf(" Datei %s ist blockorientierte Gerätedatei", argv[1]);
 } else if (S_ISFIFO(stat_buf.st_mode)) {
  printf(" Datei %s ist named Pipe bzw. FIFO", argv[1]);
 } else if (S_ISLNK(stat_buf.st_mode)) {
  printf(" Datei %s ist symbolischer Link", argv[1]);
 }
 return 0; 
}
