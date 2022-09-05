#include <conio.h>
#include <stdio.h>

int main(void)
{
     int selection, book_selection, quantity;
     char option = 'y', order = 'y', book_letter;
    int books_quantity[26] = { 0 };
    char books_letter[26] = {' '};
    printf("Something\n");
    printf(".........\n");
    while(1)
    {
        printf("Select an option (1 = View Menu, 2 = Sales Order, 3 = Exit): ");
        scanf("%d", &selection);

        if(selection == 3) break; // Exit the program

        printf("\n");
        //This is for field view
        switch(selection)
        {
            case 1:
                {
                     printf("Select a field to view:\n");
                     printf("1 = Software Development Programming\n");
                     printf("2 = Web Programming\n");
                     printf("3 = Mobile Programming\n");
                     printf("Input: ");
                     scanf("%d", &book_selection);
                     printf("\n");
                } break;
            case 2:
                {
                    int order_count = 1, i = 0;
                    printf("Sales order No. %d\n", order_count);
                    while(1)
                    {
                        printf("Book A, B, C, D, E, F, G, H, I(x = Exit)\t");
                        scanf(" %c", &book_letter);
                        // causes the while loop to exit, not the switch statement
                        if(book_letter == 'x')
                            break;
                      
                        books_letter[i] = book_letter;

                        printf("Quantity:\t");
                        scanf("%d", &quantity);
                      // This saves the quantity of books
                        books_quantity[i] += quantity;
                        i++; // watch out for this variable. Im planning it to assign 0 after the loop for the next order
                    }
                    printf("Confirm order? (Y = Yes, N = No)\t");
                    scanf(" %c", &order);
                    
                  // This only prints out the letter of books and  quantity.
                  // The program should prints out the letter, quantity, price of each book and the total price
                    for(int k = 0; k < i; k++)
                    {
                        printf("Book %c: %d\n", books_letter[k], books_quantity[k]);
                    }
                  
                  //if the user wants to order again, The order count should be incremented by 1.
                } break;
        }

        // For books
        switch(book_selection)
        {
            case 1: // software
                {
                    printf("Software Development Programming Books:\n");
                    printf("A = Beginning with programming Logic and Designs\n");
                    printf("B = C Programming\n");
                    printf("C = Programming Fundamentals\n");
                    printf("press any key to continue...");
                    getch();
                    book_selection = 0; // this field won't execute until it chosen
                } break;
        // case 2: for web
        // case 3: for mobile
        }
        printf("\n");
    }
    return 0;
}
