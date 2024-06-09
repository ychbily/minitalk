/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:00:07 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/09 18:10:10 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send(char c, pid_t pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			(kill(pid, SIGUSR2) == -1) && (write(1, "/ERROR\n", 7), exit(0), 0);
		else
			(kill(pid, SIGUSR1) == -1) && (write(1, "/ERROR\n", 7), exit(0), 0);
		i--;
		usleep(200);
	}
}

void	ft_helper(int signum)
{
	if (signum == SIGUSR1)
	{
		write(1, "DONE.", 5);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (ac != 3 || ft_atoi(av[1]) <= 1)
		return (write(1, "USAGE error\ntry ./client [PID] [string]\n", 40));
	signal(SIGUSR1, ft_helper);
	pid = ft_atoi(av[1]);
	if (kill(pid, 0))
		return (write(1, "check PID\n", 10));
	while (av[2][i])
		ft_send(av[2][i++], pid);
	ft_send(0, pid);
}
