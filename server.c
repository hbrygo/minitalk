/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <hubrygo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:40:50 by hubrygo           #+#    #+#             */
/*   Updated: 2023/06/22 15:52:01 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"
#include "printf/ft_printf.h"

static void	btoa(int signal)
{
	static int	bit;
	static int	c;

	if (SIGUSR1 == signal)
		c |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		if (signal(SIGUSR1, btoa) == SIG_ERR)
			exit(EXIT_FAILURE);
		if (signal(SIGUSR2, btoa) == SIG_ERR)
			exit(EXIT_FAILURE);
		pause();
	}
}
