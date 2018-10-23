/// The maximum number of digits allowed in a big int.
#define MAX_DIGITS 80
#include <stdio.h>
#include <string.h>

struct BigInt {
	/** number of digits of the big int. */
	int digits_count;

	/** array of digits of big int. */
	unsigned int the_int[MAX_DIGITS];
};
int strtobig_int(const char *str, int len, struct BigInt *big_int);
void print_big_int(const struct BigInt *big_int);
void multiply(const struct BigInt *big_int, int factor, struct BigInt *big_result);
void divide(const struct BigInt *big_int, int divisor, struct BigInt *big_result);
void copy_big_int(const struct BigInt *from, struct BigInt *to);
void read_char_array(char* x);
