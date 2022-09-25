void customer_bill(int *a, int *b, int *c, int *d, int *e);
void calculate_bill();
void clear_seven_to_nineteen();
void separator_line(); // prints line between shopkeepers bill and cusotmer bill
void display_bill();

void calculate_bill()
{

    // fseek(fp1,0, SEEK_SET); // THIS WILL TAKE THE CURSOR THE BEGINNING OF THE FILE

    char check1;
    gotopositionxy(33, 33);
    printf("Calculate Bill (Y/N)\t : ");
    check1 = getche();
    if (!(check1 == 'y' || check1 == 'Y'))
    {
        display_menu();
    }
    // else
    // {
    //     do nothing
    // }

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

    int ntg = 1;
    if (ntg == 1) // It will run for sure// we don't want to create a new function and pass value so
    {             // will be easy to minimize this portion so putting in if and make it always run

        system("cls");
        //  ↓↓↓↓↓↓↓↓\t\t↓↓↓↓ TEMPLATE OF BILL ↓↓↓↓↓↓↓↓↓↓↓↓
        printf("\t\t\t\t ************************************ \n");
        printf("\t\t\t\t ****** * Mr.Navy Cyber Cafe * ******");
        printf("\t\t\n\n");
        printf("\t\t\t\t\tInventory Management");
        // textcolor(1);
        gotopositionxy(37, 25);
        printf("             SHOPKEEPER'S BILL\n");
        // textcolor(8);
        gotopositionxy(15, 26);
        printf("----------------------------------------------------------------------------------------");
        gotopositionxy(18, 27);
        printf("S.N.\tCode\tName\t\tQt.Left\t     Company\t\tQty.\tRate\tTotal\n");
        gotopositionxy(15, 28);
        printf("----------------------------------------------------------------------------------------");
        separator_line();

        // ↑↑↑↑↑↑↑↑↑↑↑↑↑↑ TEMPLATE OF BILL ↑↑↑↑↑↑↑↑↑↑↑↑↑↑
    }

    // checking if the code is repeated or not
    int sn = 0;

    // THIS WILL TAKE THE FILE NAME FOR THE CUSTOMER'S BILL//// to store print the customer file to txt file      ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    int qt = 0; // quantity
    char fname[128];
    gotopositionxy(2, 5);
    printf("Enter .txt file name to store the customer bill  : ");
    scanf("%123s", fname); // for buffer of 124 bytes
    printf("\n\nPress any key to continue");
    getch();
    gotopositionxy(2, 5);
    printf("                                                                        "); // will clear the screen
    strcat(fname, ".txt");                                                              // this will add the .txt and file name together
    FILE *inputf;
    inputf = fopen(fname, "a+");

    time_t t;
    time(&t);
    fprintf(inputf, "	  NAVY CYBER STORE          \n");
    fprintf(inputf, "	      L.A., USA               \n");
    fprintf(inputf, "             Date: 11/07/2022        \n"); // fprintf("\t\t\t\t\t%s", ctime(&t)); // Print Time
    fprintf(inputf, "\n");
    fprintf(inputf, "---------------------------------------\n");
    fprintf(inputf, "Particulars     Rate    Qty.    Amount\n");

    fprintf(inputf, "---------------------------------------\n");

    // THIS WILL PRINT ON THE OUTPUT SCREEN
    gotopositionxy(118, 22);
    printf(" customer bill is printed on  ");
    gotopositionxy(120, 23);
    printf("\"%s\" file", fname);

    gotopositionxy(112, 25);
    printf("             CUSTOMER'S BILL\n");
    gotopositionxy(115, 26);
    printf("	  NAVY CYBER STORE           \n");
    gotopositionxy(118, 27);
    printf("	      L.A., USA               \n");
    gotopositionxy(120, 28);
    printf("                     - 12 June        \n"); // fprintf("\t\t\t\t\t%s", ctime(&t)); // Print Time
    gotopositionxy(110, 29);
    printf("------------------------------------------\n");
    printf("\n");
    gotopositionxy(112, 30);
    printf("Particulars	Rate	Qty.	Amount\n");
    gotopositionxy(110, 31);
    printf("------------------------------------------\n");

    // THIS WILL PRINT ON THE OUTPUT SCREEN

    fclose(inputf);

ADD_PRODUCT_AGAIN:
    int found = 0;
    clear_seven_to_nineteen();
    separator_line();

    FILE *fp1;
    FILE *fp2;

    fp1 = fopen("ProductDetails.dat", "r+");
    fp2 = fopen("Bill.dat", "a");

    // CHECKS IF THE FILE IS EMPTY OR NOT  ↓↓↓↓↓
    if (fp1 == NULL) // r+ does both read and write
    {
        printf(" \n\n\t\t RECORD FILE IS EMPTY \n");
        printf("\n\t\t Enter any key to go back to main menu\n");
        getch();
        display_menu();
    }
    // CHECKS IF THE FILE IS EMPTY OR NOT  ↑↑↑↑↑
    int code;

AGAIN: // this is used when the user inputs the code that is not in the database.      ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    found = 0;

    clear_seven_to_nineteen();
    separator_line();

    gotopositionxy(2, 5);
    printf("\n\nCode of Product  :                                                                                                                      "); // this space will clear the line when you add the next product next time
    gotopositionxy(19, 7);
    scanf("%d", &code);

    // CHECKS IF THE CODE IS PRESENT OR NOT and prints found if present   ↓↓↓↓↓ else asks to add the code again
    fseek(fp1, 0, SEEK_SET);

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
                goto no_stocks_left_goto_function;
            }

            // IF THE STOCKS IS ZERO, IT DISPLAY NO STOCKS LEFT ADD CHOOSE ANOTHER PRODUCT

            // dont multiply here TO GET GRAND TOTAL and total some error will occur that will print the address of the temp_total _price instead of the value // temp_total_price = temp_price * qt ;
        }
    }
    fseek(fp1, 0, SEEK_SET);

    // IF THE CODE IS NOT PRESENT ASKING AGAIN TO INPUT THE CODE:    ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓

    if (found == 0)
    {
      INVALID_INPUT_ENTER_CODE_AGAIN:

        gotopositionxy(0, 7);
        {
            char checkkk;
            printf("SUPPLIED  CODE IS NOT IN THE DATABASE.. Enter code again:");

            printf("\n\n PRESS \"A\" TO ENTER THE RIGHT CODE AGAIN");
            printf("\n\n\t\t\t OR \n\n");
            printf("\n\n PRESS \"M\" TO GET BACK TO MENU");

            gotopositionxy(25, 17);

            checkkk = getche();

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
                printf("\n\n INVALID INPUT !!  \n'n ENTER YOUR CHOICE AGAIN");

                goto INVALID_INPUT_ENTER_CODE_AGAIN; // goto function
            }
        }
    }

    // IF THE CODE IS NOT PRESENT ASKING AGAIN TO INPUT THE CODE:↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

