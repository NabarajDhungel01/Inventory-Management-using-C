#include <stdio.h>
#include <conio.h>
long power(int a, int b)
{
    long result = 1;
    for (int i = 1; i <= b; i++)
    {
        result *= a;
    }
    return result;
}
int count_number(int num)
{
    int count = 0;
    do
    {
        num /= 10;
        count++;
    } while (num != 0);
    return count;
}
struct product
{
    int product_code;
}pdt;

int main()
{
    int get_code = 0;
    int temp = 0;
    int chr, tempp,repeat_times_inside_eof_loop =0;
    long ten,tenn =0; 
    pdt.product_code = 1;

    chr = getch(); /*  printf("\n 2224") ; */
    printf("%d", chr - 48);
    tempp = 0;

    tempp = chr - 48;
    // gotopositionxy(19 + repeat_times_inside_eof_loop, 5);

    int count = 0,expo = 0,comparison_code = 0,temp_pdt_code = 0,temp_pdt_code2 = 0;

    get_code = get_code * 10 + tempp; /* printf("\n 2230") ; */
    
        printf("\n\n BEFOR CHANGING GET CODE  : %d", get_code);

        printf("\n\n BEFORE CHANGING CODE  : %d", pdt.product_code);

        printf("\n Repition: %d ", repeat_times_inside_eof_loop + 1);

        temp_pdt_code = pdt.product_code;  /*printf("\n 2235"); */
        temp_pdt_code2 = pdt.product_code; /* printf("\n 2236") ; */

        count = count_number(pdt.product_code);
        printf("\n COUNT IS %d \n", count);
        // printf("\n  %d \n", repeat_times_inside_eof_loop);

        expo = ((count - repeat_times_inside_eof_loop) + 1); /* printf("\n 2238"); */
        printf("\n expo is :  %d \n",expo);

        // ten = pow(10, expo);;/*  printf("\n 2240") ; */
        ten = power(10, expo-1);

        printf("\n TEN is : %d", ten);

        temp_pdt_code2 = temp_pdt_code2/ten; /*  printf("\n 2242") ; */
        printf("\nTEMP_PDT_CODE_2 is : %d", temp_pdt_code2);
        pdt.product_code = temp_pdt_code2;


        printf("\n\n AFTER CHANGING CODE  : %d", pdt.product_code);
        printf("\n\n AFTER CHANGING GET CODE  : %d", get_code);

        getch();

        return 0;
    }
