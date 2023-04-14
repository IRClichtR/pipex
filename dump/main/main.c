/*
int	main(int ac, char **av)
{
	if (ac < 2)
		return (0);
	char **str;
	str = ft_calloc(ac, sizeof(char *));
	int i = 0;
	while (av[i + 1] != NULL)
	{
		str[i] = ft_strdup(av[i+1]);
		i++;
	}
	int ptr_count = free_surstr(str);
printf("PTR FREEED == %d\n", ptr_count);
	return (0);
}
*/
