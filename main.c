#include <stdio.h>
#include "libftprintf.h"

int main()
{
	char *o = "or:%lc\n";
	char *f = "ft:%lc\n";
	int n = 256;
	int a = printf(o,n);
	int b = ft_printf(f,n);
	printf("%i %i\n", a, b);
}
