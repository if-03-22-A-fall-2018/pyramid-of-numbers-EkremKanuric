/*----------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class>
 * ---------------------------------------------------------
 * Exercise Number: 0
 * Title:			Pyramid of Numbers
 * Author:			Ekrem Kanuric
 * ----------------------------------------------------------
 * Description:
 * Calculates a pyramid of numbers, i.e., it multiplies a big
 * integer by the number 2, its result by 3, etc. and then
 * returns to the original value by subsequently dividing,
 * again starting by 2, 3, etc.
 * ----------------------------------------------------------
 */
#include <stdio.h>
#include <string.h>

/// The maximum number of digits allowed in a big int.
#define MAX_DIGITS 80

/** BigInt represents an integer number which can have MAX_DIGITS digits
*** @see MAX_DIGITS
*/
struct BigInt {
	/** number of digits of the big int. */
	int digits_count;

	/** array of digits of big int. */
	unsigned int the_int[MAX_DIGITS];
};

/** strtobig_int converts a string into a BigInt. If strtobig_int runs
*** against a character not between '0' and '9' the conversion stops
*** at this point.
*** @param *str The string to be converted.
*** @param len Number of characters in string to be converted.
*** @param *big_int The converted string now as BigInt.
* @return The number of characters converted.
*/
int strtobig_int(const char *str, int len, struct BigInt *big_int)
{
	int next_digit = len - 1;
	for (int i = 0; i < len; i++)
	{
		if (i >= MAX_DIGITS + 1)
		{
			printf("This digit is too big ! \n");
			return big_int->digits_count;
		}

		if (str[i] < '0' || str[i] > '9')
		{
			return i;
		}

		big_int->the_int[next_digit] = str[i] - '0';
		next_digit--;
	}
	big_int->digits_count = len;
	return big_int->digits_count;
}

/** print_big_int() prints a BigInt.
*** @param *big_int The BigInt to be printed.
*/
void print_big_int(const struct BigInt *big_int)
{
	for (int i = big_int->digits_count - 1; i >= 0; i--)
	{
		printf("%d", big_int->the_int[i]);
	}
}

/** multiply() multiplies a BigInt by an int.
*** @param big_int The BigInt to be multiplied.
*** @param factor The int value which is multiplied by BigInt.
*** @param *big_result The result of the multiplication.
*/
/** copy_big_int() copies a BigInt to another BigInt.
*** @param from The source where we want to copy from.
*** @param *to The target where we want to copy to.
*/
void copy_big_int(const struct BigInt* from, struct BigInt *to)
{
		 to->digits_count = from->digits_count;
		for (int i = 0; i < from->digits_count; i++)
		{
			to->the_int[i] = from->the_int[i];
		}
}
void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result)
{
		big_result->digits_count = big_int->digits_count;
		int number = 1;
		int carry = 0;
		for (int i = 0; i < big_result->digits_count; i++)
	 	{

			number = big_int->the_int[i] * factor + carry;
			carry = number / 10;
			big_result->the_int[i] = number % 10 ;
		}
		if (carry > 0)
		 {
			 big_result->digits_count++;
			 big_result->the_int[big_result->digits_count - 1] = carry;
		}
		copy_big_int(&big_result, &big_int);
	}





/** divide() multiplies a BigInt by an int.
*** @param big_int The BigInt to be divided.
*** @param divisor The int value by which we want to divide big_int.
*** @param *big_result The result of the division.
*/
void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result)
{
	int quotient= 0;
	int rest = 0;
	int digits_sum= 0;
	int count_of_zero = 0;
	for (int i = big_int->digits_count-1; i >=0; i--)
	{
		quotient = big_int->the_int[i] + (rest*10);
		big_result->the_int[i] = quotient/divisor;
		rest= quotient %divisor;
		digits_sum += big_result->the_int[i];

		if (big_result->the_int[i] == 0 && digits_sum == 0)
		{
			count_of_zero++;
		}
	}
	big_result->digits_count -= count_of_zero;
}


/**
*** main() reads the base number from which the pyramid has to be calculated
*** into an array of char. The max. length of this number is MAX_DIGITS.
*** The number is checked to contain only digits. If not the program exits.
*** Then the inputted number is converted into a big int by calling the
*** function strtobig_int().
*** After the conversion the tower is calculated by calling the functions
*** multiply(), print_big_int(), and copy_big_int() consecutively from 2 to
*** 9 and then again with divide() instead of multiply() from 2 to 9.
***
*/
int main(int argc, char *argv[])
{
  struct BigInt numberCapsule;
	struct BigInt big_result;
	char input[MAX_DIGITS + 1];
	printf("Type in a number: ");
	scanf("%s",input);
	int length = strlen(input);
	int len_converted = strtobig_int(input, length, &numberCapsule);
	big_result.digits_count = len_converted;
	for (int i = 2; i <= 9; i++)
	{
		print_big_int(&numberCapsule);
		printf(" * %d = ",i );
		multiply(&numberCapsule, i, &big_result);
		print_big_int(&big_result);
		printf("\n");
		copy_big_int(&big_result, &numberCapsule);
	}
	for (int i = 2; i <= 9; i++)
	{
		print_big_int(&numberCapsule);
		printf(" / %d =",i );
		divide(&numberCapsule, i , &big_result);
		print_big_int(&big_result);
		printf("\n" );
		copy_big_int(&big_result, &numberCapsule);
	}
	return 0;
}
