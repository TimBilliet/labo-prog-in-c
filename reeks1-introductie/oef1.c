#include <stdio.h>


int main(){

	printf("Hello world!\n");

	const int STARTWAARDE = 100;
	for(int i = STARTWAARDE; i > 0; i--) {
		printf("%d ", i);
	}
	printf("\nSTART\n");
	return 0;
}
