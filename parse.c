#include <stdio.h>

void scan_input(char *char_array, int int_array[100]) // converts a string of 2 digit hex values to a int array
{
	int a;

	for(int j = 0; j <= 300; j += 3) // loop for the hundred hex chars " f5"
	{
		sscanf(&char_array[j], "%2x", &a); // scan for 2 digit hex value and store in a
		int_array[j / 3] = a; // store a at the correct index
	}
}
