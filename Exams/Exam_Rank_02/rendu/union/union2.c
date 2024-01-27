#include <unistd.h>

void	ft_putchar(char c){
	write(1, &c, 1);
}

void	proccess(unsigned char **str){
	int used[255];
	int	i = 0, j;
	while (i <= 255){
		used[i] = 0;
		i++;
	}
	i = 1;
	while (i < 3){
		j = 0;
		while (str[i][j]){
			if (!used[(unsigned char)str[i][j]]){
				used[(unsigned char)str[i][j]] = 1;
				ft_putchar((unsigned char)str[i][j]);
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av){
	if (ac == 3){
		proccess((unsigned char **)av);
	}
	ft_putchar('\n');
	return (0);
}