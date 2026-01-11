#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scan_input(char *char_array, int int_array[100])
{
	int a;

	for(int j = 0; j <= 300; j += 3)
	{
		sscanf(&char_array[j], "%2x", &a);
		int_array[j / 3] = a;
	}
}

int main(int argc, char *argv[]) 
{
	char *input_key = calloc(300, sizeof(char));
	int int_key[100] = {0};

	if(argc == 1)
	{
		printf("# Enter One Time Pad\n");
		printf(">");
		fgets(input_key, 300, stdin);
		scan_input(input_key, int_key);
		fgetc(stdin);
	}
	else if(argc ==2)
	{
		FILE *file = fopen(argv[1], "r");
		fgets(input_key, 300, file);
		scan_input(input_key, int_key);
	}

	char input_msg[100];
	printf("# Enter Message to Encode\n");
	printf(">");
	fgets(input_msg, 100, stdin);
	input_msg[strcspn(input_msg, "\n")] = 0;

	printf("\n# Message:\n");
	for(int i = 0; i < strlen(input_msg);)
	{
		
		printf("%02x ", input_msg[i] ^ int_key[i]);
		++i;
	}
	printf("\n");
}
