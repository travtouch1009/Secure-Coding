#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void readFile(char *arg)
{
	char buf[100];
	strncpy(buf, arg, sizeof(buf));
	FILE *fp;
	char lineBuf[200];
	//comment
	fp = fopen(buf, "r");

	if (fp == NULL)
   	{
      		perror("Error while opening the file.\n");
      		exit(EXIT_FAILURE);
   	}

	fgets(lineBuf, sizeof(lineBuf), fp);
	lineBuf[sizeof(lineBuf) - 1] = '\0';

	printf("%s", lineBuf);
}

int main(int argc, char **argv)
{

	if (argc == 2)
	{
		readFile(argv[1]);
	}
	else
	{
		printf("\nThis program expects an argument.\n\n");
	}
	return 0;


}
