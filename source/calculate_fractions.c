#include <stdio.h>

struct fraction
{
	int numerator;
	int denominator;
};

struct fraction reduce_fractions(struct fraction f)
{
	int remainder;
	int n = f.numerator, d = f.denominator;
	
	while(n != 0)
	{
		remainder = n % d;
		n = d;
		d = remainder;
	}
	
	f.numerator /= d;
	f.denominator /=d;
	return f;
};

struct fraction read_fraction(void)
{
	struct fraction f;
	scanf("%d/%d", &f.numerator, &f.denominator);
	
	return f;
};

struct fraction add_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction add;
	add.numerator = f1.numerator * f2.denominator +
									       f2.numerator * f1.denominator;
	add.denominator = f1.denominator * f2.denominator;
	
	return add;
};

struct fraction subtract_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction subtract;
	subtract.numerator = f1.numerator * f2.denominator -
													 f2.numerator * f1.denominator;
   subtract.denominator = f1.denominator * f2.denominator;	return subtract;										 
};

struct fraction multiply_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction multiply;
	multiply.numerator = f1.numerator * f2.numerator;
	multiply.denominator = f1.denominator * f2.denominator;
	return multiply;
}; 

struct fraction divide_fractions(struct fraction f1, struct fraction f2)
{
	struct fraction divide;
	divide.numerator = f1.numerator * f2.denominator;
	divide.denominator = f2.numerator * f1.denominator;
	return divide;
};

void print_result(struct fraction f1, char operator, struct fraction f2, struct fraction result);

int main(void)
{
	struct fraction f1, f2, reduce_f1, reduce_f2, add, subtract, multiply, divide;
	
	printf("Enter numerator and denominator for fraction 1: ");   f1 = read_fraction();
	printf("Enter numerator and denominator for fraction 2: ");   f2 = read_fraction();
	
	printf("Fraction 1: %d/%d\n", f1.numerator, f1.denominator);
	printf("Fraction 2: %d/%d\n", f2.numerator, f2.denominator);
	
	reduce_f1 = reduce_fractions(f1);
	printf("\nFraction 1 in lowest terms: %d/%d\n", reduce_f1.numerator, reduce_f1.denominator);
	reduce_f2 = reduce_fractions(f2);
	printf("Fraction 2 in lowest terms: %d/%d\n", reduce_f2.numerator, reduce_f2.denominator);
	
	printf("\n\n");
	add =  reduce_fractions(add_fractions(f1, f2));
	print_result(f1, '+', f2, add);
	
	subtract = reduce_fractions(subtract_fractions(f1, f2));
	print_result(f1, '-', f2, subtract);
	
	multiply = reduce_fractions(multiply_fractions(f1,f2));
	print_result(f1, '*', f2, subtract);
	
	divide = reduce_fractions(divide_fractions(f1, f2));
	print_result(f1, '/', f2, divide);
	return 0;
}

void print_result(struct fraction f1, char operator, struct fraction f2, struct fraction result)
{
	printf("%d/%d %c %d/%d = %d/%d\n", f1.numerator, f1.denominator, operator, f2.numerator, f2.denominator, result.numerator, result.denominator);
}
