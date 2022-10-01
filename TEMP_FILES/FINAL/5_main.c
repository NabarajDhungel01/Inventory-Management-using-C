
// WHEN USING THIS PROJECT YOU CAN MANUALLY ADD THE DATA in the following sample
// code || name || company_name || price || quantity
//(nospacesinfront)1(space)One(spacee)ONECOMPANY(space)100(space)1000

// to change the password go to login_screen function and change the username and password in the strcmp function.

// ADD special invisible character when priting the watermark on each line..
// add space and make the character display without error in the bill
// like if name  is soyabean_oil it should show soya.
// for this compare the name before bill and make it like this.

#include <stdio.h>    // CREATED BY Mr Navy
#include <conio.h>    // Especially  for getche()
#include <stdlib.h>   // Especially  for system("cls") , exit(0);
#include <time.h>     // Especially  for showing Date and time above the inventory management
#include <string.h>   // Especially  for strcmp
#include <windows.h>  // Especially  for STD_OUTPUT_HANDLE
#include <ctype.h>    // Especially for toupper function
#include <sys/time.h> // to print time to the file

int get_Input(int o);                    // only accepts numeric input // o is provided to print the custom message
void welcome_screen(void);               // function for welcome screen
void login_screen();                     // function for login screen
void display_menu();                     // function for display menu screen
void credits();                          // function to display credits.
void gotopositionxy(int x, int y);       // this will place the cursor.
void cursor(int position);               // this will move the cursor the the positionxy
void highlight(int position, int count); // this will highlight the thing
void customer_bill(int *a, int *b, int *c, int *d, int *e);

// function seen in the menu of  DISPLAY_MENU function.
int multiplyAB(int a, int b); // takes two number multiplies and return the value
void add_product();
void delete_product();
void search_product();
void display_products();
void edit_product();
void calculate_bill();
void window(int a, int b, int c, int d);
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
    // system("cls");
    // getch();
                

    display_menu();
}

