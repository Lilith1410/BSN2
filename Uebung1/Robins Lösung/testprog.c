#include <stdio.h>
#include "file1.h"
#include "file2.h"

int main(void){
	int eingabe;
	printf("Geben Sie eine Zahl ein:");
	scanf("%d", &eingabe);

	printf("\nDie eingegebene Zahl +2 ist: %d \n", addTwo(eingabe));
	printf("\nDie eingegebene Zahl +7 ist: %d \n", addSeven(eingabe));
	return 0;
}
