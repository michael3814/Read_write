#include <stdio.h>
#include <stdlib.h>

void char_func();
void line_func();

FILE *infile;
FILE *outfile;

int main() {
    
	// Opening Input and Output files
    char file[100];
    printf("Please input the name of the file that is to be read \n");
    scanf("%s", file);
    
    infile = fopen(file, "r");
    outfile = fopen("outfile.txt", "w");

	if (infile == NULL) {
		printf("File not opened \n");
		return 1;
	}

	// Selecting Mode
	int mode;
	printf("Select mode of operation \n"
	       "0 for character-by-character mode \n"
	       "1 for line-by-line mode \n");
	scanf("%d", &mode);

	// Running Functions
	if      (mode == 0) 
		char_func();
	else if (mode == 1) 
		line_func();
	else 
		printf("Invalid mode entered");
	
	// Closing Files
	fclose(infile);
	fclose(outfile);
	return 0;
}

void char_func() {
	char letter;
	while((letter = fgetc(infile)) != EOF) {
		fputc(letter, outfile);
	}
}

void line_func() {
	char line[81];
	while(fgets(line, 81, infile) != NULL)
		fputs(line, outfile);
}
