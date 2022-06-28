#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "store.h"

void magic( FILE *stream ){
	char buffer[1024]; // Ideiglenes sor míg le nem tárolunk egy dinamikus tömbbe
	
	int capacity = 1;
	int numOfLines = 0;
	char **lineArr = (char**)malloc(capacity * sizeof(char*));
	
	if( lineArr == NULL ){
		fprintf(stderr, "Memory allocation failed!\n");
		exit(1);
	}
	

	while( fgets( buffer, 1024, stream ) != NULL ){
		char *line = storeLine( buffer );
		
		//Extend memory
		if(numOfLines >= capacity){
			capacity = capacity * 2;
			lineArr = realloc(lineArr, capacity * sizeof(char*));
		
			if(lineArr == NULL){
				fprintf(stderr, "Memory allocation failed!\n");
				exit(1);
			}
		}
		
		lineArr[numOfLines] = line;
		numOfLines++;
		
	}

	//output
	int lineNum;
	for(lineNum = numOfLines - 1; lineNum >= 0; lineNum--){
		printf("%d %s\n", lineNum + 1, lineArr[lineNum]);
	}
	
	//free	
	int i;
	for(i = 0; i < numOfLines; i++){
		free(lineArr[i]);
	}
	free(lineArr);
}



