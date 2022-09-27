#include <stdio.h>

int main(void)
{
	double amount, rate, n_years, si, ci = 1;
	
	printf("Enter amount: ");
	scanf("%lf", &amount);
	printf("Enter rate: ");
	scanf("%lf", &rate);
	printf("Enter number of years: ");
	scanf("%lf", &n_years);
	si = amount * (rate / 100.00) * n_years;
	
	printf("Simple interest: %.2f\n", si);
	printf("Total amount: %.2f\n", si + amount);
	
	for(int i = 1; i <= n_years; i++)
		ci *= (1 + (rate / 100) / 1);
		
		ci *= amount;
	printf("Compound interest: %.2lf\n", ci);
	return 0;
}
