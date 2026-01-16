#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void randomgen(FILE *file)
{
	int num, i;
	for(i=0; i<100;) // Loop 100 times for random numbers
    	{
        	num = rand(); // make random number
        	num = num % 59; // idk what i did here, wrote this a long time ago
        		
		fprintf(file, "%02x ", num); // print number
		++i; // increment i
    	}
}

void bulkfiles(int number)
{
	for(int i = 0; i<number; i++) // for all files to be made
	{
		char temp[50]; // init temp file
		sprintf(temp, "onetimepad-%d", i); // put future file name in to temp
		FILE *file = fopen(temp, "w"); // creat file with name temp
		randomgen(file); // fill file
		fclose(file); //close file
	}
}

int main(int argc, char *argv[])
{
	int num, i;
    	srand(time(NULL));  // Seed ONCE
	FILE *file;

	if(argc == 1) // if no arguments are given, print output to screen
	{	
		file = stdout;
		randomgen(file);
	}
	else if(argc == 3 && (strcmp(argv[1], "-n") == 0)) // if -n <file> is given writethe output to that file
	{	
		file = fopen(argv[2], "w");
		randomgen(file);
	}
	else if(argc == 3 && (strcmp(argv[1], "-b") == 0)) // if -b write output into argv[2] ammount of files in format onetimepad-<number>
	{	
		int numfiles;
		sscanf(argv[2], "%d", &numfiles);
		bulkfiles(numfiles);
	}
    	
}
