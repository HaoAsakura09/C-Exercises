#include <ctype.h>
#include <conio.h>
#include <stdio.h>

void header_message();
void ty_message();
void array_clear(char books_letter[], int book_quantity[], float books_price[]);

int main(void)
{
	// This will cause the whole program to exit if becomes 3, for exit
	int selection = 0;
	// for view menu option
	int view_field = 0;
	// A letter for book from A - I
	char books_letter[7] = { ' ' };
	char confirm_order = 'N', next_order = 'N', book_letter;
	// number of order of books
	int book_quantity[7] = { 0 }, quantity = 0;
	
	// number of user's' order
	int order_count = 1;
	
	//price of book from A - I
	float books_price[7] = { 5, 10, 20, 30, 40, 50, 60 };
	header_message();
	
	while(selection != 3)
	{
		printf("\nSelect an option(1 = View Menu, 2 = Sales order, 3 = Exit): ");
		scanf("%d", &selection);
		
		if(selection == 1)
		{
			printf("Select a field to view:\n");
			printf("1 - Software Development Programming\n");
			printf("2 - Web Programming\n");
			printf("3 - Mobile Programming\n");
			printf("Input: ");
			scanf("%d", &view_field);
			printf("\n");
		}
		else if(selection == 2)
		{
			int num_book = 0;
			while(next_order != 'n')
			{
				printf("Sales order No. %d\n", order_count);
				while(1)
				{
					printf("Book A, B, C, D, E, F, G, H, I (x = EXIT): ");
					scanf(" %c", &book_letter);
					
					if(book_letter == 'x') break;
					
					books_letter[num_book] = book_letter;
					
					printf("Quantity: ");
					scanf("%d", &quantity);
					book_quantity[num_book] = quantity;
					
					num_book++;
				}
				
				printf("Confirm the order? (Y = Yes, N = No) ");
				scanf(" %c", &confirm_order);
				printf("\n");
				
				//Change the discount to your prefer discount price
				float total = 0, discount = 2, sub_pay = 0, total_pay;
				
				if(confirm_order == 'y')
				{
					for(int i = 0; i < num_book; i++)
					{
						total = book_quantity[i] * books_price[i];
						printf("Book %c: %d, book price $%.2f. total = $%.2f\n", books_letter[i], book_quantity[i], books_price[i], total);
						
						sub_pay += total;
				      total = 0; //reset total for next book
					}
					
					discount = sub_pay * (discount / 100.0f);
					total_pay = sub_pay - discount;
					
					printf("Sub total = %.2f\n", sub_pay);
					printf("Discounts = %3.1f\n", discount);
					printf("Total pay = %.2f\n", total_pay);
					//Clear all previously stored values in all array and variables for next order, except discount
					array_clear(books_letter,book_quantity, books_price);
					total = sub_pay = total_pay = 0.0f;
					ty_message();
				}
				
				printf("\nNext order? (Y = Yes, N = No) ");
				scanf(" %c", &next_order);
				printf("\n");
				if(next_order == 'y')
				{
					order_count++;
					num_book = 0; // reset for next order
					continue;
				}
				
			}
		}
		
		switch(view_field)
		{
			case 1: 
							{
								printf("Software Development Programming:\n");
								printf("A - Beginning with Programming Logic and Designs\n");
								printf("B - C Programming\n");
								printf("C - Programming Fundamentals\n");
								printf("Press any key to continue...");
								while(getch() == '\n')
									;
								
								view_field = 0;
								printf("\n");
							} break;
			case 2: printf("Web Programming is empty\n"); break;
			case 3: printf("Mobile programming is empty\n"); break;
		}
	}
	return 0;
}

void header_message()
{
	printf("\n=====Change this title==========\n");
	printf("=========change this sub.=========\n");
}

void ty_message()
{
	printf("\nTHANK YOU, HAVE A NICE DAY!!\n");
}

void array_clear(char books_letter[], int book_quantity[], float books_price[])
{
	for(int i = 0; i < 7; i++)
	{
		books_letter[i] = ' ';
		book_quantity[i] = 0;
		books_price[i] = 0.0f;
	}
}
