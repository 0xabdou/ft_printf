#include <stdio.h>
#include "libftprintf.h"

int main()
{
	//char *o= "or: %lc %lli %s %u %l#x\n";
	//char *f = "ft: %lc %lli %s %u %l#x\n";
	//int n = 'a';
	int a = printf("OR %i OR %x OR %.ls OR %p\n", 1, -1, 0, &a);
	int b = ft_printf("FT %i FT %x FT %.ls FT %p\n", 1, -1, 0, &a);
	printf("|%i %i|", a, b);
}
