#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int get_Input(); // gets the valid int input
int main()
{

    int a;

    a = get_Input();
    printf(" \n\n You have entered : %d", a);

    return 0;
}
int get_Input()
{
    int num;
    int ch;
    int count;
AGAIN:
    num = 0;
    ch = 0;
    count = 0;

    printf("\n\n Balance :  ");
    while (1)
    {

        ch = getche();

        if (ch >= 48 && ch <= 57)
        {

            num = num * 10 + (ch - 48);
            count++;
        }
        else if (ch == 13)
        {
            if (count == 0) // if the enter button is pressed at the starting of the program
            {
                goto AGAIN;
            }
            else
            {   // after entered is pressed, it stops taking input

                printf(" \t\t\t \"Enter pressed\" ");
                return num;
                break;
            }
        }
        else
        {
            printf("\t\t    **********Invalid input..********* ");
            printf("\n \t\t **********Provide numeric input only********* ");
                    
            
            goto AGAIN;
        }
    }
}