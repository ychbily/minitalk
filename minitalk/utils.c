/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:53:06 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/05 11:59:24 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_skip(const char *str)
{
	int	i;

	i = 0;
	while ((str[i] != '\0' ) && (str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' '))
		i++;
	return (i);
}

int	atoi_helper(const char *str, int sign, long long n, int i)
{
	long long	nbr;

	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		nbr = n;
		n = n * 10 + str[i] - '0';
		if (nbr != n / 10 && sign == 1)
			return (-1);
		else if (nbr != n / 10 && sign == -1)
			return (0);
		i++;
	}
	return (n * sign);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	n;
	int			sign;

	n = 0;
	sign = 1;
	i = ft_skip(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	return (atoi_helper(str, sign, n, i));
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
