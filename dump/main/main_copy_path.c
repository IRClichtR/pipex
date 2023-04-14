
#include <stdio.h>

int	main(int ac, char **av, char **envp)
{
	(void) ac;
	(void) av;
	int	i = 0;
	while (envp[i] != 0)
	{
		printf("%s\n", envp[i]);
		i++;
	}
	return (0);
}
