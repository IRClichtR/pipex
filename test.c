/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:56:25 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/05 15:40:36 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	(void) ac;
	(void) av;
	int	i = 0;
	printf("coucou\n");
	while (envp[i] != 0)
	{
		printf("ENVP[%i] == %s\n", i, envp[i]);
		i++;
	}
	return (0);
}

/*
//USE CHILD TO EXECUTE a command and free the memory in the parent process 
int	main(int ac, char **av, char **envp)
{
	(void) ac;
	char **argument;
	int	outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("Impossible d'ouvrir le fichier de sortie\n");
		return (1);
	}
	argument = ft_calloc(ac + 1, sizeof(char *));
	char *av0copy = ft_strdup(av[0]);
	argument[0] = ft_strjoin(av0copy, "push_swap");
	int i = 1;
	while (av[i] != NULL)
	{
		argument[i] = ft_strdup(av[i]);
		i++;
	}
	argument[i] = NULL;
	int pid = fork();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		execve("/mnt/nfs/homes/ftuernal/TroncCommun/deuxieme_cercle/push_swap/push_swap_VtoPush/push_swap/push_swap", argument, envp);
	}
	else
	{
		wait(NULL);
		int j = ac;
		while (j >= 0)
		{
			free(argument[j]);
			argument[j] = NULL;
			j--;
		}
		free(argument);
		free(av0copy);
		argument = NULL;
	}
	close(outfile);
	return (0);
}
*/
//USE CHILD ? PARENT RELATION TO MAKE SURE EVERYTHING IS EXECUTED
/*int main()
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
		execlp("ping", "ping", "-c", "3", "google.com", NULL);
	else
	{
		wait(NULL);
		printf("i'm OK!\n");
	}
	return (0);
}
*/
/*
//EXECUTE ANOTHER PROGRAM IN MY C PROGRAM
//attention execve kill le programme. Il faut free avant de sortir. utiliser exec dans un child et free dans le parent
int	main(int ac, char **av, char **envp)
{
	(void) ac;
	char **argument;
	int	outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror("Impossible d'ouvrir le fichier de sortie\n");
		return (1);
	}
	argument = ft_calloc(ac + 1, sizeof(char *));
	char *av0copy = ft_strdup(av[0]);
	printf("LEN DE av[0] == %ld\n", ft_strlen(av[0]));
	argument[0] = ft_strjoin(av0copy, "push_swap");
	int i = 1;
	while (av[i] != NULL)
	{
		argument[i] = ft_strdup(av[i]);
		i++;
	}
	argument[i] = NULL;
	dup2(outfile, STDOUT_FILENO);
	execve("/mnt/nfs/homes/ftuernal/TroncCommun/deuxieme_cercle/push_swap/push_swap_VtoPush/push_swap/push_swap", argument, envp);
printf("coucou\n");
	int j = ac;
	while (j >= 0)
	{
		free(argument[j]);
		argument[j] = NULL;
		j--;
	}
	free(argument);
	free(av0copy);
	argument = NULL;
	return (0);
}
*/
// MULTIPLE fork management
/*
int main()
{
	int	id1 = fork();
	int	id2 = fork();
	if (id1 == 0)
	{
		pid_t pid = getpid();
		printf("My PID is == %d\n", pid);
		if (id2 == 0)
	
			printf("id1 == 0 && id2 == 0 my pid is == %d\n", getpid());
		else
			printf("id1 == 0 && id2 != 0 my pid is == %d\n", getpid());
	}
	else
	{
		if (id2 == 0)
			printf("id1 != 0 && id2 == 0 my pid is == %d\n", getpid());
		else
			printf("id1 != 0 && id2 != 0 my pid is == %d\n", getpid());
	}
	//while (wait(NULL) != -1 || errno != ECHILD)
	//	;
}
*/

/*int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	return (0);
}*/



/*
attention il faut attendre que le process child soit ermine pour aller dans le process parent. le child doit toujours s'executer et se fermer avant le parent 
wait(NULL) a la fin du process enfant pour eviter la creation d'un processus parent zombie (dont la memoire ne pourra pas etre free)

int wait_status = wait(NULL);
if (wait_status == -1)
	return (message d'erreur il n'y a pas de child a attendre)
//EXAMPLE FUNCTION WAIT()

int main()
{
	int id = fork();
	int n;
	if (id == 0)
		n = 1;
	else
		n = 6;
	if (id != 0)
	{
		int status;
		wait(&status);
	}
	int i;
	for (i = n; i < n + 5; i++)
	{
		printf("%d \n", i);
		fflush(stdout);
	} 
	return (0);
}

// EXAMPLE OF THE USE OF THE FUNCTION FORK()
int main(int ac, char **av)
{
	(void) ac;
	(void) av;
	int id = fork();
	if (id == 0)
		printf("Hello from child process (id == %d)\n", id);	
	if (id > 0)
		printf("Hello from parent process (id == %d)\n", id);	
	return (0);
}


//eXAMPLE OF USE OF THE FUNCTION PIPE()
int	main()
{
	int	fd[2];
//pipe fd[] va permettre de faire deux process separes
	if (pipe(fd) == -1)
	{	
		printf("Error with pipe\n");
		return (1);
	}
	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		int x;
		printf("Input a number\n");
		scanf("%d", &x);
		write(fd[1], &x, sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0], &y, sizeof(int));
		close(fd[0]);
		printf("read from child process == %d\n", y);
	}
	return (0);
}
*/
