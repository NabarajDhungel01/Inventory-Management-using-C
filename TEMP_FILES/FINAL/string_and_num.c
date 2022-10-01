// #include <stdio.h>
// void store_bill_name;

// int main()
// {

//     char name[30];
//     char bill_name[7];

//     return 0;
// }

// void string(char name[30])
// {
//     char six_letter_name[7];

//     for (int i = 0; i < 7; i++)
//     {
//         six_letter_name[i] = name[i];
//     }

// }

#include <stdio.h>
#include <string.h>

int main()
{
    
    // PRINT ONLY FIRST 6 LETTER OF THE NAME
    {
        {
            int name_length;
            name_length = strlen(pdt.product_name);

            if (name_length > 6)
            {
                for (int i = 0; i < 6 /* name_length */; i++) // print only 6 characters
                {
                    printf("%c", pdt.product_name[i]);
                }
            }
            else /* if (strlen(pdt.product_name < 7  ) */ // IF THE NAME LENGTH IS LESS THAN 7
                for (int i = 0; i < name_length; i++)
                {
                    printf("%c", pdt.product_name[i]);
                }
        }
    }


}