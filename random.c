#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void randomgen(FILE *file)
{
	int num, i;
	for(i=0; i<100;) // Loop 100 times for random numbers
    	{
        	num = rand();
        	num = num % 59;
		if(num > 9)
		{
        		fprintf(file, "%02x ", num);
			++i;
		}
    	}
}

void bulkfiles(int number)
{
	for(int i = 0; i<number; i++)
	{
		char temp[50];
		sprintf(temp, "onetimepad-%d", i);
		FILE *file = fopen(temp, "w");
		randomgen(file);
		fclose(file);
	}
}

int main(int argc, char *argv[])
{
	int num, i;
    	srand(time(NULL));  // Seed ONCE
	FILE *file;

	if(argc == 1)
	{	
		file = stdout;
		randomgen(file);
	}
	else if(argc == 3 && (strcmp(argv[1], "-n") == 0))
	{	
		file = fopen(argv[2], "w");
		randomgen(file);
	}
	else if(argc == 3 && (strcmp(argv[1], "-b") == 0))
	{	
		int numfiles;
		sscanf(argv[2], "%d", &numfiles);
		bulkfiles(numfiles);
	}
    	
}
