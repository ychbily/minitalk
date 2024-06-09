/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 21:00:20 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/09 18:38:41 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_reset(t_data *data, siginfo_t *info)
{
	(void)info;
	data->bit = 0;
	data->byte = 0;
	data->uni_byte_counter = 0;
	data->uni_bytes = 4;
	while (data->uni_bytes > 0)
		data->unicode[--data->uni_bytes] = 0;
}

static void	ft_unicode(t_data *data)
{
	if (data->uni_bytes == 0)
		data->uni_bytes = (data->byte >= 240) + \
		(data->byte >= 224) + (data->byte >= 192) * 2;
	if (data->uni_bytes && data->uni_byte_counter < data->uni_bytes)
		data->unicode[data->uni_byte_counter++] = data->byte;
	if (data->uni_bytes && data->uni_byte_counter == data->uni_bytes)
	{
		write(1, &data->unicode, data->uni_bytes);
		ft_reset(data, NULL);
	}
}

static void	sig_h(int signum, siginfo_t *info, void *ucontext_t)
{
	static t_data	data;

	ucontext_t = 0;
	if (data.pid != info->si_pid)
	{
		data.pid = info->si_pid;
		ft_reset(&data, NULL);
	}
	data.byte = (data.byte << 1) + (signum == SIGUSR2);
	if (++data.bit == 8)
	{
		(data.byte == 0) && (kill(data.pid, SIGUSR1));
		if (data.byte < 127)
			write(1, &data.byte, 1);
		else
			ft_unicode(&data);
		data.bit = 0;
		data.byte = 0;
	}
}

int	main(void)
{
	t_sigaction	sig;

	sig.sa_sigaction = &sig_h;
	sig.sa_flags = SA_SIGINFO;
	write(1, "PID: ", 6);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd(10, 1);
	while (1)
	{
		if (sigaction(SIGUSR1, &sig, NULL) < 0 \
			|| sigaction(SIGUSR2, &sig, NULL) < 0)
			return (write(1, "/ERR33OR\n", 7));
		usleep(200);
	}
	return (0);
}
