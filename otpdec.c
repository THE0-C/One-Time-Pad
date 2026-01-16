#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_input(char *text_input, int int_array[100]) // converts input string to input int array
{
	int temp; // temp

	for(int j = 0; j <= 300; j += 3) // loops for all charecters
	{
		sscanf(&text_input[j], "%2x", &temp); // scans for 2 digit hex number
		int_array[j / 3] = temp; // set respective value in int array
	}
}

int main(int argc, char *argv[])
{
	int key[100] = {0}; // int array to store the one time pad (otp)
	int int_msg[100] = {0}; // int arrray to store the encoded message after it is converted to ints
	char *input_key = calloc(300, sizeof(char)); // char array to store the inputed key

	if(argc == 1) // check whether there are no cmd arguments
	{

		printf("# Enter One Time Pad\n");
		printf(">");

		fgets(input_key, 300, stdin); // store inputed key. 300 in length because each encoded charecter is 3 char long and the max message length is 100
		scan_input(input_key, key); // call function to convert string to int array

		fgetc(stdin); // tbh idk what this does, i think it removes a newline from the previos fgets
		printf("\n");
	}
	else if(argc == 2) // runs if there is one cmd argument
	{
		char newname[100];

		FILE* file = fopen(argv[1], "r"); // file which stores otp
		fgets(input_key, 300, file); // read the otp from file
		scan_input(input_key, key); // convert to array 
		fclose(file); // close file

		sprintf(newname, "%s.used", argv[1]); // save new name: argv[1] + .used
		rename(argv[1], newname); // rename file

	}
	else // prints if wrong number of arguments is supplied
	{
		printf("Incorrect number of arguments\n");
		exit(1);
	}

	char *input_msg = calloc(300, sizeof(char)); // allocate space for received message

	printf("# Enter Received Message\n");
	printf(">");
	fgets(input_msg, 300, stdin); // get input
	scan_input(input_msg, int_msg); // convert to array

	printf("\n# Decoded message:\n");
	int msg_len = (strlen(input_msg) - 1)/3; // calculate mesage length

	for(int i = 0; i <= msg_len; i++) // loop for message length
	{
		printf("%c", int_msg[i] ^ key[i]); //print decoded message one char at a time
	}
	printf("\n");
}
