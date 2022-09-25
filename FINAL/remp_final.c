
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
void display_bill_customer(char fname[128]); // pass the bill name and print the bill template;

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
void export_data_excel_file();
void display_bill_template();

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
    // printf("----------------------------------------------------------------------------------------");
    // gotopositionxy(1, 27);
    // printf("S.N.  Code  Name    Qt.Left  Company    Qty.  Rate  Total\n");
    // gotopositionxy(0, 28);
    // printf("----------------------------------------------------------------------------------------");

    calculate_bill();

    // display_menu();
}

void display_menu()
{
    system("cls"); // will clear the screen to show the menu
    printf("\n\n\n\n\n\n");
    printf("\t  $$$   $$   $$$$$   $$   $$  $$  $$       $$$$$$      $     $   $$$$$    $$$$$  \n");
    printf("\t  $$$$$ $$  $$   $$  $$   $$  $$$$$$      $            $     $   $     $  $    $ \n");
    printf("\t  $$  $$$$  $$$$$$$  $$  $$     $$        $$$$$$$$     $$$$$$$   $     $  $$$$$$ \n");
    printf("\t  $$   $$$  $$   $$    $$       $$                $    $     $   $     $  $      \n");
    printf("\t  $$   $$$  $$   $$    $$       $$         $$$$$$$$    $     $   $$$$$$$  $      \n");

    remove("temp_clone_ProductDetails.dat"); // removes the clone file

    window(25, 60, 20, 32);
    const char *menu[] = {"\tCalculate Bill", "\tAdd Product", "\tDelete Product", "\t Search Product", "\tDisplay All", "Edit Product", "Credits", "Export Data(Excel Format )", "Exit"};
    gotopositionxy(33, 18);
    printf("MAIN MENU");
    for (int i = 0; i <= 8; i++)
    {
        gotopositionxy(30, 22 + i);
        printf("%s\n\n\n", menu[i]);
    }
    cursor(9); // 7

    printf("final");
    getch();
}

