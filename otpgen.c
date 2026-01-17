#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_input(char *char_array, int int_array[100]) // converts a string of 2 digit hex values to a int array
{
	int a;

	for(int j = 0; j <= 300; j += 3) // loop for the hundred hex chars " f5"
	{
		sscanf(&char_array[j], "%2x", &a); // scan for 2 digit hex value and store in a
		int_array[j / 3] = a; // store a at the correct index
	}
}

int main(int argc, char *argv[]) 
{
	char *input_key = calloc(300, sizeof(char)); // allocate a var for the enterd key
	int int_key[100] = {0}; // init var to store key in int array

	if(argc == 1) // if no arguments are given
	{
		printf("# Enter One Time Pad\n"); 
		printf(">");
		fgets(input_key, 300, stdin); // get input key
		scan_input(input_key, int_key); // convert string into int array
		fgetc(stdin); // idk what this dose but it fixes something
	}
	else if(argc ==2) // if 2 args are given
	{
		FILE *file = fopen(argv[1], "r"); // use the second arg as a file to read from
		fgets(input_key, 300, file); // read key from file
		scan_input(input_key, int_key); // convert key to int array
	}

	char input_msg[100]; // init var to store message to encode
	printf("# Enter Message to Encode\n"); 
	printf(">");
	fgets(input_msg, 100, stdin); // get input
	input_msg[strcspn(input_msg, "\n")] = 0; // remove newline from message

	printf("\n# Message:\n");
	for(int i = 0; i < strlen(input_msg);) // encode message
	{
		
		printf("%02x ", input_msg[i] ^ int_key[i]); // print encoded message
		++i;
	}
	printf("\n");
}
