#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* storeLine(char lineToStore[1024] ){
		int strLen = strlen(lineToStore);
		char* line = (char*)malloc((strLen) * sizeof(char)); // +1 a \0-nak
		
		if(line == NULL){
			fprintf(stderr, "Memory allocation failed!\n");
			exit(1);
		}

		int i;
		for(i = 0; i < strLen - 1; i++){
			char cToStore = lineToStore[strLen - 2 - i];
			
				line[i] = cToStore;
			
		}

	line[ strLen - 1 ] = '\0';
	
	return line;
}
