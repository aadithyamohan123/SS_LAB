#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char input[10];

    int start, length, addr;
    FILE *f1, *f2;

    f1 = fopen("object.txt", "r");
    f2 = fopen("output.txt", "w");

    if (f1 == NULL || f2 == NULL) 
	{
        printf("Error opening files.\n");
        return 1;
    }

    fscanf(f1, "%s", input);

    if (strcmp(input, "H") == 0)
    {
        fscanf(f1, "%d", &start);
        fscanf(f1, "%d", &length);
        fscanf(f1, "%s", input);
    }

    while (strcmp(input, "H") != 0)
    {
        if (strcmp(input, "T") == 0)
        {
            fscanf(f1, "%d", &addr);
            fscanf(f1, "%s", input);

            if (strlen(input) >= 6) 
			{
                fprintf(f2, "%d\t%c%c\n", addr, input[0], input[1]);
                fprintf(f2, "%d\t%c%c\n", (addr + 1), input[2], input[3]);
                fprintf(f2, "%d\t%c%c\n", (addr + 2), input[4], input[5]);
                addr += 3;
            } 
			else
			{
                printf("Error: Input string is too short.\n");
                return 1;
            }

            fscanf(f1, "%s", input);
        }
        else
        {
            if (strlen(input) >= 6) 
			{
                fprintf(f2, "%d\t%c%c\n", addr, input[0], input[1]);
                fprintf(f2, "%d\t%c%c\n", (addr + 1), input[2], input[3]);
                fprintf(f2, "%d\t%c%c\n", (addr + 2), input[4], input[5]);
                addr += 3;
            } 
			else 
			{
                printf("Error: Input string is too short.\n");
                return 1;
            }

            fscanf(f1, "%s", input);
        }
    }

    fclose(f1);
    fclose(f2);
    printf("FINISHED");

    return 0;
}
