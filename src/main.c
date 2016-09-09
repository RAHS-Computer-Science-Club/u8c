/**
 * This code is in the Public Domain.  Feel free to modify and distribute at
 * will.
**/

#include <stdio.h> // For using printf()
#include <stdlib.h> // For using atoi()
#include <string.h> // For using strlen()

void encode(int argc, char *argv[]) {
	int i, j;

	for(i = 1; i < argc; i++) {
		for(j = 0; j < strlen(argv[i]); j++)
			printf("%d ", argv[i][j]);
		printf("32 "); // Space
	}
}

void decode(int argc, char *argv[]) {
	int i;

	for(i = 1; i < argc; i++)
		printf("%c", atoi(argv[i]));
}

// Main function.
int main(int argc, char *argv[]) {
	// Check for lacking arguments.
	if(argc < 2) {
		printf("Usage:\n");
		printf("\n");
		printf("\tHow to break the code:\n");
		printf("\t\t./u8c 1 2 3\n");
		printf("\tHow to form the code:\n");
		printf("\t\t./u8c I want to encode this\n");
		// Return 1 on an error.
		return 1;
	}

	// Test if numbers or text.
	if(argv[1][0] >= '0' && argv[1][0] <= '9')
		decode(argc, argv);
	else
		encode(argc, argv);

	// Newline
	printf("\n");

	// Return 0 on success.
	return 0;
}
