#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	l = 0;
	while (str[l])
		l++;
	return (l);
}

char	*ft_strdup(char *str)
{
	char	*duped;
	int i = 0;
	duped = malloc(sizeof(char *) * ft_strlen(str));
	while (str[i])
	{
		duped[i] = str[i];
		i++;
	}
	duped[i] = '\0';
	return (duped);
}

char *get_next_line(int fd)
{
	char	line[6500000] = {0};
	int		i = 0;
	while (read(fd, &line[i], 1) > 0)
	{
		if (line[i++] == '\n')
			break ;
	}
	if (line[0] != 0 && BUFFER_SIZE > 0)
		return (ft_strdup(line));
	return (NULL);
}
