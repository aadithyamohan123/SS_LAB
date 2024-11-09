#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() 
{
    char add[6], length[10], input[10], bitmask[12], relocbit;
    int start, len, i, address, opcode, addr, actualadd;
    FILE *fp1, *fp2;

    printf("Enter the actual starting address: ");
    scanf("%d", &start);

    fp1 = fopen("relocinput.txt", "r");
    fp2 = fopen("relocoutput.txt", "w");

    if (fp1 == NULL || fp2 == NULL) 
    {
        printf("Error opening files.\n");
        return 1; 
    }

    fprintf(fp2,"%s\t%s\t%s\n","raddr","Opcd","aaddr");

    fscanf(fp1, "%s", input);

    while (strcmp(input, "E") != 0) 
    {
        if (strcmp(input, "H") == 0) 
        {
            fscanf(fp1, "%s", add);
            fscanf(fp1, "%s", length);
            fscanf(fp1, "%s", input); 
        }

        if (strcmp(input, "T") == 0)
        {
            fscanf(fp1, "%d", &address);
            address += start;
            
            fscanf(fp1, "%s", bitmask);
            len = strlen(bitmask); 

            for (i = 0; i < len; i++) 
            {
                fscanf(fp1, "%d", &opcode);  
                fscanf(fp1, "%d", &addr);   

                relocbit = bitmask[i]; 
                if (relocbit == '0') 
                {
                    actualadd = addr;
                } 
                else 
                {
                    actualadd = addr + start;
                }

                fprintf(fp2, "%d\t%d\t%d\n", address, opcode, actualadd);
                address += 3;
            }
            fscanf(fp1, "%s", input); 
        }

    }

    fclose(fp1);
    fclose(fp2);

    printf("FINISHED");

    return 0; 
}

/*

relocinput.txt

H 1000 200
T 1000 11001 14 1033 48 1039 90 1776 92 1765 57 1765
T 2011 11110 23 1838 43 1979 89 1060 66 1849 99 1477
E 1000

relocoutput.txt

raddr	Opcd	aaddr
6000	14	6033
6003	48	6039
6006	90	1776
6009	92	1765
6012	57	6765
7011	23	6838
7014	43	6979
7017	89	6060
7020	66	6849
7023	99	1477

*/
