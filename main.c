#include <stdio.h>
#include <stdlib.h>

#include "magic.h"

int main(int argc, char *argv[]){

	FILE *stream;
	
	if( argc < 2){ // Beolvasás a stdin-ről
	
		stream = stdin;
		
		magic(stream);
	
	} else { // Beolvasás a fájlokból
		int i;
		for(i = 1; i < argc; i++){ // i = 1, mert az 1-es indextől kezdődnek a fájl(ok) neve(i)
			stream = fopen(argv[i], "r");
			
			if( stream == NULL ){
				fprintf(stderr, "File opening unsuccessful!\n");
				continue;
			}
			
			magic(stream);
			
			fclose(stream);
		}
		
	}

	return 0;
}