ENTER_STOCKS_AGAIN:

    gotopositionxy(2, 7);
    printf("\n\nQty. for Billing :                          ");
    gotopositionxy(19, 9);
    scanf("%i", &qt);
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

    if ((checkk1 == 'y' || checkk1 == 'Y'))
    {
        printf(""); // will do nothing
    }
    else
    {
        printf("\n\nYou pressed N, The item is discarded, add another product again \n\n Press enter");

        fflush(stdin);
        getch();
        goto AGAIN;
    }
    // ASKING FOR THE USER TO CONFIRM TO ADD THE PRODUCT OR NOT

    // DECREASE THE QUANTITY ENTERED//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    fseek(fp1, 0, SEEK_SET);

    if (found == 1)
    {
        while (fscanf(fp1, "%i %s %s %i %i", &pdt.product_code, pdt.product_name, pdt.product_company, &pdt.product_price, &pdt.product_quantity) != EOF)
        {
            if (code == pdt.product_code)
            {
                pdt.product_quantity = pdt.product_quantity - qt;
                // we cannot store the
            }
            fprintf(fp2, "%i %s %s %i %i\n", pdt.product_code, pdt.product_name, pdt.product_company, pdt.product_price, pdt.product_quantity);
        }
    }
    fseek(fp1, 0, SEEK_SET);
    // DECREASE THE QUANTITY ENTERED//↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑

    fclose(fp1);
    fclose(fp2);

    // printf("Removing ProductDetails.dat, press any key\n");
    // getch();
    remove("ProductDetails.dat");

    // printf("Renaming bill.dat, press any key\n");
    // getch();
    // rename("Bill.dat", "ProductDetails.dat");

    sn = sn + 1; // AFTER ONE PRODUCT IS ADDED , THE SN WIL INCREASE BY 1.

    // temp_total_price = temp_price * qt ; // multiply rate * quantity
    temp_total_price = multiplyAB(qt, pdt.product_price);     // this user-defined function will do the job
    Grand_Total_Price = Grand_Total_Price + temp_total_price; // this will keep adding the value in the variable

    // reducing the

    // PRINTING THE VALUE TO THE SCREEN;
    gotopositionxy(18, 28 + sn); // the sn will change the each times the value will print.
    // this will do a bit error when printing next time    // printf("%i.\t %i\t%s\t\t  %i\t\t%s\t%i\t%i\t%i",sn,temp_code,temp_name,temp_total_quantity,temp_company_name,qt,temp_price, temp_total_price);
    // Specifying address where to print the value
    gotopositionxy(19, 28 + sn);
    printf("%d.", sn);
    gotopositionxy(25, 28 + sn);
    printf("%d", temp_code);

    // this will print the first 7 characters of the temp_name
    gotopositionxy(32, 28 + sn);
    for (int i = 0; i < 7; i++)
    {
        printf("%c", temp_name[i]);
    }
    printf("."); // will print dot after

    gotopositionxy(50, 28 + sn);
    printf("%d", temp_total_quantity);

    gotopositionxy(61, 28 + sn);
    printf("%s", temp_company_name);
    gotopositionxy(81, 28 + sn);
    printf("%d", qt);
    gotopositionxy(88, 28 + sn);
    printf("%d", temp_price);
    gotopositionxy(97, 28 + sn);
    printf("%d", temp_total_price);

    // ADDING THE BILL DETAILS TO THE CUSTOMER BILL
    inputf = fopen(fname, "a+");
    fseek(inputf, 0, SEEK_END);
    fprintf(inputf, "%s\t\t\t%d\t\t%d\t\t%d\n", temp_name, temp_price, qt, temp_total_price);

    // THIS WILL PRINT THE BILL ON THE SCREEN
    gotopositionxy(112, (31 + sn));
    for (int i = 0; i < 7; i++)
    {
        printf("%c", temp_name[i]);
    }
    printf("."); // will print dot after name
    printf("\t\t%d\t%d\t%d\n", temp_price, qt, temp_total_price);

    fclose(inputf);
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

    gotopositionxy(15, 28 + sn + 1); // will print after all the products are shown on the bill
    printf("----------------------------------------------------------------------------------------");

    gotopositionxy(81, 28 + sn + 2); // will print after all the products are shown on the bill
    printf("======================");

    gotopositionxy(83, 28 + sn + 3);
    printf("Grand Total:   %d", Grand_Total_Price);

    gotopositionxy(81, 28 + sn + 4);
    printf("======================");

    // printing the grand total price for shopkeepers bill

    // printing the grand total price for customer's bill on OUTPUT SCREEN

    gotopositionxy(132, 31 + sn + 1);
    printf("=====================");
    gotopositionxy(133, 31 + sn + 2);
    printf("Grand Total : %d", Grand_Total_Price);
    gotopositionxy(132, 31 + sn + 3);
    printf("=====================");
    // printing the grand total price for customer's bill on OUTPUT SCREEN

    // printing the grand total price in the file at last
    inputf = fopen(fname, "a+");
    fseek(inputf, 0, SEEK_END);
    fprintf(inputf, "                   =====================\n");
    fprintf(inputf, "                    Grand Total : %d\n", Grand_Total_Price);
    fprintf(inputf, "                   =====================\n");
    fprintf(inputf, "\n\t\tThan You, Visit again.");
    fclose(inputf);

    // printing the grand total price in the file at last

    printf("\nPress any key to go back to main menu");
    getch();
    display_menu();
}

void clear_seven_to_nineteen()
{
    // will clear the line by printing empty spaces:      ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
    gotopositionxy(0, 7);
    printf("                                                                                                         ");
    gotopositionxy(0, 8);
    printf("                                                                                                        ");
    gotopositionxy(0, 9);
    printf("                                                                                                       ");
    gotopositionxy(0, 10);
    printf("                                                                                                        ");
    gotopositionxy(0, 11);
    printf("                                                                                                        ");
    gotopositionxy(0, 12);
    printf("                                                                                                       ");
    gotopositionxy(0, 13);
    printf("                                                                                                       ");
    gotopositionxy(0, 14);
    printf("                                                                                                        ");
    gotopositionxy(0, 15);
    printf("                                                                                                        ");
    gotopositionxy(0, 16);
    printf("                                                                                                        ");
    gotopositionxy(0, 17);
    printf("                                                                                                        ");
    gotopositionxy(0, 18);
    printf("                                                                                                         ");
    gotopositionxy(0, 19);
    printf("                                                                                                         ");
    gotopositionxy(0, 20);
    printf("                                                                                                        ");
    gotopositionxy(0, 21);
    printf("                                                                                                           ");
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
