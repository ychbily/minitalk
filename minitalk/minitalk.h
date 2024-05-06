/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychbily <ychbily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 20:36:25 by ychbily           #+#    #+#             */
/*   Updated: 2024/04/07 01:07:18 by ychbily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <stdlib.h>

# include <signal.h>
# include <sys/types.h>
# include "unistd.h"
# include "stdio.h"
# include "libc.h"

typedef struct s_data
{
	int					uni_bytes;
	int					uni_bit_counter;
	unsigned char		unicode[4];
	int				byte;
	int					bit;
	int					pid;
}	t_data;

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	sig_h(int signum, siginfo_t *info, void *ucontext_t);
int		ft_skip(const char *str);
int		atoi_helper(const char *str, int sign, long long n, int i);
int		ft_atoi(const char *str);

#endif