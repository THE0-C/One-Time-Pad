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

void bulkfiles(int number, char name[])
{
	for(int i = 0; i<number; i++) // for all files to be made
	{
		char temp[50]; // init temp file
		sprintf(temp, "%s-%d", name, i); // put future file name in to temp
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
	else if(argc == 5 && (strcmp(argv[1], "-n") == 0) && (strcmp(argv[3], "-b") == 0)) // if -n and -b write output into argv[4] ammount of files in format argv[2]-argv[4]
	{	
		int numfiles;
		sscanf(argv[4], "%d", &numfiles); // get number of files to make
		bulkfiles(numfiles, argv[2]); // call bulkfiles with number of pads and the name
	}
	else // output correct useage
	{
		printf("./random # Output the pad to terminal\n./random -n <filename> # Creats or writes the pad to <filename>\n./random -n <filename> -b <number> # Creats <number> ammount of pads with format <filename>-<number>\n");
	}
    	
}
