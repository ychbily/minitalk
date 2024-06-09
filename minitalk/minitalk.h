/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:36:25 by ychbily           #+#    #+#             */
/*   Updated: 2024/06/09 18:44:57 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "signal.h"
# include "libc.h"

typedef struct s_data
{
	int					uni_bytes;
	int					uni_byte_counter;
	unsigned char		unicode[4];
	int					byte;
	int					bit;
	int					pid;
}	t_data;

typedef struct sigaction	t_sigaction;

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_skip(const char *str);
int		atoi_helper(const char *str, int sign, long long n, int i);
int		ft_atoi(const char *str);

#endif