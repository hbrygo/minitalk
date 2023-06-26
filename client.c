/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:46:20 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/22 15:49:09 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

static void	send_signal(char c, int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		usleep(100);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("Wrong imput\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	if (pid == -1 || pid == 0)
	{
		ft_printf("Wrong PID\n");
		return (0);
	}
	while (argv[2][i])
	{
		send_signal(argv[2][i], pid);
		i++;
	}
	send_signal('\n', pid);
	return (0);
}
