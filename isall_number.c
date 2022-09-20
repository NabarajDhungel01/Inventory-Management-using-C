#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXINPUT 100

int isallnumber(int num);
int length_of_num(int num);

int main()
{

    char input[MAXINPUT] = "";
    int length,i; 
    int not_number = 0;

    scanf ("%s", input);
    length = strlen (input);
    for (i=0;i<length; i++)
        if (!isdigit(input[i]))
        {
            printf ("Entered input is not a number\n");
            // exit(1);
            not_number++;
        }
    printf ("Given input is a number\n");


    return 0;
}
