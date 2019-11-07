#include <stdio.h>
#include <locale.h>
#include "libftprintf.h"

int main()
{
	//char *o= "or: %lc %lli %s %u %l#x\n";
	//char *f = "ft: %lc %lli %s %u %l#x\n";
	//int n = 'a';
	setlocale(LC_NUMERIC, "");
	long long n = 1392923479;
	int a =    printf("OR %'+#50i\n", n);
	int b = ft_printf("FT %'+#50i\n", n);
	printf("|%i %i|", a, b);
}