void display_menu()
{
    system("cls"); // will clear the screen to show the menu
    window(25, 60, 20, 32);
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

    char check;
    gotopositionxy(33, 33);
    printf("Add Products(Y/N) \t: ");
    check = getche();
    if (check == 'y' || check == 'Y')
    {
        //  do nothing // continue
    }
    else
    {

        display_menu();
    }

    int valid = 0; // declared to check if character is valid or not.
    char c;        // we delcared this variable for later so that after taking all the inputs from the user, c will contain getch() , if the user presses enter, the while loop will be continued if any other key is entered, the loop will stop and will get to next step.                       // int index = 0;              // we will use this for checking if the charcter in string is valid or not
    FILE *filep1;
    int i;
    int Product_Code_Input;

    do
    {
        system("cls"); // clears the screen
        printf("=========== ENTER THE DETAILS OF THE PRODUCT ===========\n");
        // int Product_Code_Input; // we will be taking the input in this variable

        // filep1 = fopen("ProductDetails.dat", "r");

        if ((filep1 = fopen("ProductDetails.dat", "r")) != NULL) // if condition that checks if the file is NULL or not
        {
        XYZ:                            // for goto loop later on
            fseek(filep1, 0, SEEK_SET); // goest to the beginning of the file
            // printf("\n Product Code  ( Numbers Only )  \t\t : ");
            // scanf("%i", &Product_Code_Input); // Down // Checking if the product code is already there or not.

            Product_Code_Input = get_Input(1);
            fflush(stdin);

            /* else{ CONTINUE } */
            while (fscanf(filep1, "%i %s %s %i %i", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
            {
                /*
                fscanf reads every data stored in the file
                if entered staffID already exist then jumps to
                position I declared inside if(sfile!=NULL) at top
                */
                if (Product_Code_Input == pdt.product_code)
                {
                    printf("\n\tTHE PRODUCT CODE ALREADY EXIST.\n");
                    goto XYZ;
                }
                /* else do nothing */
            }
            // TRANSFERRING THE data from one array to another
            pdt.product_code = Product_Code_Input;

            // pdt.product_code = Product_Code_Input;
        }
        else // runs if sfile is empty
        {
        XYZ_2:
            // printf("\n Product Code  ( Numbers Only )  \t\t : ");
            // scanf("%i", &Product_Code_Input); // Down // Checking if the product code is already there or not.

            Product_Code_Input = get_Input(1);
            fflush(stdin);
            // TRANSFERRING THE data from one array to another
            pdt.product_code = Product_Code_Input;
        }

        // add product name
        do
        {

            fflush(stdin);
            printf("\n\n Product Name\t\t : ");
            gets(pdt.product_name);                             // takes input from user\
            fflush(stdin);
            pdt.product_name[0] = toupper(pdt.product_name[0]); // will capitalize the first letter of
            // this will iterate for every character in string and change it to uppercase
            for (i = 0; i < strlen(pdt.product_name); ++i)
            { // check if the character is valid or not
                if (isalpha(pdt.product_name[i]))
                {
                    valid = 1;
                }
                else
                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n The name you entered contain invalid character. Please 'Enter' Again");
                getch(); // this will hold the output
            }
        } while (!valid); // while end here
        fflush(stdin);
        // Product Company
        do
        {
            // char product_company[40];
            fflush(stdin);
            printf("\n Product Company\t : ");
            gets(pdt.product_company); // will get the input string
            pdt.product_company[0] = toupper(pdt.product_company[0]);
            // will capitalize the first letter of
            for (i = 0; i < strlen(pdt.product_company); ++i)
            { // check if the character is valid or not
                if (isalpha(pdt.product_company[i]))
                    valid = 1;
                else

                {
                    valid = 0;
                    break;
                }
            }
            if (!valid)
            {
                printf("\n The name you entered contain invalid character. Please 'Enter' Again");
                getch();
            }
        } while (!valid);
        fflush(stdin);
        // Product Price
        // printf("\n Product Price\t\t : ");
        pdt.product_price = get_Input(2);
        // scanf("%i", &pdt.product_price);
        fflush(stdin);
        // Product Quantity
        // printf("\n Product Quantity\t : ");
        pdt.product_quantity = get_Input(3);
        // scanf("%i", &pdt.product_quantity);
        fflush(stdin);
        filep1 = fopen("ProductDetails.dat", "a+");
        fprintf(filep1, "%i %s %s %i %i\n", pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
        fclose(filep1);
        printf("\n Press 'Enter' button to add more item and any other key to go to main menu");

    } while ((c = getch()) == '\r'); // c will contain getch() , if the user presses enter, the while loop will be continued if any other key is entered, the loop will stop and will get to next step.
    display_menu();                  // After taking all the input and adding the products , the menu will be shown while the button other than enter is pressed.
}

void delete_product()
{
    int target;
    char check1;
    FILE *fp1, *fp2;
    gotopositionxy(33, 33);
    printf("Delete Product (Y/N)\t : ");
    check1 = getche();
    if (!(check1 == 'y' || check1 == 'Y')) // if user doesn't press y or Y , it will show menu
    {
        display_menu();
    }
    // else
    // {
    //     do nothing
    // }
    system("cls");
    char repeat0; // defining char variable
AGAIN:

    fp1 = fopen("ProductDetails.dat", "r");
    if (fp1 == NULL) // r+ does both read and write
    {
        printf(" \n\n\t\t RECORD FILE IS EMPTY \n");
        printf("\n\t\t Enter any key to go back to main menu\n");
        getch();
        display_menu();
    }
    fp2 = fopen("Temp_ProductDetails.dat", "a+");

    // printf("\n\n\nEnter the code of product to delete : ");
    fflush(stdin);
    // scanf("%i", &target);
    target = get_Input(4);
    int found = 0;

    fseek(fp1, 0, SEEK_CUR);
    while (fscanf(fp1, "%i %s %s %i %i\n", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
    {
        if (target == pdt.product_code)
        {
            found = 1;
            // NOT WRITING TO THE FILE WHEN THE RECORD IS ENCOUNTERED
            // fprintf(fp2, "%i %s %s %i %i\n", pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
        }
        else
        {
            fprintf(fp2, "%i %s %s %i %i\n", pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
        }
    }
    if (!found)
    {
        printf("\nRecord not found");
        getch();
        display_menu();
    }
    else
    {
        printf("\nRecord Deleted\n");
    }
    fclose(fp1);
    fclose(fp2);

    // remove("ProductDetails.dat");
    remove("ProductDetails.dat");

    // rename("Temp_ProductDetails.dat", "ProductDetails.dat");
    rename("Temp_ProductDetails.dat", "ProductDetails.dat");

    printf("\n\nDelete Another Product (Y/N)\t : ");

    repeat0 = getche();
    if (repeat0 == 'y' || repeat0 == 'Y')
    {
        goto AGAIN;
    } /* else display menu */

    display_menu();
}

void search_product()
{
    char check;
    gotopositionxy(33, 33);
    printf("Search Products(Y/N) \t: ");
    check = getche();
    if (check == 'y' || check == 'Y')
    {
        //  do nothing
    }
    else
    {

        display_menu();
    }

    int repitition = 0; // now you can search the items without going to menu and come here back and forth again
again:
    system("cls");      // clears only one time and doesnt clear the recird that you searched for it again.
    char repeat;
    FILE *filep1;
    int a = 0;
    int target_code = 0;
    // we use this variable to ask yes or no later
    long int size = sizeof(pdt); // size of struct product

    if ((filep1 = fopen("ProductDetails.dat", "r+")) == NULL) // r+ does both read and write
    {
        printf(" \n\n\t\t RECORD FILE IS EMPTY \n");
        printf("\n\t\t Enter any key to go back to main menu\n");
        getch();
        display_menu();
    }
    else
    {
        if (repitition > 0)
        {
            printf("\n\n\t\t\tAgain !!\n\n\n\n Code of Product to search\t:");
        }
        else
        {
            printf("Code of Product to search\t: ");
        }
        scanf("%i", &target_code);

        fflush(stdin);

        while (fscanf(filep1, "%i %s %s %i %i\n", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
        {
            if (target_code == pdt.product_code)
            {

                a = 1;
                window(25, 70, 20, 28); 
                gotopositionxy(30, 18);
                printf(" =*=*=*=*=  Product Found  =*=*=*=*=");
                gotopositionxy(30,22);
                printf("Product Code\t\t: %i", pdt.product_code);
                gotopositionxy(30,23);
                printf("Product Name\t\t: %s", pdt.product_name);
                gotopositionxy(30,24);
                printf("Product Company\t\t: %s", pdt.product_company);
                gotopositionxy(30,25);
                printf("Price\t\t\t: %i", pdt.product_price);
                gotopositionxy(30,26);
                printf("Product Quantity\t\t: %i\n\n", pdt.product_quantity);
            }
        }
        if (!a) /* if a = 0  */
        {
            printf("\n\n\n  The product doesn't exists!!!  \n\n\n\n");
        }
        fclose(filep1);
    gotopositionxy(33, 33);
        printf("\n\n\n\nSearch Another Product(Y/N)\t : ");
    }
    repeat = getche();
    printf("\n");
    if (repeat == 'y' || repeat == 'Y')
    {
        repitition = 1;
        goto again;
    }
    // if user presses the Y the process will repeat
    // if user presses any other button than Y he will be automatically directed to the main menu

    display_menu();
}

void display_products()
{

    char check;
    gotopositionxy(33, 33);
    printf("Display All (Y/N) \t: ");
    check = getche();
    if (check == 'y' || check == 'Y')
    {
        //  do nothing
    }
    else
    {

        display_menu();
    }

    
    system("cls");

    FILE *filep1;
    int p = 0;
    int q = 0;
    int y = 8; // declaring this to print the details from the file in the next y axis;

    // if file is null
    if ((filep1 = fopen("ProductDetails.dat", "r")) == NULL)
    {
        gotopositionxy(10, 3);
        printf(" RECORD FILE IS EMPTY");
        printf("\n\t\t Enter any key to go back to main menu");
        getch();
        display_menu();
    }
    else
    {
        gotopositionxy(0, 5);
        for (int i = 0; i < 99; i++)
        {
            printf("-"); // this will be printed 100 times to make a bar like this ----------------------------------------
        }
        printf("\n");

        // we are tweaking with only Y-axis because we want output horizontally like this↓↓↓↓
        // Product Name      Product Price     Product Company    Product Code   Product Quantity  etc
        gotopositionxy(5, 6);
        printf("Product Code");
        gotopositionxy(25, 6);
        printf("Product Name");
        gotopositionxy(40, 6);
        printf("Product Company");
        gotopositionxy(60, 6);
        printf("Product Price");
        gotopositionxy(80, 6);
        printf("Product Quantity");

        printf("\n");
        for (int i = 0; i < 99; i++)
        {
            printf("-"); // this will be printed 100 times to make a bar like this ----------------------------------------
        }
        printf("\n");

        while (fscanf(filep1, "%i %s %s %i %i", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
        {
            gotopositionxy(5, y);
            printf("%i", pdt.product_code);
            gotopositionxy(25, y);
            printf("%s", pdt.product_name);
            gotopositionxy(40, y);
            printf("%s", pdt.product_company);
            gotopositionxy(60, y);
            printf("%i", pdt.product_price);
            gotopositionxy(80, y);
            printf("%i", pdt.product_quantity);

            y++; // this will point to the new line every time the loop repeates
        }
        printf("\n"); // takes to the new line
        for (int i = 0; i < 99; i++)
        {
            printf("-"); // this will be printed 100 times to make a bar like this ----------------------------------------
        }
        printf("\n");
    }
    fclose(filep1);

    gotopositionxy(25, y + 1);

    printf("\n\nEND OF FILE!\n\n");

    printf("\n Enter any key to go to Main Menu ");
    getch();
    display_menu();
}

void credits()
{
       system("cls");
    printf("\n\n\n\n\n");

    printf("\t\t\t   @@@@@@    @@@@@@   @@@@@@@@            @@@@@      @@@    @@@@@@@@@@@     @@@      @@@   @@@@    @@@@        \n");
    printf("\t\t\t   @@@@@@@  @@@@@@@   @@@   @@@           @@@@@@     @@@   @@@@@@@@@@@@@    @@@      @@@    @@@@  @@@@         \n");
    printf("\t\t\t   @@@  @@@@@@  @@@   @@@    @@@          @@@  @@@   @@@   @@@       @@@    @@@      @@@     @@@@@@@@          \n");
    printf("\t\t\t   @@@   @@@    @@@   @@@@@@@@@           @@@   @@@  @@@   @@@       @@@    @@@      @@@      @@@@@            \n");
    printf("\t\t\t   @@@          @@@   @@@@@@@             @@@    @@@ @@@   @@@@@@@@@@@@@     @@@    @@@        @@@             \n");
    printf("\t\t\t   @@@          @@@   @@@   @@@    @@@    @@@     @@@@@@   @@@       @@@      @@@  @@@         @@@             \n");
    printf("\t\t\t   @@@          @@@   @@@    @@@   @@@    @@@      @@@@@   @@@       @@@       @@@@@@          @@@             \n");

    printf("\n\n\nDeveloped by : Nabaraj Dhungel a.k.a Mr.Navy\n");
    printf("E-mail : nabaraj.dhungeel@gmail.com\n");
    printf("Github : https://github.com/nabarajdhungel01");
    printf("\n\n\n\n\n");
    printf("  OKAY \n");
    printf("Thank You!!\n");
    printf("\n\n\n\n\n\n\n\n\n");
    getch();
    display_menu();
}

void edit_product()
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
                else if (count == 8)
                {
                    char check1;
                    gotopositionxy(33, 33);
                    printf("Exit (Y/N)\t : ");
                    check1 = getche();
                    if (!(check1 == 'y' || check1 == 'Y'))
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
    printf("                                              ");
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
    gotopositionxy(104, 22);
    printf("||");
    gotopositionxy(104, 23);
    printf("||");
    gotopositionxy(104, 24);
    printf("||");
    gotopositionxy(104, 25);
    printf("||");
    gotopositionxy(104, 26);
    printf("||");
    gotopositionxy(104, 27);
    printf("||");
    gotopositionxy(104, 28);
    printf("||");
    gotopositionxy(104, 29);
    printf("||");
    gotopositionxy(104, 30);
    printf("||");
    gotopositionxy(104, 31);
    printf("||");
    gotopositionxy(104, 32);
    printf("||");
    gotopositionxy(104, 33);
    printf("||");
    gotopositionxy(104, 34);
    printf("||");
    gotopositionxy(104, 35);
    printf("||");
    gotopositionxy(104, 36);
    printf("||");
    gotopositionxy(104, 37);
    printf("||");
    gotopositionxy(104, 38);
    printf("||");
    gotopositionxy(104, 39);
    printf("||");
    gotopositionxy(104, 40);
    printf("||");
    gotopositionxy(104, 41);
    printf("||");
    gotopositionxy(104, 42);
    printf("||");
    gotopositionxy(104, 43);
    printf("||");
    gotopositionxy(104, 44);
    printf("||");
    gotopositionxy(104, 45);
    printf("||");
    gotopositionxy(104, 46);
    printf("||");
    gotopositionxy(104, 47);
    printf("||");
    gotopositionxy(104, 48);
    printf("||");
    gotopositionxy(104, 49);
    printf("||");
}

void window(int a, int b, int c, int d)
{
    int i;
    // textcolor(1);
    // textcolor(4);
    for (i = a; i <= b; i++)
    {
        gotopositionxy(i, 17);
        printf("\xcd");
        gotopositionxy(i, 19);
        printf("\xcd");
        gotopositionxy(i, c);
        printf("\xcd");
        gotopositionxy(i, d);
        printf("\xcd");
    }

    gotopositionxy(a, 17);
    printf("\xc9");
    gotopositionxy(a, 18);
    printf("\xba");
    gotopositionxy(a, 19);
    printf("\xc8");
    gotopositionxy(b, 17);
    printf("\xbb");
    gotopositionxy(b, 18);
    printf("\xba");
    gotopositionxy(b, 19);
    printf("\xbc");
    // textcolor(4);
    for (i = c; i <= d; i++)
    {
        gotopositionxy(a, i);
        printf("\xba");
        gotopositionxy(b, i);
        printf("\xba");
    }
    gotopositionxy(a, c);
    printf("\xc9");
    gotopositionxy(a, d);
    printf("\xc8");
    gotopositionxy(b, c);
    printf("\xbb");
    gotopositionxy(b, d);
    printf("\xbc");
    // textbackground(11);
    // textcolor(0);
}

int get_Input(int o) // only accepts numeric input

{
    int num;
    int ch;
    int count;
AGAIN:
    num = 0;
    ch = 0;
    count = 0;

    printf("\n");
    switch (o)
    {
    case 1:
        printf("\n\n\n Product Code  ( Numbers Only )  \t\t : ");
        break;
    case 2:
        printf("\n\n\n Product Price\t\t : ");
        break;
    case 3:
        printf("\n\n\n Product Quantity\t : ");
        break;
    case 4:
        printf("\n\n\nEnter the code of product to delete : ");
        break;
    default:
        break;
    }

    // printf("\n\n Balance :  ");  // respective printing message will be print ;
    // printf("\n\n INPUT :  ");
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
            { // after entered is pressed, it stops taking input

                printf(" \n \t\t\t \"Enter pressed\" ");
                return num;
                break;
            }
        }
        else
        {
            printf("\n\n\t\t    **********Invalid input..********* ");
            printf("\n \t\t **********Provide numeric input only********* ");

            goto AGAIN;
        }
    }
}
