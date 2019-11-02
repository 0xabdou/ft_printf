#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char *o = "or: %llu\n";
	char *f = "ft: %llu\n";
	unsigned long long n = (unsigned long long)-12345612220;
	int a = printf(o, n);
	int b = ft_printf(f, n);
	printf("%i %i\n", a, b);
}
