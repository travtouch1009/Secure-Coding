#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_CHAR 1000
#define MAX_LINE_COUNT 200

void readFile(char *arg)
{
        //Copy the filename to buf
        char buf[100];
        strncpy(buf, arg, sizeof(buf));
        buf[sizeof(buf)-1] = '\0';

        //FID, line storage, and line array
        FILE *fp;
        char lineBuf[MAX_LINE_CHAR];
        char *lines[MAX_LINE_COUNT];
        fp = fopen(buf, "r");
	int i = 0;

        //read the lines of the file to the max line count
        while(fgets(lineBuf, sizeof(lineBuf), fp) && i < MAX_LINE_COUNT)
        {
                lineBuf[sizeof(lineBuf) - 1] = '\0';
                lines[i] = lineBuf;
                i++;
        }
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
