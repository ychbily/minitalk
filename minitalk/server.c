/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 03:37:28 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/09 18:38:26 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_h(int signum, siginfo_t *info, void *ucontext)
{
	static t_data	data;

	ucontext = 0;
	if (data.pid != info->si_pid)
	{
		data.pid = info->si_pid;
		data.bit = 0;
		data.byte = 0;
	}
	data.byte = (data.byte << 1) + (signum == SIGUSR2);
	if (++data.bit == 8)
	{
		data.bit = 0;
		ft_putchar_fd(data.byte, 1);
		data.byte = 0;
	}
}

int	main(void)
{
	t_sigaction	sig;

	sig.sa_sigaction = &sig_h;
	sig.sa_flags = SA_SIGINFO;
	write(1, "PID :", 5);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd(10, 1);
	while (1)
	{
		if (sigaction(SIGUSR1, &sig, NULL) < 0
			|| sigaction(SIGUSR2, &sig, NULL) < 0)
			return (write(1, "/ERROR\n", 7));
		usleep(200);
	}
	return (0);
}