void calculate_bill()
{
    remove("temp_clone_ProductDetails.dat"); // REMOVING IF THERE IS ALREADY FILE NAMED THESE
    remove("Temp_ProductDetails.dat");       // REMOVING IF THERE IS ALREADY FILE NAMED THESE

    char check1;
    gotopositionxy(33, 33);
    printf("Calculate Bill (Y/N)\t : ");
    check1 = getche();
    if (!(check1 == 'y' || check1 == 'Y'))
    {
        display_menu();
    }

    // WE USE THIS VALUES TO STORE THE VALUE OF THE SELECTED CODE NUMBER TEMPORARAILY AND TO PRINT ON THE BILL   ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    int temp_code = 0;
    char temp_name[40];
    char temp_company_name[40];
    int temp_price = 0;
    int temp_total_quantity = 0;
    int temp_total_price = 0;
    int Grand_Total_Price = 0;
    int Discount_Amount = 0;
    // WE USE THIS VALUES TO STORE THE VALUE OF THE SELECTED CODE NUMBER TEMPORARAILY AND TO PRINT ON THE BILL  ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
    // PRINTS THE BILL OUTLINE DISPLAY TO THE USER
    display_bill_template();

    // checking if the code is repeated or not
    int sn = 0;

    // THIS WILL TAKE THE FILE NAME FOR THE CUSTOMER'S BILL//// to store print the customer file to txt file      ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    int qt = 0; // quantity

    // DECLARATIONS OF VARIABLE TO PRINT TO THE BILL FILE
    char fname[128];
    gotopositionxy(2, 5);
    printf("Enter .txt file name to store the customer bill  : ");
    scanf("%123s", fname); // for buffer of 124 bytes
    printf("\n\nPress any key to continue");
    getch();
    gotopositionxy(2, 5);
    printf("                                                                        "); // will clear the screen
    strcat(fname, ".txt");                                                              // this will add the .txt and file name together

    // OPENING THE BILL FILE to be printed..
    // Writing the following details to the bill.txt file
    FILE *inputf;
    inputf = fopen(fname, "a+");
    // inputf = fopen("Bill.txt", "a+");
    time_t t;
    time(&t);
    fprintf(inputf, "	  NAVY CYBER STORE          \n");
    fprintf(inputf, "	      L.A., USA               \n");
    fprintf(inputf, "             Date: 11/07/2022        \n"); // fprintf("\t\t\t\t\t%s", ctime(&t)); // Print Time
    fprintf(inputf, "\n");
    fprintf(inputf, "---------------------------------------\n");
    fprintf(inputf, "Particulars     Rate    Qty.    Amount\n");
    fprintf(inputf, "---------------------------------------\n");
    fclose(inputf);
    display_bill_customer(fname);
    int code;
    int found;
ADD_PRODUCT_AGAIN:
    found = 0;
    clear_seven_to_nineteen();
    separator_line();
    FILE *fp1;

    fp1 = fopen("ProductDetails.dat", "r");
    // fp2 = fopen(fname, "a+");

    // CHECKS IF THE FILE IS EMPTY OR NOT  ↓↓↓↓↓
    if (fp1 == NULL) // r+ does both read and write
    {
        printf(" \n\n\t\t RECORD FILE IS EMPTY \n");
        printf("\n\t\t Enter any key to go back to main menu\n");
        getch();
        display_menu();
    }
    else
        // CHECKS IF THE FILE IS EMPTY OR NOT  ↑↑↑↑↑
        code = 0; // initializing with zero

AGAIN: // this is used when the user inputs the code that is not in the database.      ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    found = 0;
    clear_seven_to_nineteen();
    separator_line();

    gotopositionxy(2, 5);
    printf("\n\nCode of Product  :                                                                                                                      "); // this space will clear the line when you add the next product next time
    gotopositionxy(19, 7);
    // scanf("%d", &code);
    code = get_Input(8);

    // CHECKS IF THE CODE IS PRESENT OR NOT and prints found if present   ↓↓↓↓↓ else asks to add the code again
    fseek(fp1, 0, SEEK_SET); // moves cursor to the beginning of the file
    temp_code = code;
    while (fscanf(fp1, "%i %s %s %i %i\n", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
    {
        if (code == pdt.product_code)
        {
            gotopositionxy(25, 7);
            printf("***Found***      || Name || :- \"%s\"  || Rate || :- \"%d\"  ||Total Qty.|| :- \"%d\" ", pdt.product_name, pdt.product_price, pdt.product_quantity);
            found = 1;
            // sn = sn + 1;  // dont increase the sn here because if the product is found and you do not want to proceed further the value will be increased
            // which will cause error in the symbol number
            temp_code = pdt.product_code;
            temp_price = pdt.product_price;
            temp_total_quantity = pdt.product_quantity;
            strcpy(temp_name, pdt.product_name);
            strcpy(temp_company_name, pdt.product_company);
            // IF THE STOCKS IS ZERO, IT DISPLAY NO STOCKS LEFT ADD CHOOSE ANOTHER PRODUCT

            if (temp_total_quantity == 0)
            {
                // printf("no stocks left");
                goto no_stocks_left_goto_function;
            }

            // IF THE STOCKS IS ZERO, IT DISPLAY NO STOCKS LEFT ADD CHOOSE ANOTHER PRODUCT

            // dont multiply here TO GET GRAND TOTAL and total some error will occur that will print the address of the temp_total _price instead of the value // temp_total_price = temp_price * qt ;
        }
    }
    if (found == 0)
    {
        int repeat__ = 0;
    INVALID_INPUT_ENTER_CODE_AGAIN:

        gotopositionxy(0, 7);
        {
            char checkkk;
            if (repeat__ == 0)
                printf("SUPPLIED  CODE IS NOT IN THE DATABASE.. Enter code again:");

            gotopositionxy(25, 17);

            checkkk = getche();

            if (sn = 0) // if the user hadnt add any of the products
            {
                printf("\n\n PRESS \"A\" TO ENTER THE RIGHT CODE AGAIN");
                printf("\n\n\t\t\t OR \n\n");
                printf("\n\n PRESS \"M\" TO GET BACK TO MENU");
                if (checkkk == 'A' || checkkk == 'a') // if (checkkk_big_letter == "END" )  // to compare string we use strcmp lol
                {
                    goto AGAIN;
                }
                else if (checkkk == 'M' || checkkk == 'm')
                {
                    display_menu();
                }
                else
                {
                    printf("\n\n INVALID INPUT !!  \n\n ENTER YOUR CHOICE AGAIN");
                    repeat__++;
                    goto INVALID_INPUT_ENTER_CODE_AGAIN; // goto function
                }
            }
            else // if sn > 0 , // if one product is already added dont give option to go back to menu
            {
                printf("\n\n PRESS \"A\" TO ENTER THE RIGHT CODE AGAIN");

                if (checkkk == 'A' || checkkk == 'a') // if (checkkk_big_letter == "END" )  // to compare string we use strcmp lol
                {
                    goto AGAIN;
                }
                else
                {
                    printf("\n\n INVALID INPUT !!  \n\n ENTER YOUR CHOICE AGAIN");
                    repeat__++;
                    goto INVALID_INPUT_ENTER_CODE_AGAIN; // goto function
                }
            }

            // IF THE CODE IS NOT PRESENT ASKING AGAIN TO INPUT THE CODE:↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

        ENTER_STOCKS_AGAIN:

            gotopositionxy(2, 7);
            printf("\n\nQty. for Billing :                          ");
            gotopositionxy(19, 9);
            qt = get_Input(9);
            // scanf("%i", &qt);
            gotopositionxy(0, 11);
            printf("                                                                                                     "); // will clear the line

            if (qt == 0 || qt < 0)
            {
                printf("\nINVALID INPUT!!! ENTER QUANTITY MORE THAN ZERO");
                goto ENTER_STOCKS_AGAIN;
            }

            // COMPARING USER INPUT QUANTITY VS TOTAL QUANTITY IN THE DATABASE  ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

            if (temp_total_quantity == 0)
            {
                gotopositionxy(2, 18);
            no_stocks_left_goto_function:
                printf("\n\n NO STOCKS LEFT !!!!    CHOOSE ANOTHER PRODUCT");
                getch();
                clear_seven_to_nineteen(); // will clear line from seven to nineteen
                separator_line();
                goto AGAIN;
            }
            else if (qt > temp_total_quantity)
            {
                gotopositionxy(2, 18);
                printf("WE DON'T HAVE REQUIRED QUANTITY !!!!   ONLY %d STOCKS LEFT !!   PLEASE RE-ENTER STOCKS :  ", temp_total_quantity);
                goto ENTER_STOCKS_AGAIN;
            }
            else
            {
                printf(""); // do nothing continue
            }

            // COMPARING USER INPUT QUANTITY VS TOTAL QUANTITY IN THE DATABASE   ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

            // WILL CLEAR THESE THREE LINES              ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
            gotopositionxy(2, 18);
            printf("                                                                                                                            ");
            gotopositionxy(2, 19);
            printf("                                                                                                                            ");
            gotopositionxy(2, 20);
            printf("                                                                                                                            ");
            // WILL CLEAR THESE THREE LINES              ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

            // ASKING FOR THE USER TO CONFIRM TO ADD THE PRODUCT OR NOT
            char checkk1;
            gotopositionxy(5, 18);
            printf("WARNING!!!!!! Pressing y will reduce the quantity sold from the database, Proceed::");
            printf("\nAdd (Y/N)\t : ");
            checkk1 = getche();

            if (!(checkk1 == 'y' || checkk1 == 'Y')) // if the user press any key other than y then the condition will run..
            {
                // printf("325");
                printf("\n\nYou pressed N, The item is discarded, add another product again \n\n Press enter");
                fflush(stdin);
                getch();
                goto AGAIN;
            }

            // DECREASE THE QUANTITY ENTERED//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
            // printf("333");

            FILE *fp3;
            fp3 = fopen("Temp_ProductDetails.dat", "a+");
            fseek(fp1, 0, SEEK_SET); // seek the beginning of the file...

            if (found == 1)
            // printf("340");
            {
                while (fscanf(fp1, "%i %s %s %i %i", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
                {
                    if (code == pdt.product_code)
                    {
                        pdt.product_quantity = pdt.product_quantity - qt;
                        // we cannot store the
                    }
                    fprintf(fp3, "%i %s %s %i %i\n", pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
                }
            }
            // printf("352");

            fclose(fp1);
            // printf("355");
            // printf("360");
            fclose(fp3);

            // printf("Removing ProductDetails.dat, press any key\n");
            // getch();
            remove("ProductDetails.dat");

            // printf("Temp_productdetails.dat, press any key\n");
            // getch();
            rename("Temp_ProductDetails.dat", "ProductDetails.dat");

            sn = sn + 1; // AFTER ONE PRODUCT IS ADDED , THE SN WIL INCREASE BY 1.

            // temp_total_price = temp_price * qt ; // multiply rate * quantity
            temp_total_price = multiplyAB(qt, pdt.product_price);     // this user-defined function will do the job
            Grand_Total_Price = Grand_Total_Price + temp_total_price; // this will keep adding the value in the variable

            // reducing the

            // PRINTING THE VALUE TO THE SCREEN;
            gotopositionxy(18, 28 + sn); // the sn will change the each times the value will print.
            // this will do a bit error when printing next time    // printf("%i.\t %i\t%s\t\t  %i\t\t%s\t%i\t%i\t%i",sn,temp_code,temp_name,temp_total_quantity,temp_company_name,qt,temp_price, temp_total_price);
            // Specifying address where to print the value
            gotopositionxy(1, 28 + sn);
            printf("%d.", sn);
            gotopositionxy(7, 28 + sn);
            printf("%d", temp_code);

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
                                gotopositionxy(14, 28 + sn);

                                for (int i = 0; i < 6 /* name_length */; i++) // print only 6 characters
                                {
                                    printf("%c", temp_name[i]);
                                }
                            }
                            else /* if (strlen(temp_name < 7  ) */ // IF THE NAME LENGTH IS LESS THAN 7
                                gotopositionxy(14, 28 + sn);

                            for (int i = 0; i < name_length; i++)
                            {
                                printf("%c", temp_name[i]);
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
            gotopositionxy(23, 28 + sn);
            printf("%d", temp_total_quantity);

            gotopositionxy(32, 28 + sn);
            printf("%s", temp_company_name);

            // PRINT ONLY FIRST 6 LETTER OF THE NAME
            {
                {
                    int name_length;
                    name_length = strlen(temp_company_name);

                    if (name_length > 6)
                    {
                        gotopositionxy(32, 28 + sn);

                        for (int i = 0; i < 6 /* name_length */; i++) // print only 6 characters
                        {
                            printf("%c", temp_company_name[i]);
                        }
                    }
                    else /* if (strlen(temp_company_name < 7  ) */ // IF THE NAME LENGTH IS LESS THAN 7
                        gotopositionxy(32, 28 + sn);

                    for (int i = 0; i < name_length; i++)
                    {
                        printf("%c", temp_company_name[i]);
                    }
                }
                printf("."); // will print dot after name
            }

            gotopositionxy(42, 28 + sn);
            printf("%d", qt);
            gotopositionxy(48, 28 + sn);
            printf("%d", temp_price);
            gotopositionxy(55, 28 + sn);
            printf("%d", temp_total_price);

            // ADDING THE BILL DETAILS TO THE CUSTOMER BILL
            inputf = fopen(fname, "a+");
            fseek(inputf, 0, SEEK_END);
            fprintf(inputf, "%s\t\t\t%d\t\t%d\t\t%d\n", temp_name, temp_price, qt, temp_total_price);
            fclose(inputf);
            // THIS WILL PRINT THE BILL ON THE SCREEN
            gotopositionxy(66, (31 + sn));

            // for (int i = 0; i < 7; i++)
            // {
            //     printf("%c", temp_name[i]);
            // }

            // print the name of the product
            {
                {
                    // this will print the first 7 characters of the temp_name
                    gotopositionxy(66, 31 + sn);
                    // PRINT ONLY FIRST 6 LETTER OF THE NAME
                    {
                        {
                            int name_length;
                            name_length = strlen(temp_name);

                            if (name_length > 6)
                            {
                                gotopositionxy(66, 31 + sn);

                                for (int i = 0; i < 6 /* name_length */; i++) // print only 6 characters
                                {
                                    printf("%c", temp_name[i]);
                                }
                            }
                            else /* if (strlen(temp_name < 7  ) */ // IF THE NAME LENGTH IS LESS THAN 7
                                gotopositionxy(66, 31 + sn);

                            for (int i = 0; i < name_length; i++)
                            {
                                printf("%c", temp_name[i]);
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

            // printf("."); // will print dot after name

            // gotopositionxy()
            printf("\t\t%d\t%d\t%d\n", temp_price, qt, temp_total_price);

            // ADDING THE BILL DETAILS TO THE CUSTOMER BILL

            // WRITING ALL THE PURCHASE DETAILS FOR EVERY PRODUCT AND SESSION TO ONE FILE

            FILE *totalp;
            totalp = fopen("Total_Sales_Details.txt", "a+");
            fseek(totalp, 0, SEEK_END);
            fprintf(totalp, "%s\t\t\t%d\t\t%d\t\t%d\n", temp_name, temp_price, qt, temp_total_price);
            fclose(totalp);

            // WRITING ALL THE PURCHASE DETAILS FOR EVERY PRODUCT AND SESSION TO ONE FILE

            gotopositionxy(0, 13);
            printf("Add Another Product(Y/N) : ");
            char hehe;
            hehe = getche();
            if (hehe == 'y' || hehe == 'Y')
            {

                // gotopositionxy(2, 5);
                // // this code will clear the line with spaces
                // printf("\n\nCode of Product  :                                                                                                                      "); // this space will clear the line when you add the next product next time
                // gotopositionxy(2, 7);
                // printf("\n\nQty. for Billing :                          ");

                // // this will print the following in the position
                // gotopositionxy(0, 13);
                // printf("Add Another Product(Y/N) :       ");

                goto ADD_PRODUCT_AGAIN;
            }

            /*  else if the user is done with adding the items then  */
            gotopositionxy(0, 15);
            printf("CALCULATING TOTAL PRICE...\n");
            printf("PRESS ANY KEY TO SHOW THE BILL : ");
            getch();
            // printing the grand total price for shopkeepers bill

            gotopositionxy(0, 28 + sn + 1); // will print after all the products are shown on the bill
            printf(" ------------------------------------------");

            gotopositionxy(29, 28 + sn + 2); // will print after all the products are shown on the bill
            printf("======================");

            gotopositionxy(30, 28 + sn + 3);
            printf("Grand Total:   %d", Grand_Total_Price);

            gotopositionxy(29, 28 + sn + 4);
            printf("======================");

            // printing the grand total price for shopkeepers bill

            // printing the grand total price for customer's bill on OUTPUT SCREEN

            gotopositionxy(82, 31 + sn + 1);
            printf("=====================");
            gotopositionxy(83, 31 + sn + 2);
            printf("Grand Total : %d", Grand_Total_Price);
            gotopositionxy(82, 31 + sn + 3);
            printf("=====================");
            // printing the grand total price for customer's bill on OUTPUT SCREEN

            // printing the grand total price in the file at last
            inputf = fopen(fname, "a+");
            fseek(inputf, 0, SEEK_END);
            fprintf(inputf, "                   =====================\n");
            fprintf(inputf, "                    Grand Total : %d\n", Grand_Total_Price);
            fprintf(inputf, "                   =====================\n");
            fprintf(inputf, "\n\t\tThank You, Visit again.");
            fclose(inputf);

            // printing the grand total price in the file at last

            printf("\nPress any key to go back to main menu");
            getch();
            display_menu();

            getch();
        }
    }
}

void display_bill_customer(char fname[128])
{
    // THIS WILL PRINT ON THE OUTPUT SCREEN
    gotopositionxy(70, 22);
    printf(" customer bill is printed on  ");
    gotopositionxy(77, 23);
    printf("\"%s\" file", fname);
    // printf(" bills.txt ");
    gotopositionxy(68, 25);
    printf("       CUSTOMER'S BILL\n");
    gotopositionxy(70, 26);
    printf("	  NAVY CYBER STORE           \n");
    gotopositionxy(70, 27);
    printf("	    L.A., USA               \n");
    gotopositionxy(70, 28);
    printf("                     - 12 June        \n"); // fprintf("\t\t\t\t\t%s", ctime(&t)); // Print Time
    gotopositionxy(63, 29);
    printf(" ------------------------------------------\n");
    printf("\n");
    gotopositionxy(65, 30);
    printf("Particulars	Rate	Qty.	Amount\n");
    gotopositionxy(63, 31);
    printf(" ------------------------------------------\n");
}

void display_bill_template()
{

    system("cls");
    //  ↓↓↓↓↓↓↓↓\t\t↓↓↓↓ TEMPLATE OF BILL ↓↓↓↓↓↓↓↓↓↓↓↓
    printf("\t\t\t ************************************ \n");
    printf("\t\t\t ****** * Mr.Navy Cyber Cafe * ******");
    printf("\n\n");
    printf("\t\t\t\tInventory Management");
    // textcolor(1);
    gotopositionxy(20, 25);
    printf("SHOPKEEPER'S BILL\n");
    // textcolor(8);
    gotopositionxy(0, 26);
    printf("----------------------------------------------------------");
    gotopositionxy(1, 27);
    printf("S.N.  Code  Name    Qt.Left  Company    Qty.  Rate  Total\n");
    // printf("S.N. 2 Code 2 Name   Qt.Left 2 Company 2 Qty.2Rate 2 Total\n");

    gotopositionxy(0, 28);
    // printf("----------------------------------------------------------");
    // printf("12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890");// to locate the position in the terminal
    separator_line(); // adds the horizontal separator in the right bottom corner side
}

void add_product()
{
    remove("temp_clone_ProductDetails.dat"); // REMOVING IF THERE IS ALREADY FILE NAMED THESE
    remove("Temp_ProductDetails.dat");       // REMOVING IF THERE IS ALREADY FILE NAMED THESE

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
    remove("temp_clone_ProductDetails.dat"); // REMOVING IF THERE IS ALREADY FILE NAMED THESE
    remove("Temp_ProductDetails.dat");       // REMOVING IF THERE IS ALREADY FILE NAMED THESE

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
    remove("temp_clone_ProductDetails.dat"); // REMOVING IF THERE IS ALREADY FILE NAMED THESE
    remove("Temp_ProductDetails.dat");       // REMOVING IF THERE IS ALREADY FILE NAMED THESE

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
    system("cls"); // clears only one time and doesnt clear the recird that you searched for it again.
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
                gotopositionxy(30, 22);
                printf("Product Code\t\t: %i", pdt.product_code);
                gotopositionxy(30, 23);
                printf("Product Name\t\t: %s", pdt.product_name);
                gotopositionxy(30, 24);
                printf("Product Company\t\t: %s", pdt.product_company);
                gotopositionxy(30, 25);
                printf("Price\t\t\t: %i", pdt.product_price);
                gotopositionxy(30, 26);
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
    remove("temp_clone_ProductDetails.dat"); // REMOVING IF THERE IS ALREADY FILE NAMED THESE
    remove("Temp_ProductDetails.dat");       // REMOVING IF THERE IS ALREADY FILE NAMED THESE

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

    remove("temp_clone_ProductDetails.dat"); // REMOVING IF THERE IS ALREADY FILE NAMED THESE
    remove("Temp_ProductDetails.dat");       // REMOVING IF THERE IS ALREADY FILE NAMED THESE

    char check1;
    gotopositionxy(33, 33);
    printf("Edit Product (Y/N)\t : ");
    check1 = getche();
    if (!(check1 == 'y' || check1 == 'Y'))
    {
        display_menu();
    }
    // else
    // {
    //     do nothing
    // }
    // COPYING THE FILE TO ANOTHER NAME;
    {
        {
            {
                {
                    {
                        {
                            char ch, source_file[25], target_file[25];

                            FILE *source, *target;

                            source = fopen("ProductDetails.dat", "r");

                            target = fopen("temp_clone_ProductDetails.dat", "w");

                            while ((ch = fgetc(source)) != EOF)
                                fputc(ch, target);

                            printf("File copied successfully.\n");
                            fclose(source);
                            fclose(target);
                        }
                    }
                }
            }
        }
    }

    FILE *filep1;
    FILE *filep2; // to create the new temp file
    FILE *filep3;
    int index;
    int valid;
    int i;
    char target[40];
    int a = 0;
    int target_code;
    int edited_new_code;
    char edit;
    char abc;
    char xyz;
    int reps = 0;
    // we use this variable to ask yes or no later
    if ((filep1 = fopen("ProductDetails.dat", "r")) == NULL) // r+ does both read and write
    {
        printf(" \n\n\t\tRECORD FILE IS EMPTY\n");
        printf("\n\t\t Enter any key to go back to main menu\n");
        getch();
        display_menu(); // will go to the main menu if the file is empty
    }
    // else // else is not compulsory here bcz if there is no file present above condition call displaY_menu()
    {
        long int size = sizeof(pdt); // size of struct product
        system("cls");
        printf("Code of Product to edit\t : ");
        scanf("%i", &target_code);

        printf("\n\n\nEdit Product %i (Y/N) : ", target_code);
        abc = getche();
        if (!(abc == 'y' || abc == 'Y')) // user doesnt inputs y, it will go to main menu
        {
            display_menu();
        }
        filep2 = fopen("Temp_ProductDetails.dat", "a+");

        fflush(stdin);
        fseek(filep1, 0, SEEK_CUR);
        while (fscanf(filep1, "%i %s %s %i %i\n", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
        {
            if (target_code == pdt.product_code)
            {
                char original_pdt_product_name[30];
                char original_pdt_product_company[40];
                int original_pdt_product_code;
                int original_pdt_product_price;
                int original_pdt_product_quantity;

                a = 1; // found = 1;
                printf("\n\n\n\t =*=*=*=*=  Record Found  =*=*=*=*=\n\n");
                printf("Product Code\t\t: %i", pdt.product_code);
                printf("\nProduct Name\t\t: %s", pdt.product_name);
                printf("\nProduct Company\t\t: %s", pdt.product_company);
                printf("\nPrice\t\t\t: %i", pdt.product_price);
                printf("\nProduct Quantity\t:%i ", pdt.product_quantity);

                // STORING THE SCANNED VALUE FOR FUTURE USE
                {
                    {
                        original_pdt_product_code = pdt.product_code;

                        for (int i = 0; i < 30; i++)
                        {
                            original_pdt_product_name[i] = pdt.product_name[i];
                        }

                        for (int i = 0; i < 40; i++)
                        {
                            original_pdt_product_company[i] = pdt.product_company[i];
                        }

                        original_pdt_product_price = pdt.product_price;
                        original_pdt_product_quantity = pdt.product_quantity;
                    }
                }

                printf("\n\n\n\n\t =*=*=*=*=  New Record  =*=*=*=*=\n\n");

                // New Code Number
            CHECKING_CODE_REPITITION: // checks if the to be edit data will enter the another matching id

                // if (reps > 0)
                // {
                // printf("\n\n Enter the New Code Number again\n\n\n");
                // }
                // else
                // {
                // printf("New Code Number\t\t: ");
                // }
                // scanf("%i", &edited_new_code);
                edited_new_code = get_Input(5);
                // CHECKING IF THE EDIT CODE INPUT BY USER IS REPEATED OR NOT
                ///////////////////////////////////////////////////////////
                // OPENING THE CLONE FILE
                // OPENING THE CLONE FILE
                // OPENING THE CLONE FILE
                // OPENING THE CLONE FILE
                {
                    {

                        filep3 = fopen("temp_clone_ProductDetails.dat", "r");
                        fseek(filep3, 0, SEEK_SET); // this will again point to the beginning of the file so that the repition can be checkde.
                        while (fscanf(filep3, "%i %s %s %i %i", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
                        {

                            /*
                            fscanf reads every data stored in the file
                            if entered staffID already exist then jumps to
                            position I declared inside if(sfile!=NULL) at top
                            */

                            {
                                /* code */
                            }
                            if (!(target_code == pdt.product_code)) // this condition allows you to enter the same id as the previous id
                            {
                                if (edited_new_code == pdt.product_code) // this condition will show error if you enter the new product id code that matches with any other product id code
                                {
                                    printf("\n\tTHE PRODUCT CODE ALREADY EXIST.\n");
                                    reps = 1;
                                    goto CHECKING_CODE_REPITITION;
                                }
                            }
                            /* else continue */

                            // else
                            //  {} do nothing
                        }
                    }
                }
                // this upper loop checked if the code is mattching or not

                ///////////////////////////////////////////////////////////
                pdt.product_code = edited_new_code; // this will save the new code number
                                                    //  New Product Name
                do
                {
                    fflush(stdin);
                    printf("\nNew Product Name\t: ");
                    gets(pdt.product_name);                             // takes input from user
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
                } while (!valid); // while ends here,  it will keep taking input until all the characters aare good.

                // New Product Company
                do
                {
                    // char product_company[40];
                    fflush(stdin);
                    printf("\nProduct Company\t\t: ");
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
                // New Product Price
                pdt.product_price = get_Input(6);
                // printf("\nPrice \t\t:");
                // scanf("%i", &pdt.product_price);

                // New  Product Quantity
                pdt.product_quantity = get_Input(7);
                // printf("\nQuantity \t\t: ");
                // scanf("%i", &pdt.product_quantity);

                printf("\n\n\nEdit Confirm(Y/N)\t:");
                edit = getche();

                if (edit == 'y' || edit == 'Y')
                {
                    fprintf(filep2, "%i %s %s %i %i\n", pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
                    fflush(stdin);
                    printf("\n\n\t\t THE RECORD IS SUCCESSFULLY EDITED!!!");
                    fclose(filep3);
                    fclose(filep3);
                    remove("temp_clone_ProductDetails.dat");
                }
                else
                {
                    printf("\n\nYou pressed \"N \" ,\n\n Getting back to MENU without editing the Details! ");
                    fclose(filep2);
                    remove("Temp_ProductDetails.dat");
                    fclose(filep1);

                    fclose(filep3);
                    remove("temp_clone_ProductDetails.dat"); // removes the clone file

                    getch();
                    display_menu();
                    // IF THE USER PRESS ANY OTHER BUTTON THAN Y, the temp file will be deleted and file1 will remain unchanged
                    // IF THE USER DOESN'T PRESS Y to EDIT , then the default scanned parameters will be written to the file
                    // fprintf(filep2, "%i %s %s %i %i\n", original_pdt_product_code, original_pdt_product_name, original_pdt_product_company, original_pdt_product_price, original_pdt_product_quantity);
                    fflush(stdin);
                }
                // if ends here we are not using the else for this if ↑↑↑↑↑↑↑↑↑↑↑↑
            }
            else
            {
                fprintf(filep2, "%i %s %s %i %i\n", pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
            }

        } // while ends here
        if (!a)
        {
            printf("\n\n  The product doesn't exists!!!  \n\n");
        }
        fclose(filep3);
        remove("temp_clone_ProductDetails.dat"); // removes the clone file
        fclose(filep1);
        fclose(filep2);
        remove("ProductDetails.dat");
        rename("Temp_ProductDetails.dat", "ProductDetails.dat");
        getch();
        fclose(filep3);
        remove("temp_clone_ProductDetails.dat"); // removes the clone file

        display_menu();
    }
}

void export_data_excel_file()
{
    time_t t; // use this code by adding enter on it..  //#include <stdio.h> #include<time.h> int main() {    	time_t t;	time(&t);     printf("Date and Time is : %s",ctime(&t));     return 0; }
    time(&t);

    char check1;
    FILE *fp1, *fp2;
    gotopositionxy(22, 33);
    printf("Export Data in Excel (csv)?(Y/N)\t : ");
    check1 = getche();
    if (!(check1 == 'y' || check1 == 'Y')) // if user doesn't press y or Y , it will show menu
    {
        display_menu();
    }
    system("cls");
    char repeat0; // defining char variable

    printf("Enter the name of the file : ");
    char filename[30] = {0};
    char extension[] = ".csv";

    gets(filename);

    strcat(filename, extension);

    fp1 = fopen("ProductDetails.dat", "r");
    if (fp1 == NULL) // r+ does both read and write
    {
        printf(" \n\n\t\t RECORD FILE IS EMPTY \n");
        printf("\n\t\t Enter any key to go back to main menu\n");
        getch();
        display_menu();
    }

    fp2 = fopen(filename, "a+");
    fseek(fp1, 0, SEEK_CUR);
    fprintf(fp2, " \n NAVY INVENTORY MGMT SYSTEM\n");
    fprintf(fp2, " Product Details \n");
    fprintf(fp2, "Export Time : %s", ctime(&t));
    fprintf(fp2, "\n\n S.No, Product Code,\"Product Name\",\"Product Company\",\"Qty\",\"Price\"\n");
    int i = 1;
    while (fscanf(fp1, "%i %s %s %i %i\n", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
    {
        fprintf(fp2, "%i,%i,%s,%s,%i,%i\n", i, pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
        i++;
    }
    fclose(fp1);
    fclose(fp2);

    display_menu();
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
            if (position == 9)
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
                    export_data_excel_file();
                else if (count == 9)
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
    if (position == 9)
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
        printf("   Export Data(Excel)      ");
        gotopositionxy(30, 30);
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
            printf("-  Export Data(Excel)      ");
            break;
        case 9:
            gotopositionxy(30, 30);
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
    printf("                                                                ");
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

    printf("\n");
    gotopositionxy(61, 22);
    printf("||");
    gotopositionxy(61, 23);
    printf("||");
    gotopositionxy(61, 24);
    printf("||");
    gotopositionxy(61, 25);
    printf("||");
    gotopositionxy(61, 26);
    printf("||");
    gotopositionxy(61, 27);
    printf("||");
    gotopositionxy(61, 28);
    printf("||");
    gotopositionxy(61, 29);
    printf("||");
    gotopositionxy(61, 30);
    printf("||");
    gotopositionxy(61, 31);
    printf("||");
    gotopositionxy(61, 32);
    printf("||");
    gotopositionxy(61, 33);
    printf("||");
    gotopositionxy(61, 34);
    printf("||");
    gotopositionxy(61, 35);
    printf("||");
    gotopositionxy(61, 36);
    printf("||");
    gotopositionxy(61, 37);
    printf("||");
    gotopositionxy(61, 38);
    printf("||");
    gotopositionxy(61, 39);
    printf("||");
    gotopositionxy(61, 40);
    printf("||");
    gotopositionxy(61, 41);
    printf("||");
    gotopositionxy(61, 42);
    printf("||");
    gotopositionxy(61, 43);
    printf("||");
    gotopositionxy(61, 44);
    printf("||");
    gotopositionxy(61, 45);
    printf("||");
    gotopositionxy(61, 46);
    printf("||");
    gotopositionxy(61, 47);
    printf("||");
    gotopositionxy(61, 48);
    printf("||");
    gotopositionxy(61, 49);
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
    case 5:
        printf("\n\n New  Code Number\t\t : ");
        break;
    case 6:
        printf("\n\n New Product Price\t\t : ");
        break;
    case 7:
        printf("\n\n New Product Qty.\t\t : ");
    case 8:
        gotopositionxy(2, 5);
        printf("\n\nCode of Product  :                                                                                                          ");
        gotopositionxy(19, 7);
        break;
    case 9:
        gotopositionxy(2, 7);
        printf("\n\nQty. for Billing :                          ");
        gotopositionxy(19, 9);
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
            else if (o == 8 || o == 9)
            {
                return num;
                // do notprint the eenter pressed
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
            if (o == 8 || o == 9)
            {
                // getch()///;;;?????????///..;
                clear_seven_to_nineteen();
            }

            goto AGAIN;
        }
    }
}

// SAMPLE DATA
/*
1 One Onec 1 111
2 Two Twoc 2 22
3 Three Threec 3 33
4 Four Fourc 4 44
5 Five Fivec 5 55
 */