#include "minit.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int	ft_isdigit(char *c)
{
	int	i;
	int	thereisi;

	i = 0;
	thereisi = 0;
	while (c[i] != '\0')
	{
		if ((c[i] == '-' || c[i] == '+') && i == 0)
		{
			i++;
			thereisi++;
		}
		else if (c[i] <= 57 && c[i] >= 48)
		{
			i++;
		}
		else
		{
			return (0);
		}
	}
	if (thereisi > 1 || i == thereisi)
		return (0);
	return (1);
}

int	*chartobinary(char c)
{
	int	*tab;
	int	i;

	i = 7;
	tab = malloc(sizeof (int) * 8);
	while (i >= 0)
	{
		tab[7 - i] = (c & (1 << i)) >> i;
		i--;
	}
	return (tab);
}
int	checks(char **argj, int argc)
{
	if (ft_isdigit(argj[1]) == 0)
	{
		ft_putstr_fd("PID is not a digit",1);
		return (0);
	}
	if (argc != 3)
	{
		ft_putstr_fd("ERROR ARGUMETNS", 1);
		return (0);
	}
	return(1);
}

void	acknolegment(int sig)
{
	printf("ll\n");
	write(1, "message recieved thank you\n", 28);
	exit(0);
}

int	sendsignals(int *bit, int i, int pid)
{
	if (bit[i] == 0)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			ft_putstr_fd("PID NOT FOUND", 1);
			return (0);
		}	
	}
	else if (bit[i] == 1)
	{
		if(kill(pid, SIGUSR2) == -1)
		{
			ft_putstr_fd("PID NOT FOUND", 1);
			return (0);
		}	
	}
	return(1);
}
int	main(int argc, char **argv)
{
	int		*bit;
	char	c;
	int		i;
	int		j;
	pid_t	pid;

	
	printf("pid %d\n", getpid());
	signal(SIGUSR1, acknolegment);
	if (checks(argv, argc) == 0)
		return (0);
	pid = atoi(argv[1]);
	j = 0;
	while (1)
	{
		bit = chartobinary(argv[2][j]);
		i = 0;
		while (i < 8)
		{
			if (sendsignals(bit , i, pid) == 0)
				return (0);
			usleep(150);
			i++;
		}
		if (argv[2][j] == 0)
			break ;
		j++;
	}
	pause();
	return (0);
}
