#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	nbrlenght(int nbr){
	long n = nbr;
	int l = 1;
	if (n < 0){
		n = -n;
		l++;
	}
	while(n > 9){
		n /= 10;
		l++;
	}
	return (l);
}

int	hexlenght(unsigned int nbr){
	int l = 1;
	while(nbr > 15){
		nbr /= 16;
		l++;
	}
	return (l);
}

int ft_putchar(char c)
{
    return (write(1, &c, 1));
}

int	ft_putstr(char *str){
	int i = 0;
	if (!str) 
		return (ft_putstr("(null)"));
	while (str[i] != '\0'){
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_putnbr(int nbr){
	long n = nbr;
	if (n < 0){
		ft_putchar('-');
		n = -n;
	}
	if (n > 9){
		ft_putnbr(n / 10);
		n %= 10;
	}
	ft_putchar(n + '0');
	return (nbrlenght(nbr));
}

int ft_puthex(unsigned int hex){
	char *base;
	base = "0123456789abcdef";
	if (hex > 15)
		ft_puthex(hex / 16);
	ft_putchar(base[hex % 16]);
	return (hexlenght(hex));
}


int	proccess(char c, char *str){
	int j = 0;
	if (c == 's')
		j = ft_putstr(str);
	if (c == 'd')
		j = ft_putnbr((int)str);
	if (c == 'x')
		j = ft_puthex((unsigned int)str);
	return (j); 
}

int ft_printf(const char *var, ...){
	va_list	av;
	int	i = 0, j = 0;
	va_start(av, var);
	while (var[i]){
		if (var[i] == '%'){
			j += proccess(var[i + 1], va_arg(av, char *)) - 2;
			i++;
		}
		else
			ft_putchar(var[i]);
		i++;
	}
	va_end(av);
	return (i + j);
}