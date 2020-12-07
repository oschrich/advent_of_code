#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

const int INLINES = 323;

void lookForTrees(int x, int y, int verbose)
{
	FILE *file;
	char* line;
	int count;

	int rightCnt=0;
	int downCnt=y-1;

	int min,max;
	char c;

	int trees=0;
	int offset;

	line = malloc(128);

	file = fopen("input", "r");

	count=0;

	while (fgets(line, 128, file) != NULL) {

		count++;
		downCnt++;

		if (downCnt != y)
		{
			continue;
		}

		offset = rightCnt % 31;
		rightCnt+=x;
		downCnt=0;
		
		if (verbose)
		{
			printf("line %d : %s",count, line);
		}


		if(line[offset] == '.')
		{
			line[offset] = 'O';
		}
		else if (line[offset] == '#')
		{
			line[offset] = 'X';
			trees++;
		}
		else
		{
			printf("Invalid character!\n");
		}	
		if (verbose)
		{
			printf("line %d : %s - trees:%d\n",count, line, trees);
		}

	}

	printf("trees: %d\n", trees);

	fclose(file);
	free(line);
}


int main() {
	lookForTrees(1,1,0);
	lookForTrees(3,1,0);
	lookForTrees(5,1,0);
	lookForTrees(7,1,0);
	lookForTrees(1,2,0);
	return 0;
}

