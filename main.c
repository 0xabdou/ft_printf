#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char *o = "or: %-+05.5lli\n";
	char *f = "ft: %-+05.5lli\n";
	long long n = -12345612220;
	int a = printf(o, n);
	int b = ft_printf(f, n);
	printf("%i %i\n", a, b);
}
