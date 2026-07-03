#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h> 

void randomgen(FILE *file, int len)
{
	int num, i;
	for(i=0; i<len;) // Loop 100 times for random numbers
    	{
        	num = rand(); // make random number
        	num = num % 59; // idk what i did here, wrote this a long time ago
        		
		fprintf(file, "%02x ", num); // print number
		++i; // increment i
    	}
}

void bulkfiles(int number, char name[], int len)
{ for(int i = 1; i < (number + 1); i++) // for all files to be made
	{
		char temp[50]; // init temp file
		sprintf(temp, "%s-%d", name, i); // put future file name in to temp
		FILE *file = fopen(temp, "w"); // creat file with name temp
		randomgen(file, len); // fill file
		fclose(file); //close file
	}
}

int main(int argc, char *argv[])
{
    	srand(time(NULL));  // Seed ONCE
	FILE *file;
	int len = 100;
	int opt;
	int bulk = 0;
	char filename[100] = "";
	while((opt = getopt(argc, argv, "f:n:b:h")) != -1)
	{
		switch(opt)
		{
			case 'f':
				strcpy(filename, optarg);
				break;
			case 'n':
				len = atoi(optarg);
				break;
			case 'b':
				if (atoi(optarg) >= 0)
				bulk = atoi(optarg);
				break;
			case '?':	
			case 'h':
				printf("INCORRECT USAGE\n");
				exit(-1);
				
		}
	}
	if (bulk == 0)
	{
		if (strlen(filename) == 0)
		{
			file = stdout;
			randomgen(file, len);
		}
		else
		{
			file = fopen(filename, "w");
			randomgen(file, len);
		}
	}
	else
	{
		if(strlen(filename) == 0)
		{
			bulkfiles(bulk, "pad", len);
		}
		else
		{
			bulkfiles(bulk, filename, len);
		}

	}
	
	return 0;
}
