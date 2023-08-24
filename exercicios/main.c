#include <stdio.h>
#include <stdbool.h>

int main(void)
{
 
    FILE* fh_output;

    fh_output = fopen("io.txt", "w");

    int input = 0;
    while (true)
    {
        printf("Enter # (-1 quits): ");
        scanf("%d", &input);
        if (input == -1) break;
        else fprintf(fh_output, "%d\n", input);
    }

    fclose(fh_output);

    FILE* fh_input;
    fh_input = fopen("io.txt", "r");

    int finput = 0;
    int lines = 0;
    int numbers[100];

    
    while (fscanf(fh_input, "%d", &finput) != EOF)
    {
        
        numbers[lines] = finput;
        printf("file line %d: %d\n", lines + 1, finput);
        lines++;
    }

    int total = 0;
    for (int i = 0; i < lines; i++)
        total = i;
    printf("Average: %d\n", total + 1);

    fclose(fh_input);
 /*
    fh_input = fopen("in.txt", "r");


    fgets(buffer, 256, fh_input);
    printf("Buffer: %s\n", buffer);

    fclose(fh_input);
    */

    return 0;
}
