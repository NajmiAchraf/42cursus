#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_list {
	char **av;
	int	   pipe_fd[2];
	int	   prev_pipe;
	int	   prev_type;
	int	   type;
} t_list;

int ft_strlen(char *s) {
	int len = 0;
	while (s && s[len])
		len++;
	return (len);
}

void error(char *func, char *msg, char *var) {
	write(2, "error: ", 8);
	if (func)
		write(2, func, ft_strlen(func));
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (var)
		write(2, var, ft_strlen(var));
	write(2, "\n", 1);
}

void fatal(char *func, char *msg, char *var) {
	error(func, msg, var);
	exit(1);
}

int init_list(t_list *list, char **av, int i) {
	int len, end = i;
	while (av[end] && strcmp(av[end], "|") != 0 && strcmp(av[end], ";") != 0)
		end++;
	len = end - i;
	if (len > 0) {
		list->av		= &av[i];
		list->prev_type = list->type;
		if (!av[end])
			list->type = 0;
		else if (strcmp(av[end], "|") == 0)
			list->type = 1;
		else
			list->type = 2;
		av[end]			= NULL;
		list->prev_pipe = list->pipe_fd[0];
	}
	return end;
}

void exe_shell(t_list *list, char **env) {
	pid_t pid;
	if ((list->type == 1 || list->prev_type == 1) && pipe(list->pipe_fd))
		fatal(NULL, "fatal", NULL);
	if ((pid = fork()) < 0)
		fatal(NULL, "fatal", NULL);
	if (pid == 0) {
		if (list->type == 1 && (dup2(list->pipe_fd[1], 1) < 0))
			fatal(NULL, "fatal", NULL);
		if (list->prev_type == 1 && (dup2(list->prev_pipe, 0) < 0))
			fatal(NULL, "fatal", NULL);
		if (execve(list->av[0], list->av, env) < 0)
			fatal(NULL, "cannot execute ", list->av[0]);
	} else {
		if (list->type == 1 || list->prev_type == 1) {
			close(list->pipe_fd[1]);
			if (list->type != 1)
				close(list->pipe_fd[0]);
		}
		if (list->prev_type == 1)
			close(list->prev_pipe);
		waitpid(pid, NULL, 0);
	}
}

int main(int ac, char *av[], char **env) {
	t_list list;
	int	   start, i = 0;
	while (i < ac && av[++i]) {
		start = i;
		i	  = init_list(&list, av, i);
		if (strcmp(av[start], "cd") == 0) {
			if (i - start != 2)
				error("cd: ", "bad arguments", NULL);
			else if (chdir(list.av[1]) < 0)
				error("cd: ", "cannot change directory to ", list.av[1]);
		} else if (i > start)
			exe_shell(&list, env);
	}
	return (0);
}
