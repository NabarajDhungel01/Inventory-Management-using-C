
// WHEN USING THIS PROJECT YOU CAN MANUALLY ADD THE DATA in the following sample
// code || name || company_name || price || quantity
//(nospacesinfront)1(space)One(spacee)ONECOMPANY(space)100(space)1000  

// to change the password go to login_screen function and change the username and password in the strcmp function.


// ADD special invisible character when priting the watermark on each line..
// add space and make the character display without error in the bill
// like if name  is soyabean_oil it should show soya.
// for this compare the name before bill and make it like this.

#include <stdio.h>   // CREATED BY Mr Navy
#include <conio.h>   // Especially  for getche()
#include <stdlib.h>  // Especially  for system("cls") , exit(0);
#include <time.h>    // Especially  for showing Date and time above the inventory management
#include <string.h>  // Especially  for strcmp
#include <windows.h> // Especially  for STD_OUTPUT_HANDLE
#include <ctype.h>   // Especially for toupper function
#include <sys/time.h>  // to print time to the file

void welcome_screen(void);               // function for welcome screen
void login_screen();                     // function for login screen
void display_menu();                     // function for display menu screen
void credits();                          // function to display credits.
void gotopositionxy(int x, int y);       // this will place the cursor.
void cursor(int position);               // this will move the cursor the the positionxy
void highlight(int position, int count); // this will highlight the thing
void customer_bill(int *a, int*b,int *c, int*d, int*e );

// function seen in the menu of  DISPLAY_MENU function.
int multiplyAB(int a, int b); // takes two number multiplies and return the value
void add_product();
void delete_product();
void search_product();
void display_products();
void edit_product();
void calculate_bill();
void window(int a,int b,int c,int d);
void clear_seven_to_nineteen();
void separator_line(); // prints line between shopkeepers bill and cusotmer bill
void display_bill();

void exit(); // we will not be using this function for sure. because we will be using """"exit(0)"""" function from <stdlib.h>;

struct product

{
    char product_name[30];
    char product_company[40];
    char c;
    int product_code;
    int product_price;
    int product_quantity;
} pdt;

COORD coord = {0, 0}; // this is global variable used for the position of cursor // it is included in <windows.h>  header


int main()
{
    display_menu();
}

void display_menu()
{
    system("cls"); // will clear the screen to show the menu
    window(25,60,20,32);
    const char *menu[] = {"\tCalculate Bill", "\tAdd Product", "\tDelete Product", "\t Search Product", "\tDisplay All", "Edit Product", "Credits", "Exit"};
    gotopositionxy(33, 18);
    printf("MAIN MENU");
    for (int i = 0; i <= 7; i++)
    {
        gotopositionxy(30, 22 + i);
        printf("%s\n\n\n", menu[i]);
    }
    cursor(8); // 7

    printf("final");
    getch();
}

void calculate_bill()
{

}

void add_product()
{

}

void delete_product()
{

}

void search_product()
{

}

void display_product()
[

]



void  credits()
{

}

































void cursor(int position)
{
    int count = 1;
    char ch = '0';
    gotopositionxy(30, 22);
    while (1)
    {
        switch (ch)
        {
        case 80:
            count++;
            if (count == position + 1)
                count = 1;
            break;

        case 72:
            count--;
            if (count == 0)
                count = position;
            break;
        }
        highlight(position, count);
        ch = getch();
        if (ch == '\r')
        {
            if (position == 8)
            {
                // YOU CAN SET YOUR FUNCTION WHERE TO JUMP HERE
                if (count == 1)
                    calculate_bill();                  // printf("\t\t Calculate Bill HEHE");
                else if (count == 2) /*add_product()*/ /*printf("add_item")*/
                    add_product();
                else if (count == 3)    /*delete_product()*/
                    delete_product();   // printf("deleteproduct");
                else if (count == 4)    /*search_product()*/
                    search_product();   // printf("search_item");
                else if (count == 5)    /*display_products()*/
                    display_products(); /*printf ("read_item")*/
                else if (count == 6)    /*()*/
                    edit_product();     //  printf("edit_item");   // edit_product();
                else if (count == 7)
                    credits() /*del()*/ /*printf("credits")*/;
                else if (count ==8 )
                { char check1;
                        gotopositionxy(33, 33);
                        printf("Exit (Y/N)\t : ");
                        check1 = getche();
                        if ((check1 == 'n' || check1 == 'n'))
                        {
                            display_menu();
                        }
                         else
                         exit(0);
                     /*printf("exit"*/;

                }
                else
                exit(0);
            }
        }
    }
}

void gotopositionxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void highlight(int position, int count)
{
    // THIS FUNCTOIN WILL HIghlight the selected item by cursor
    if (position == 8)
    {
        gotopositionxy(30, 22);
        printf("   Calculate Bill");
        gotopositionxy(30, 23);
        printf("   Add Product ");
        gotopositionxy(30, 24);
        printf("   Delete Products      ");
        gotopositionxy(30, 25);
        printf("   Search Product     ");
        gotopositionxy(30, 26);
        printf("   Display All    ");
        gotopositionxy(30, 27);
        printf("   Edit Product         ");
        gotopositionxy(30, 28);
        printf("   Credits   ");
        gotopositionxy(30, 29);
        printf("   Exit           ");

        switch (count)
        {
        case 1:
            gotopositionxy(30, 22);
            printf(" - Calculate Bill");
            break;
        case 2:
            gotopositionxy(30, 23);
            printf(" - Add Product");
            break;
        case 3:
            gotopositionxy(30, 24);
            printf(" - Delete Products");
            break;
        case 4:
            gotopositionxy(30, 25);
            printf(" - Search Product");
            break;
        case 5:
            gotopositionxy(30, 26);
            printf(" - Display All");
            break;
        case 6:
            gotopositionxy(30, 27);
            printf(" - Edit Product");
            break;
        case 7:
            gotopositionxy(30, 28);
            printf(" - Credits");
            break;
        case 8:
            gotopositionxy(30, 29);
            printf(" - Exit");
            break;
        }
    }
}

int multiplyAB(int a, int b)
{
    int Mul;
    Mul = a * b;
    return Mul;
}

void clear_seven_to_nineteen()
{
     // will clear the line by printing empty spaces:      ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    gotopositionxy(0, 7);                                                  
    printf("                                                                                                                               ");
    gotopositionxy(0, 8);                                              
    printf("                                                                                                                               ");
    gotopositionxy(0, 9);                                              
    printf("                                                                                                                               ");
    gotopositionxy(0, 10);                                              
    printf("                                                                                                                               ");
    gotopositionxy(0, 11);                                              
    printf("                                                                                                                               ");
    gotopositionxy(0, 12);                                              
    printf("                                                                         ");
    gotopositionxy(0, 13);                                               
    printf("                                                                                                      ");
    gotopositionxy(0, 14);                                               
    printf("                                                                                                      ");
    gotopositionxy(0, 15);                                            
    printf("                                                                                                       ");
    gotopositionxy(0, 16);                                            
    printf("                                                                                                       ");
    gotopositionxy(0, 17);                                            
    printf("                                                                           ");
    gotopositionxy(0, 18);                                              
    printf("                                              "                                                 );
    gotopositionxy(0, 19);                                              
    printf("                                                                                              ");
    gotopositionxy(0, 20);                                              
    printf("                                                                                                ");
    gotopositionxy(0, 21);                                              
    printf("                                                                                                                 ");
    //↑↑↑↑↑↑↑↑↑ THIS WILL CLEAR THE MESSAGE ENTER CODE AGAIN, WHEN THE USER ADDS THE CODE THAT IS NOT IN THE DATABASE
}

void separator_line()
{
gotopositionxy(104,22);
printf("||");
gotopositionxy(104,23);
printf("||");
gotopositionxy(104,24);
printf("||");
gotopositionxy(104,25);
printf("||");
gotopositionxy(104,26);
printf("||");
gotopositionxy(104,27); 
printf("||");
gotopositionxy(104,28);
printf("||");
gotopositionxy(104,29);
printf("||");
gotopositionxy(104,30); 
printf("||");
gotopositionxy(104,31);
printf("||");
gotopositionxy(104,32);
printf("||");
gotopositionxy(104,33);
printf("||");
gotopositionxy(104,34);
printf("||");
gotopositionxy(104,35);
printf("||");
gotopositionxy(104,36);
printf("||");
gotopositionxy(104,37); 
printf("||");
gotopositionxy(104,38);
printf("||");
gotopositionxy(104,39);
printf("||");
gotopositionxy(104,40); 
printf("||");
gotopositionxy(104,41);
printf("||");
gotopositionxy(104,42); 
printf("||");
gotopositionxy(104,43);
printf("||");
gotopositionxy(104,44);
printf("||");
gotopositionxy(104,45);
printf("||");
gotopositionxy(104,46);
printf("||");
gotopositionxy(104,47); 
printf("||");
gotopositionxy(104,48); 
printf("||");
gotopositionxy(104,49);
printf("||");
}

void window(int a,int b,int c,int d)
{
    int i;
//textcolor(1);
//textcolor(4);
    for (i=a; i<=b; i++)
    {
        gotopositionxy(i,17);
        printf("\xcd");
        gotopositionxy(i,19);
        printf("\xcd");
        gotopositionxy(i,c);
        printf("\xcd");
        gotopositionxy(i,d);
        printf("\xcd");
    }

    gotopositionxy(a,17);
    printf("\xc9");
    gotopositionxy(a,18);
    printf("\xba");
    gotopositionxy(a,19);
    printf("\xc8");
    gotopositionxy(b,17);
    printf("\xbb");
    gotopositionxy(b,18);
    printf("\xba");
    gotopositionxy(b,19);
    printf("\xbc");
//textcolor(4);
    for(i=c; i<=d; i++)
    {
        gotopositionxy(a,i);
        printf("\xba");
        gotopositionxy(b,i);
        printf("\xba");
    }
    gotopositionxy(a,c);
    printf("\xc9");
    gotopositionxy(a,d);
    printf("\xc8");
    gotopositionxy(b,c);
    printf("\xbb");
    gotopositionxy(b,d);
    printf("\xbc");
//textbackground(11);
//textcolor(0);
}


