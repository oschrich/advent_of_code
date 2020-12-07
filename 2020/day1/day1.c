#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
	int fd,i,j,k;
	FILE *file;
	char* line;
	int count;

	int values[300] = {0};

	line = malloc(128);

	printf("hello world\n");

	file = fopen("input", "r");

	count=0;
	while (fgets(line, 128, file) != NULL) {
		values[count] = atoi(line);
		//printf("line %d : %d\n",count, values[count]);
		count++;

	}

	for(i=0;i<count;i++)
	{
		int a = values[i];
		for(j=0;j<count;j++)
		{
			if (j==i)
				continue;

			int b = values[j];

			if (a+b == 2020)
			{
				printf("a=%d,b=%d\n",a,b);
			}
		}
	}
	for(i=0;i<count;i++)
	{
		int a = values[i];
		for(j=0;j<count;j++)
		{
			if (j==i)
				continue;

			int b = values[j];
			
			for(k=0;k<count;k++)
			{
				if (k==i)
					continue;

				int c = values[k];
				if (a+b+c == 2020)
				{
					printf("a=%d,b=%d,c=%d\n",a,b,c);
				}
			}
		}
	}


	//printf("line=%d\n",values[0]);
	fclose(file);

	free(line);
	//for(i=0;
	return 0;
}

