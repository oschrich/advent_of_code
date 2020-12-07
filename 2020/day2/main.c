#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file;
	char* line;
	int count;

	int min,max;
	char c;
	char pass[100];

	line = malloc(128);

	file = fopen("input", "r");

	count=0;

	int validCnt = 0;
	int validCnt2 = 0;
	while (fgets(line, 128, file) != NULL) {
		printf("line %d : %s",count, line);
		sscanf(line, "%d-%d %c: %s\n", &min, &max, &c, pass);
		printf(" min: %d  max: %d  char: %c\n", min, max, c);
		printf(" pass: %s\n", pass);
		count++;
		int i;
		int charCnt;
		charCnt=0;
		for(i=0;i<strlen(pass);i++)
		{
			if(c == pass[i])
			{
				charCnt++;
			}
		}
		if (charCnt >= min && charCnt <= max)
		{
			validCnt++;
		}
		int match1;
		int match2;
		match1 = (c == pass[min-1]);
		match2 = (c == pass[max-1]);
		if (match1 ^ match2)
		{
			validCnt2++;
		}
		printf(" strlen: %d charCnt: %d, validCnt: %d\n", strlen(pass), charCnt, validCnt) ;
	}

	printf("valid: %d\n", validCnt);
	printf("valid2: %d\n", validCnt2);

	fclose(file);
	free(line);
	return 0;
}

