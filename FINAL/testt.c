#include <stdio.h>
#include <windows.h>

void gotopositionxy(int x, int y);
COORD coord = {0, 0};
int main()
{
    system("cls");
    int sn = 0;

    char temp_name[30];
    puts("Enter the name");
    gets(temp_name);

    // print the name of the product
    {
        {
            // this will print the first 7 characters of the temp_name
            gotopositionxy(14, 28 + sn);
            // PRINT ONLY FIRST 6 LETTER OF THE NAME
            {
                {
                    int name_length;
                    name_length = strlen(temp_name);

                    if (name_length > 6)
                    {
                        gotopositionxy(0, 10);
                        printf("case 1");

                        gotopositionxy(14, 28 + sn);

                        for (int i = 0; i < 6; i++) // print only 6 characters
                        {
                            printf("%c", temp_name[i]);
                        }
                    }
                    else
                    {
                        /* if (strlen(temp_name < 7  ) */ // IF THE NAME LENGTH IS LESS THAN 7
                        gotopositionxy(0, 10);
                        printf("case 2");

                        gotopositionxy(14, 28 + sn);

                        for (int i = 0; i < name_length; i++)
                        {
                            printf("%c", temp_name[i]);
                        }
                    }
                }
            }
            // for (int i = 0; i < 7; i++)
            // {
            // printf("%c", temp_name[i]);
            // }
            printf("."); // will print dot after
        }
    }

    return 0;
}
void gotopositionxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}