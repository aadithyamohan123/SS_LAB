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

/*
object.txt

H 1000 232
T 1000 142033 483039 102036
T 2000 298300 230000 282030 302015
E



output.txt

1000	14
1001	20
1002	33
1003	48
1004	30
1005	39
1006	10
1007	20
1008	36
2000	29
2001	83
2002	00
2003	23
2004	00
2005	00
2006	28
2007	20
2008	30
2009	30
2010	20
2011	15

*/


