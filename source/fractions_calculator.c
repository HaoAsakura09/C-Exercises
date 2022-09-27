#include <stdio.h>

struct fraction
{
	int numerator;
	int denominator;
};

struct fraction reduce_fractions(struct fraction f)
{
	int n = f.numerator, d = f.denominator, remainder;
	
	while(n % d != 0)
	{
		remainder = n % d;
		n = d;
		d = remainder;
	}
	
	f.numerator /= d;
	f.denominator /= d;
	
	return f;
}

struct fraction read_fractions(void)
{
	struct fraction f;
	scanf("%d/%d", &f.numerator, &f.denominator);
	return f;
}

struct fraction add_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction add;
	add.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	add.denominator = f1.denominator * f2.denominator;
	return add;
}

struct fraction subtract_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction subtract;
	subtract.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	subtract.denominator = f1.denominator * f2.denominator;
	return subtract;
}

struct fraction multiply_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction multiply;
	multiply.numerator = f1.numerator * f2.numerator;
	multiply.denominator = f1.denominator * f2.denominator;
	return multiply;
}

struct fraction divide_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction divide;
	divide.numerator = f1.numerator * f2.denominator;
	divide.denominator = f2.numerator * f2.denominator;
	return divide;
}

void print_lowest_term(struct fraction f);
void print_fractions
(struct fraction a, char operator, struct fraction b, struct fraction r);

int main(void)
{
	struct fraction f1, f2,  r_fractions, add, subtract, multiply, divide;
	
	printf("Enter fraction 1: ");
	f1 = read_fractions();
	printf("Enter fraction 2: ");
	f2 = read_fractions();
	
	printf("\nFraction 1 in lowest term: ");
   r_fractions = reduce_fractions(f1);
   print_lowest_term(r_fractions);
   printf("\nFraction 2 in lowest term: ");
   r_fractions = reduce_fractions(f2);
   print_lowest_term(r_fractions);
   printf("\n");
   
   printf("Adding fractions:\n");
   add = add_fractions(f1, f2);
   print_fractions(f1, '+', f2, add);
   printf("Result in lowest term: %d/%d", reduce_fractions(add).numerator, reduce_fractions(add).denominator);
   printf("\n");
   
   printf("\nSubtracting fractions:\n");
   subtract = subtract_fractions(f1, f2);
   print_fractions(f1, '-', f2, subtract);
   printf("Result in lowest term: %d/%d", reduce_fractions(subtract).numerator, reduce_fractions(subtract).denominator);
   
   printf("\nMultiplying fractions:\n");
   multiply = multiply_fractions(f1, f2);
   print_fractions(f1, '*', f2, multiply);
   printf("Result in lowest term: %d/%d\n", reduce_fractions(multiply).numerator, reduce_fractions(multiply).denominator);
   
   printf("\nDividing fractions:\n");
   divide= divide_fractions(f1, f2);
   print_fractions(f1, '/', f2, divide);
   printf("Result in lowest term: %d/%d\n", reduce_fractions(divide).numerator, reduce_fractions(divide).denominator);
   
	return 0;
}

void print_lowest_term(struct fraction f)
{
	printf("%d/%d\n", f.numerator, f.denominator);
}

void print_fractions
(struct fraction a, char operator, struct fraction b, struct fraction r)
{
	printf("%d/%d %c %d/%d = %d/%d\n", a.numerator, a.denominator, operator, b.numerator, b.denominator, r.numerator, r.denominator);
}
